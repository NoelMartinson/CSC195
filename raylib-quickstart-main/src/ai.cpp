#include "AI.h"
#include <limits>

int AI::Evaluate(const Board& board) {
    if (board.CheckWin(Player::AI)) return +10;
    if (board.CheckWin(Player::HUMAN)) return -10;
    return 0;
}

int AI::Minimax(Board& board, int depth, bool isMaximizing) {
    int score = Evaluate(board);

    if (score == 10 || score == -10 || board.IsFull())
        return score;

    if (isMaximizing) {
        int best = std::numeric_limits<int>::min();
        for (int y = 0; y < 3; ++y) {
            for (int x = 0; x < 3; ++x) {
                if (board.GetCell(x, y) == Player::NONE) {
                    board.PlaceMove(x, y, Player::AI);
                    best = std::max(best, Minimax(board, depth + 1, false));
                    board.PlaceMove(x, y, Player::NONE); // undo
                }
            }
        }
        return best;
    }
    else {
        int best = std::numeric_limits<int>::max();
        for (int y = 0; y < 3; ++y) {
            for (int x = 0; x < 3; ++x) {
                if (board.GetCell(x, y) == Player::NONE) {
                    board.PlaceMove(x, y, Player::HUMAN);
                    best = std::min(best, Minimax(board, depth + 1, true));
                    board.PlaceMove(x, y, Player::NONE); // undo
                }
            }
        }
        return best;
    }
}

std::pair<int, int> AI::GetBestMove(Board& board) {
    int bestVal = std::numeric_limits<int>::min();
    std::pair<int, int> bestMove = { -1, -1 };

    for (int y = 0; y < 3; ++y) {
        for (int x = 0; x < 3; ++x) {
            if (board.GetCell(x, y) == Player::NONE) {
                board.PlaceMove(x, y, Player::AI);
                int moveVal = Minimax(board, 0, false);
                board.PlaceMove(x, y, Player::NONE); // undo

                if (moveVal > bestVal) {
                    bestMove = { x, y };
                    bestVal = moveVal;
                }
            }
        }
    }

    return bestMove;
}

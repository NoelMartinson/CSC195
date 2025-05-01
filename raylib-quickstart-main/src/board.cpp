#include "Board.h"

Board::Board() { Reset(); }

void Board::Reset() {
    for (int y = 0; y < 3; y++)
        for (int x = 0; x < 3; x++)
            cells[y][x] = Player::NONE;
}

bool Board::PlaceMove(int x, int y, Player player) {
    if (cells[y][x] == Player::NONE) {
        cells[y][x] = player;
        return true;
    }
    return false;
}

bool Board::IsFull() const {
    for (int y = 0; y < 3; y++)
        for (int x = 0; x < 3; x++)
            if (cells[y][x] == Player::NONE)
                return false;
    return true;
}

bool Board::CheckWin(Player player) const {
    for (int i = 0; i < 3; i++) {
        if ((cells[i][0] == player && cells[i][1] == player && cells[i][2] == player) ||
            (cells[0][i] == player && cells[1][i] == player && cells[2][i] == player))
            return true;
    }
    if ((cells[0][0] == player && cells[1][1] == player && cells[2][2] == player) ||
        (cells[0][2] == player && cells[1][1] == player && cells[2][0] == player))
        return true;

    return false;
}

Player Board::GetCell(int x, int y) const {
    return cells[y][x];
}

void Board::Draw() const {
    int cellSize = 200;
    for (int i = 1; i < 3; i++) {
        DrawLine(i * cellSize, 0, i * cellSize, 600, DARKGRAY);
        DrawLine(0, i * cellSize, 600, i * cellSize, DARKGRAY);
    }

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            int cx = x * cellSize + cellSize / 2;
            int cy = y * cellSize + cellSize / 2;
            if (cells[y][x] == Player::HUMAN_X) {
                DrawLine(cx - 40, cy - 40, cx + 40, cy + 40, RED);
                DrawLine(cx + 40, cy - 40, cx - 40, cy + 40, RED);
            }
            else if (cells[y][x] == Player::HUMAN_O) {
                DrawCircleLines(cx, cy, 40, BLUE);
            }
        }
    }
}

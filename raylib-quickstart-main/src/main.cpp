#include "raylib.h"
#include "board.h"
#include "player.h"

int main() {
    const int screenWidth = 600;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Tic Tac Toe - Player vs Player");
    SetTargetFPS(60);

    Board board;
    Player currentPlayer = Player::HUMAN_X;
    Player winner = Player::NONE;
    bool gameOver = false;

    while (!WindowShouldClose()) {
        if (!gameOver && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mouse = GetMousePosition();
            int x = mouse.x / 200;
            int y = mouse.y / 200;

            if (board.PlaceMove(x, y, currentPlayer)) {
                if (board.CheckWin(currentPlayer)) {
                    winner = currentPlayer;
                    gameOver = true;
                }
                else if (board.IsFull()) {
                    gameOver = true;
                }
                else {
                    currentPlayer = (currentPlayer == Player::HUMAN_X) ? Player::HUMAN_O : Player::HUMAN_X;
                }
            }
        }

        if (IsKeyPressed(KEY_R)) {
            board.Reset();
            currentPlayer = Player::HUMAN_X;
            winner = Player::NONE;
            gameOver = false;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        board.Draw();

        if (gameOver) {
            const char* msg = (winner == Player::HUMAN_X) ? "Player X Wins!" :
                (winner == Player::HUMAN_O) ? "Player O Wins!" : "Draw!";
            DrawText(msg, screenWidth / 2 - MeasureText(msg, 40) / 2, 20, 40, DARKGREEN);
            DrawText("Press R to Restart", screenWidth / 2 - 100, screenHeight - 40, 20, GRAY);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

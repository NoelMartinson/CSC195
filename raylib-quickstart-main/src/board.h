#pragma once
#include "raylib.h"
#include "player.h"

class Board {
public:
    Board();
    void Reset();
    bool PlaceMove(int x, int y, Player player);
    bool IsFull() const;
    bool CheckWin(Player player) const;
    Player GetCell(int x, int y) const;
    void Draw() const;

private:
    Player cells[3][3];
};

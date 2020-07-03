#include "pacman.h"
#include <cmath>
#include <iostream>

void Pacman::Update() {
    SDL_Point prev_cell{
        static_cast<int>(head_x),
        static_cast<int>(
            head_y) };  // We first capture the head's cell before updating.
    UpdateHead();
    SDL_Point current_cell{
        static_cast<int>(head_x),
        static_cast<int>(head_y) };  // Capture the head's cell after updating.
}

void Pacman::UpdateHead() {
    switch (direction) {
    case Direction::kUp:
        head_y -= speed;
        break;

    case Direction::kDown:
        head_y += speed;
        break;

    case Direction::kLeft:
        head_x -= speed;
        break;

    case Direction::kRight:
        head_x += speed;
        break;
    }

    // Wrap the Snake around to the beginning if going off of the screen.
    head_x = fmod(head_x + grid_width, grid_width);
    head_y = fmod(head_y + grid_height, grid_height);
}

// Inefficient method to check if cell is occupied by snake.
bool Pacman::PacmanCell(int x, int y) {
    if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
        return true;
    }
    return false;
}

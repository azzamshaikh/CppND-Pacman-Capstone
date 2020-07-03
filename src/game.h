#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "pacman.h"

class Game {
public:
    Game(std::size_t grid_width, std::size_t grid_height);
    void Run(Controller const& controller, Renderer& renderer,
        std::size_t target_frame_duration);
    int GetScore() const;
    int GetSize() const;

private:
    Pacman pacman;
    SDL_Point food;
    std::vector<SDL_Point> foods;


    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> random_w;
    std::uniform_int_distribution<int> random_h;

    int score{ 0 };

    void CreateFood();
    void Eat();
    void PlaceFood();
    void Update();
    void Replay();
    bool ans;


};

#endif
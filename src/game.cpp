#include "game.h"
#include <iostream>
#include <string>
#include <cstring>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : pacman(grid_width, grid_height),
    engine(dev()),
    random_w(0, static_cast<int>(grid_width - 1)),
    random_h(0, static_cast<int>(grid_height - 1)) {
    CreateFood();
}

void Game::Run(Controller const& controller, Renderer& renderer,
    std::size_t target_frame_duration) {
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    int frame_count = 0;
    bool running = true;

    while (running) {
        frame_start = SDL_GetTicks();

        // Input, Update, Render - the main game loop.
        controller.HandleInput(running, pacman);
        Update();
        renderer.Render(pacman, foods);
        if (foods.empty() == true) {
            Replay();
            if (ans == true) {
                CreateFood();
            }
            else if (ans == false)
                break;
        }

        frame_end = SDL_GetTicks();

        // Keep track of how long each loop through the input/update/render cycle
        // takes.
        frame_count++;
        frame_duration = frame_end - frame_start;

        // After every second, update the window title.
        if (frame_end - title_timestamp >= 1000) {
            renderer.UpdateWindowTitle(score, frame_count);
            frame_count = 0;
            title_timestamp = frame_end;
        }

        // If the time for this frame is too small (i.e. frame_duration is
        // smaller than the target ms_per_frame), delay the loop to
        // achieve the correct frame rate.
        if (frame_duration < target_frame_duration) {
            SDL_Delay(target_frame_duration - frame_duration);
        }
    }
}

void Game::PlaceFood() {
    int x, y;
    while (true) {
        x = random_w(engine);
        y = random_h(engine);
        // Check that the location is not occupied by a snake item before placing
        // food.
        if (!pacman.PacmanCell(x, y)) {
            food.x = x;
            food.y = y;
            return;
        }
    }
}

void Game::CreateFood() {
    int x, y;
    //create 10 food objects
    for (int i = 0; i < 15; i++) {
        x = random_w(engine);
        y = random_h(engine);
        //check if the location is not occupied by a snake item 
        if (!pacman.PacmanCell(x, y)) {
            food.x = x;
            food.y = y;
        }
        foods.push_back(food);
    }
}

void Game::Update() {
    if (!pacman.alive) return;

    pacman.Update();

    int new_x = static_cast<int>(pacman.head_x);
    int new_y = static_cast<int>(pacman.head_y);

    // Check if there's food over here
    for (int i = 0; i < foods.size(); i++) {
        if (foods[i].x == new_x && foods[i].y == new_y) {
            foods.erase(foods.begin() + i);
            score++;
        }
    }
}

void Game::Replay() {
    std::cout << "Congratulations! You won!! Would you like to play again? If so, enter 'yes'! If not, enter 'no' or anything else! Answer: ";
    std::string response;
    std::cin >> response;
    std::string WantsToPlay = "yes";
    std::string Close = "no";

    if (response == WantsToPlay) {
        ans = true;
    }
    else if (response == Close) {
        ans = false;
    }
    else
    {
        ans = false;
    }

}

int Game::GetScore() const { return score; }
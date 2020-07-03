#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "startup.h"

int main() {
    constexpr std::size_t kFramesPerSecond{ 60 };
    constexpr std::size_t kMsPerFrame{ 1000 / kFramesPerSecond };
    constexpr std::size_t kScreenWidth{ 640 };
    constexpr std::size_t kScreenHeight{ 640 };
    constexpr std::size_t kGridWidth{ 32 };
    constexpr std::size_t kGridHeight{ 32 };

    bool startgame;

    while (true) {
        while (startgame == false) {
            Startup start;
            startgame = start.bootscreen();
            if (start.getQuitGame() == true) {
                return 0;
            }
        }
        Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
        Controller controller;
        Game game(kGridWidth, kGridHeight);
        game.Run(controller, renderer, kMsPerFrame);
        std::cout << "Game has terminated successfully!";
        std::cout << " Your final score was: " << game.GetScore() << "\n";
        return 0;
    }
}
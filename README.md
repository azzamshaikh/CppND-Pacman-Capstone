# CPPND: Capstone Pacman Game 

This is my capstone project for the Udacity C++ Nanodegree Program. The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses. I used the code and adjusted it to create a simple Pacman style game.

<img src="snake_game.gif"/>

The Capstone Project is a primitive version of the classic game Pacman. While this game does not have anyone to run from, it does have a vital feature from the original game: food. When this game begins, it will randomly place 15 snacks across the window and the players objective is to eat them all! Once all snacks have been devoured, the game will end and you can choose to play again or quit the game. 

In accordance with the capstone rubric, the following critera was satisifed within my project:
* Loops, Functions, I/O:
  * The project demonstrates an understanding of C++ functions and control structures
    -> My project features a variety of control structures such as [for loops](https://github.com/azzamshaikh/CppND-Pacman-Capstone/blob/94d03aeb44f1c3b812b600f8a4e7a9f56af2561f/src/game.cpp#L81), [switch cases](https://github.com/azzamshaikh/CppND-Pacman-Capstone/blob/94d03aeb44f1c3b812b600f8a4e7a9f56af2561f/src/startup.cpp#L23), and [if/else statements](https://github.com/azzamshaikh/CppND-Pacman-Capstone/blob/94d03aeb44f1c3b812b600f8a4e7a9f56af2561f/src/game.cpp#L117). In addition, the project code is organized into functions such as [Game::CreateFood()](https://github.com/azzamshaikh/CppND-Pacman-Capstone/blob/94d03aeb44f1c3b812b600f8a4e7a9f56af2561f/src/game.cpp#L78) and [Game::Replay()](https://github.com/azzamshaikh/CppND-Pacman-Capstone/blob/94d03aeb44f1c3b812b600f8a4e7a9f56af2561f/src/game.cpp#L110).
  * The project accepts user input and processes the input
    -> Upon start up, the game asks the user [what they want to do](https://github.com/azzamshaikh/CppND-Pacman-Capstone/blob/94d03aeb44f1c3b812b600f8a4e7a9f56af2561f/src/startup.cpp#L17) and the game processes the input. In addition, after completing the game, the user is asked if they want to [play again](https://github.com/azzamshaikh/CppND-Pacman-Capstone/blob/94d03aeb44f1c3b812b600f8a4e7a9f56af2561f/src/game.cpp#L110).
* Object Oriented Programming 
  * The project uses OOP techniques
    -> The game contains multiple classes to complete different functionality like controlling and rendering. I created a class that was responsible for the [boot options](https://github.com/azzamshaikh/CppND-Pacman-Capstone/blob/master/src/startup.cpp) that is started upon game launch.
  * Classes use appropriate access specifiers for class members
    -> Each class contains appropriate access specifiers for class members.
  * Classes abstract implementation details from their interfaces
    -> All class member functions have documented effects via name and comments.
    
The prebuilt SnakeGame also featured a variety of memory management techniques regarding use of references that were kept in my version.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./PacmanGame`.

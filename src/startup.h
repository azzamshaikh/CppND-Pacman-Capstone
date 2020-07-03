#include <iostream>
#include <vector>

using std::vector;

class Startup {
public:
    Startup() {
        quitgame = false; 
    }
    bool bootscreen(); // load a bootscreen at the start of the game
    void setQuitGame() { quitgame = true; } // set the quitgame variable to true
    bool getQuitGame() { return quitgame; } // return the quitgame variable
private:
    bool static quitgame;


};

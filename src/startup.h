#include <iostream>
#include <vector>

using std::vector;

class Startup {
public:
    Startup() {
        quitgame = false;
    }
    bool bootscreen();
    void setQuitGame() { quitgame = true; }
    bool getQuitGame() { return quitgame; }
private:
    bool static quitgame;


};
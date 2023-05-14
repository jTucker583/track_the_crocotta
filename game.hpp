#include <iostream>
#include <string>
#define ROWS 5
#define COLS 5

class track_the_crocotta
{
    struct position
    {
        bool is_pit;
        bool contains_crocotta;
    };
    struct player
    {
        int arrows = 2;
        position pos[ROWS][COLS];
        int hasFallenIntoPit(int x, int y)
        {
            return pos[x][y].is_pit;
        }
    };

private:
    position position[ROWS][COLS];
    bool killed_crocotta;

public:
    // constructor
    track_the_crocotta();
    // game mechanics
    int move(char a);
    int shoot(char a); // character for choosind direction to shoot
    void moveCrocotta();
    void displayMenu();
    void runGameOver();
    // getters
    std::pair<int, int> getPosition();
    bool isPit(int x, int y);
    bool containsCrocotta(int x, int y);
    bool isCrocottaDead();
    // setters
    void killCrocotta();
    void subtractArrow();
};
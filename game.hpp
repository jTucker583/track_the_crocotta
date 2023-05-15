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
        bool is_visited;
    };
    struct player
    {
        int arrows = 2;
        std::pair<int, int> playerpos;
    };

private:
    position posi[ROWS][COLS];
    bool killed_crocotta;
    player p1;
    std::pair<int, int> crocotta_pos;

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
    std::pair<int, int> getCrocottaPosition();
    // setters
    void killCrocotta();
    void subtractArrow();
    void setCrocottaPos(int x, int y);
};
#include <iostream>
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
    std::pair<int, int> pits[3];
    int score = 0;

public:
    // constructor
    track_the_crocotta();
    // game mechanics
    int move(char a);
    int shoot(char a); // character for choosind direction to shoot
    void moveCrocotta();
    void displayGridAndMenu();
    void runGameOver();
    // getters
    int getArrows();
    std::pair<int, int> getPosition();
    bool isPit(int x, int y);
    bool containsCrocotta(int x, int y);
    bool isCrocottaDead();
    std::pair<int, int> getCrocottaPosition();
    std::pair<int, int> *getPitLocations();
    // setters
    void killCrocotta();
    void subtractArrow();
    void setCrocottaPos(int x, int y);
};
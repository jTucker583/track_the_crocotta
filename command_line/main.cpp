#include <iostream>
#include "game.hpp"
using namespace std;

void debug(track_the_crocotta game)
{
    cout << "Player position: (" << game.getPosition().first << ", " << game.getPosition().second << ")" << endl;
    cout << "Crocotta position: (" << game.getCrocottaPosition().first << ", " << game.getCrocottaPosition().second << ")" << endl;
    cout << "pit locations:" << endl;
    cout << "   1. (" << game.getPitLocations()[0].first << ", " << game.getPitLocations()[0].second << ")" << endl;
    cout << "   2. (" << game.getPitLocations()[1].first << ", " << game.getPitLocations()[1].second << ")" << endl;
    cout << "   3. (" << game.getPitLocations()[2].first << ", " << game.getPitLocations()[2].second << ")" << endl;

    for (int i = 0; i < ROWS + 2; i++)
        cout << "-";
    cout << endl;
    for (int i = 0; i < ROWS; i++)
    {
        cout << "|";
        for (int j = 0; j < COLS; j++)
        {
            if (game.isPit(i, j))
                cout << "X";
            else if (game.containsCrocotta(i, j))
                cout << "Z";
            else
                cout << "0";
        }
        cout << "|" << endl;
    }
    for (int i = 0; i < ROWS + 2; i++)
        cout << "-";
    cout << endl;
}

int main()
{

    char key;
    track_the_crocotta game = track_the_crocotta();
    while (true)
    {
        std::cout << std::endl;
        // debug(game);
        game.displayGridAndMenu();
        cout << "key: ";
        cin >> key;
        switch (key)
        {
        case 'w':
            if (game.move(key) == 0)
                cout << "Can't move outside the barrier!" << endl;
            break;
        case 'a':
            if (game.move(key) == 0)
                cout << "Can't move outside the barrier!" << endl;
            break;
        case 's':
            if (game.move(key) == 0)
                cout << "Can't move outside the barrier!" << endl;
            break;
        case 'd':
            if (game.move(key) == 0)
                cout << "Can't move outside the barrier!" << endl;
            break;
        case 'j':
            if (game.shoot(key) == 0)
                cout << "Can't shoot outside the barrier!" << endl;
            break;
        case 'k':
            if (game.shoot(key) == 0)
                cout << "Can't shoot outside the barrier!" << endl;
            break;
        case 'l':
            if (game.shoot(key) == 0)
                cout << "Can't shoot outside the barrier!" << endl;
            break;
        case 'i':
            if (game.shoot(key) == 0)
                cout << "Can't shoot outside the barrier!" << endl;
            break;
        case 'Q':
            return 0;
        default:
            cout << "Invalid input." << endl;
            break;
        }
        // check if player has hit a pit or the crocotta after moving
        int tempx = game.getPosition().first;
        int tempy = game.getPosition().second;
        if (game.isPit(tempx, tempy) || game.containsCrocotta(tempx, tempy))
        {
            game.runGameOver();
            return 0;
        }
        // check if the crocotta is dead
        if (game.isCrocottaDead())
        {
            game.runGameOver();
            return 0;
        }
        // check if the player has any arrows left
        if (game.getArrows() == 0)
        {
            game.runGameOver();
            return 0;
        }
    }
}

// opengl tutorial stuff - https://satviksrivastava.hashnode.dev/opengl-in-vs-code-setup

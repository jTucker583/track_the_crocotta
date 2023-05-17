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
    debug(game);
    // while (key != 'q')
    // {
    //     key = getchar();
    //     fflush(stdin);
    //     cout << key << endl;
    // }

    return 0;
}

// opengl tutorial stuff - https://satviksrivastava.hashnode.dev/opengl-in-vs-code-setup
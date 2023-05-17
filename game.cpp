#include <iostream>
#include <ctime>
#include "game.hpp"

track_the_crocotta::track_the_crocotta()
{
    std::pair<int, int> location_of_interest;
    int counter = 0;

    srand(time(0));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            posi[i][j].is_pit = false;
            posi[i][j].contains_crocotta = false;
            posi[i][j].is_visited = false;
        }
    }
    // generate crocotta location
    location_of_interest.first = rand() % ROWS;
    location_of_interest.second = rand() % COLS;
    posi[location_of_interest.first][location_of_interest.second].contains_crocotta = true;
    crocotta_pos = location_of_interest;
    // generate pit locations where the crocotta is not
    do
    {
        location_of_interest.first = rand() % ROWS;
        location_of_interest.second = rand() % COLS;
        if (posi[location_of_interest.first][location_of_interest.second].contains_crocotta)
            continue;
        else
        {
            posi[location_of_interest.first][location_of_interest.second].is_pit = true;
            pits[counter] = location_of_interest;
            counter++;
        }
    } while (counter < 3);
    // generate starting player location where there are no pits and no crocotta
    do
    {
        location_of_interest.first = rand() % ROWS;
        location_of_interest.second = rand() % COLS;
        if (!posi[location_of_interest.first][location_of_interest.second].contains_crocotta &&
            !posi[location_of_interest.first][location_of_interest.second].is_pit)
        {
            p1.playerpos.first = location_of_interest.first;
            p1.playerpos.second = location_of_interest.second;
            break;
        }
    } while (true);
}

// getter methods

std::pair<int, int> track_the_crocotta::getPosition()
{
    return p1.playerpos;
}

std::pair<int, int> track_the_crocotta::getCrocottaPosition()
{
    return crocotta_pos;
}

bool track_the_crocotta::isPit(int x, int y)
{
    return (posi[x][y].is_pit);
}

bool track_the_crocotta::containsCrocotta(int x, int y)
{
    return (posi[x][y].contains_crocotta);
}

std::pair<int, int> *track_the_crocotta::getPitLocations()
{
    return pits;
}

bool track_the_crocotta::isCrocottaDead() { return killed_crocotta; }

// setter methods

void track_the_crocotta::killCrocotta() { killed_crocotta = true; }

void track_the_crocotta::subtractArrow()
{
    if (p1.arrows > 0)
        p1.arrows -= 1;
}

void track_the_crocotta::setCrocottaPos(int x, int y)
{
    crocotta_pos.first = x;
    crocotta_pos.second = y;
}

// game mechanics
int track_the_crocotta::move(char a)
{
    switch (a)
    {
    case 'a': // move left
        if (p1.playerpos.first > 0)
        {
            p1.playerpos.first -= 1;
            return 1;
        }
        return 0;
    case 's': // move down
        if (p1.playerpos.second < COLS)
        {
            p1.playerpos.second += 1;
            return 1;
        }
        return 0;
    case 'd': // move right
        if (p1.playerpos.first < ROWS)
        {
            p1.playerpos.first += 1;
            return 1;
        }
        return 0;
    case 'w': // move up
        if (p1.playerpos.second > 0)
        {
            p1.playerpos.second -= 1;
            return 1;
        }
        return 0;
    default: // invalid key; should not return here if keychecks in main done correctly
        return -1;
    }
}

int track_the_crocotta::shoot(char a)
{
    switch (a)
    {
    case 'j': // shoot left
        if (p1.playerpos.first > 0)
        {
            if (posi[p1.playerpos.first - 1][p1.playerpos.second].contains_crocotta)
                killCrocotta();
            return 1;
        }
        return 0;
    case 'k': // shoot down
        if (p1.playerpos.second < COLS)
        {
            if (posi[p1.playerpos.first][p1.playerpos.second + 1].contains_crocotta)
                killCrocotta();
            return 1;
        }
        return 0;
    case 'l': // shoot right
        if (p1.playerpos.first < ROWS)
        {
            if (posi[p1.playerpos.first + 1][p1.playerpos.second].contains_crocotta)
                killCrocotta();
            return 1;
        }
        return 0;
    case 'i': // shoot up
        if (p1.playerpos.second > 0)
        {
            if (posi[p1.playerpos.first][p1.playerpos.second - 1].contains_crocotta)
                killCrocotta();
            return 1;
        }
        return 0;
    default: // invalid key; should not return here if keychecks in main done correctly
        return -1;
    }
}

void track_the_crocotta::moveCrocotta()
{
    // similar to the constructor, find a random spot where the player is not and there is not a pit.
    int randx, randy;
    do
    {
        randx = rand() % ROWS;
        randy = rand() % COLS;
        if (!(posi[randx][randy].is_pit && p1.playerpos.first == randx && p1.playerpos.second == randy))
            break;
    } while (true);
    std::pair<int, int> temp = getCrocottaPosition();
    posi[temp.first][temp.second].contains_crocotta = false;
    setCrocottaPos(randx, randy);
    posi[randx][randy].contains_crocotta = true;
}
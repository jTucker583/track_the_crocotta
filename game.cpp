#include <iostream>
#include <string>
#include <ctime>
#include "game.hpp"

track_the_crocotta::track_the_crocotta()
{
    std::pair<int, int> location_of_interest;
    int counter = 0;

    srand(0);
    for (auto pos : posi)
    {
        pos->contains_crocotta = false;
        pos->is_pit = false;
    }
    // generate crocotta location
    location_of_interest.first = rand() % ROWS;
    location_of_interest.second = rand() % COLS;
    posi[location_of_interest.first][location_of_interest.second].contains_crocotta = true;
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
        }
    } while (true);
}

// getter methods

std::pair<int, int> track_the_crocotta::getPosition()
{
}
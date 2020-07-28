/**
 * @author Wilmot Osei-Bonsu
 */

#include "Game.h"


Game::Game(int day, Team* team1, Team* team2, int score1, int score2) {
    this->day = day;
    this->teams.push_back(team1);
    this->teams.push_back(team2);
    this->score1 = score1;
    this->score2 = score2;
}

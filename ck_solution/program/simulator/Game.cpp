/**
 * @author Wilmot Osei-Bonsu
 */

#include "Game.h"
#include <vector>

Game::Game(int day, Team* team1, Team* team2, int score1, int score2) {
    this->day = day;
    this->teams.push_back(team1);
    this->teams.push_back(team2);
    this->score1 = score1;
    this->score2 = score2;
}

int Game::getDay()
{
	return this->day;
}

std::vector<Team*> Game::getTeams()
{
	return this->teams;
}

int Game::getScore1()
{
	return this->score1;
}

int Game::getScore2()
{
	return this->score2;
}

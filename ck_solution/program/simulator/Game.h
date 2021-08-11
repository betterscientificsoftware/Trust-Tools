#pragma once
//
// Created by wilmo on 10/3/2019.
//

#ifndef MARCH_MADNESS_SIMULATOR_GAME_H
#define MARCH_MADNESS_SIMULATOR_GAME_H

#include <string>
#include <vector>
#include "Team.h"

class Team;
class Game {

public:

    /**
     * Constructor for game class.
     * @param day Number of days since 1-1-0000.
     * @param team1 First team in the game.
     * @param team2 Second team in the game.
     * @param score1 Score of first team.
     * @param score2 Score of second team.
     */
    Game(int day, Team* team1, Team* team2, int score1, int score2);

    /**
     * Returns days since 1-1-0000.
     * @return Int representing days since 1-1-0000.
     */
    int getDay();

    /**
     * Returns collection holing both teams playing.
     * @return Collection holding teams playing in game.
     */
    std::vector<Team*> getTeams();

    /**
     * Returns int representing location of game. 1=home, -1=away, 0=neutral.
     * @return 1=home, -1=away, 0=neutral.
     */
    int getScore1();

    int getScore2();


private:
    /**
     * Number of days since 1-1-0000.
     */
    int day;

    /**
     * Collection holing both teams playing.
     */
    std::vector<Team*> teams;

    /**
     * Int representing location of game. 1=home, -1=away, 0=neutral.
     */
    int location;

    int score1;

    int score2;
};
#endif //MARCH_MADNESS_SIMULATOR_GAME_H

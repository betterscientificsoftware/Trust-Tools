/**
 * @author Wilmot Osei-Bonsu
 */

#ifndef MARCH_MADNESS_SIMULATOR_TEAM_H
#define MARCH_MADNESS_SIMULATOR_TEAM_H

#include <string>
#include <vector>
#include "Game.h"

using namespace std;

class Game;

class Team{

public:

    /**
     * @brief Constructor for team object.
     * @param name Team name.
     * @param id Team identification number.
     */
    Team(string name, int id);

    /**
     * Adds new game to the team's collection of games. Returns if the game collection is altered.
     * @param newGame New game to be added to the game collection.
     * @return True if game collection is changed.
     */
    void addGame(Game* newGame);

    /**
     * Returns copy of collection holding all games for the team.
     * @return All games played by team.
     */
    vector<struct Game *> getAllGames();

    /**
     * Returns team name;
     * @return Team name.
     */
    string getName();

    /**
     * Returns team identification number.
     * @return team id.
     */
    int getId();

    int getNumGamesPlayed();

    void addRank(double rank);

    string toString();

    double getRank() const;

private:

    /**
     * Collection holding all games played by this team.
     */
    vector<Game*> gameCollection;

    /**
    * Team name
    */
    string name;

    /**
     * Identification number for team.
     */
    int id;

    double rank;
};

bool operator<(const Team &team1, const Team &team2);
#endif //MARCH_MADNESS_SIMULATOR_TEAM_H

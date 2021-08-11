/**
 * @author Wilmot Osei-Bonsu
 */

#include "Team.h"

Team::Team(std::string name, int id) {
    this->id = id;
    this->name = name;
}

void Team::addGame(Game* newGame) {
    this->gameCollection.push_back(newGame);
}

std::vector<Game*> Team::getAllGames() {
    return this->gameCollection;
}

int Team::getId() {
    return this->id;
}

std::string Team::getName() {
    return this->name;
}

int Team::getNumGamesPlayed() {
    return this->Team::gameCollection.size();
}

std::string Team::toString() {
    return name;
}

void Team::addRank(double rank) {
    this->rank = rank;
}

double Team::getRank() const {
    return this->rank;
}

bool operator<(const Team& team1, const Team& team2) {
    return team1.getRank() < team2.getRank();
}


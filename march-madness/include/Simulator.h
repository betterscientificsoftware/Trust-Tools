//
// Created by wilmot on 10/6/2019.
//

#ifndef MARCH_MADNESS_SIMULATOR_SIMULATOR_H
#define MARCH_MADNESS_SIMULATOR_SIMULATOR_H
#include <string>
#include <vector>
#include <map>
#include "eigen/Eigen/Core"
#include "eigen/Eigen/Dense"

class Team;
class Game;

/**
 * Method responsible for converting team text file into team objests
 * @param teamData
 */
void createTeams(std::string teamData);

void loadGames(std::string gameData, int flag, bool apply_scaling);

void run(int flag, bool apply_scaling);

void populateMatrix(int team_1_Id, int team_2_Id, int team_1_score, int team_2_score, bool apply_scaling);

void constructCorrectVector(std::string filename);

void printVector(std::vector<int> vect);

void printVector(std::vector<Team> vect);

void constructAxes();

double computeSSE(std::vector<int> vect1, std::vector<Team> vect2);

void createLabels();

std::vector<std::string> getLabels();

double sse();

double mse();

double se();

std::vector<int> get_x_axis();

std::vector<int> get_y_axis();

std::map<int, Team*> getTeamMap();

int getNumTeams();

int getNumGamesPlayed();

Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> getGameMatrix();


#endif //MARCH_MADNESS_SIMULATOR_SIMULATOR_H

//
// Created by wilmo on 10/6/2019.
//

#ifndef MARCH_MADNESS_SIMULATOR_SIMULATOR_H
#define MARCH_MADNESS_SIMULATOR_SIMULATOR_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "./eigen/Eigen/Core"
#include "./eigen/Eigen/Dense"
#include "Team.h"
#include <bits/stdc++.h>
#include <iterator>
#include <algorithm>

class Team;
class Game;
using namespace std;
using namespace Eigen;

/**
 * Collection holding all teams.
 */
vector<Team*> teamCollection;
vector<Team> resultVector;
vector<Team*> cleanedResultVector;
map<int, Team*> teamMap;
Matrix<double, Dynamic, Dynamic> gameMatrix;
VectorXd scores;
VectorXd solutionVector;
int numGamesPlayed;
int numTeams;

/**
 * Method responsible for converting team text file into team objests
 * @param teamData
 */
void createTeams(string teamData);

void loadGames(string gameData);

void checkCorrectness(string correctData);

void bin(vector<Team*> *teamVector, vector<vector<int>> *resultVector);

double comparison(vector<vector<int>> *v1, vector<vector<int>> *v2);
#endif //MARCH_MADNESS_SIMULATOR_SIMULATOR_H

#include "Simulator.h"

void populateMatrix(int team1Index, int team2Index, int score1Int, int score2Int);

int main() {
    //createTeams(string("./Data/NCAA Mens BasketBall 2019/TestSetTeams.txt"));
    //loadGames(string("./Data/NCAA Mens BasketBall 2019/TestSetGames.txt"));
    createTeams(string("./Data/NCAA Mens BasketBall 2019/NCAABasketballTeams.txt"));
    loadGames(string("./Data/NCAA Mens BasketBall 2019/NCAABasketballGames.txt"));

    solutionVector = gameMatrix.lu().solve(scores);



    map<int, Team*>::iterator itr;
    for(itr = teamMap.begin(); itr != teamMap.end(); ++itr){
        itr->second->addRank(solutionVector.row(itr->second->getId() -1).value());
        resultVector.push_back(*(itr->second));
    }

    //sort Teams by rank

    sort(resultVector.begin(), resultVector.end());
    vector<Team>::iterator itr2;
    for(itr2 = resultVector.end() - 1; itr2 != resultVector.begin() - 1 ; --itr2){
        //cout << itr2->getName() << endl;
    }
    checkCorrectness("./Data/NCAA Mens BasketBall 2019/Correct.txt");
}

void createTeams(string teamData) {
    string id, name;
    ifstream teams (teamData);
    if(teams.is_open()){
        while (getline(teams, id, ',')){
            getline(teams, name, '\n');
            int idNum = stoi(id);
            remove(name.begin(), name.end(),' ');
            Team* tempTeam = new Team(name, idNum);
            teamCollection.push_back(tempTeam);
            teamMap.insert(pair<int, Team*>(idNum, tempTeam));
            numTeams++;
        }
        teams.close();
    }
    else cout << "Unable to open file";
}

void loadGames(string gameData){
    gameMatrix = Matrix<double, Dynamic, Dynamic>::Zero(numTeams , numTeams);
    scores = VectorXd::Zero(numTeams);

    string days, date, team1, field1, score1, team2, field2, score2;
    fstream games(gameData);
    if(games.is_open()){
        while(getline(games, days, ',')){
            getline(games, date, ',');
            getline(games, team1, ',');
            getline(games, field1, ',');
            getline(games, score1, ',');
            getline(games, team2, ',');
            getline(games, field2, ',');
            getline(games, score2, ' ');
            getline(games, score2, ' ');

            int daysInt = stoi(days);
            int team1Index = stoi(team1);
            int team2Index = stoi(team2);
            int score1Int = stoi(score1);
            int score2Int = stoi(score2);
            Game tempGame(daysInt, teamMap.at(team1Index), teamMap.at(team2Index), score1Int, score2Int);
            teamMap.at(team1Index)->addGame(&tempGame);
            teamMap.at(team2Index)->addGame(&tempGame);
            //gameCollection.push_back(&tempGame);
            numGamesPlayed++;


            populateMatrix(team1Index, team2Index, score1Int, score2Int);
            for(int i = 0; i < numTeams; i++){
                gameMatrix.row(numTeams - 1).col(i) << 1;
            }
            scores.row(numTeams - 1) << 0;
        }
    }
    else cout << "Unable to open file";
}

void populateMatrix(int team1Index, int team2Index, int score1Int, int score2Int) {
    gameMatrix.row(team1Index - 1 ).col(team2Index - 1) << -1;
    gameMatrix.row(team2Index -1 ).col(team1Index -1) <<  -1;
    gameMatrix.row(team1Index -1 ).col(team1Index -1) <<  teamMap.at(team1Index)->getNumGamesPlayed();
    gameMatrix.row(team2Index -1 ).col(team2Index -1) <<  teamMap.at(team2Index)->getNumGamesPlayed();
    if(score1Int > score2Int){
        int temp = scores.row(team1Index - 1).value();
        scores.row(team1Index - 1 ) << temp + (score1Int - score2Int);
        temp = scores.row(team2Index - 1).value();
        scores.row(team2Index - 1 ) << temp + (score2Int - score1Int);
    }
    else{
        int temp = scores.row(team2Index - 1).value();
        scores.row(team2Index - 1 ) << temp + (score1Int - score2Int);
        temp = scores.row(team1Index - 1).value();
        scores.row(team1Index - 1 ) << temp + (score2Int - score1Int);
    }
}

void checkCorrectness(string correctData){
    /**
     * True team rankings binned by level in madness competition.
     */
    vector<vector<int>> actualLevels;
    /**
     * Computed team rankings binned by level in madness competition.
     */
    vector<vector<int>> computedLevels;
    /**
     * Set contains teams that played in March Madness Competition.
     */
    unordered_set<int> teamsInCompetition;
    /**
     * True team ranking based upon history.
     */
    vector<Team*> actualRanking;

    //Pull Correct Data.
    string id;
    ifstream correct (correctData);
    

    if(correct.is_open()){
        unordered_set<Team*> teams;
        while(getline(correct, id, '\n')){
            teamsInCompetition.insert(stoi(id));
            actualRanking.push_back(teamMap.find(stoi(id))->second);
        }
        correct.close();
    }
    else cout << "Unable to open file";

    //Create map binned by level for truth {First(1), Second(1), Final Four(2), Elite Eight(4), Sweet Sixteen(8), Top 32(16), All(32)}.
    bin(&actualRanking, &actualLevels);

    //Reduce ranking to teams that made it march madness.
    vector<Team>::iterator fullRankItr;
    for(fullRankItr = resultVector.end() - 1; fullRankItr != resultVector.begin() - 1 ; --fullRankItr){
        if(teamsInCompetition.find(teamMap.find(fullRankItr->getId())->second->getId()) != teamsInCompetition.end() ){
            cleanedResultVector.push_back(teamMap.find(fullRankItr->getId())->second);
        }
    }

    //Create map binned by level for output {First(1), Second(1), Final Four(2), Elite Eight(4), Sweet Sixteen(8), Top 32(16), All(32)}.
    bin(&cleanedResultVector, &computedLevels);

    //Compare the contents of each bin.
    double comparisonScore = comparison(&actualLevels, &computedLevels);
    cout << "Similarity Score: " << to_string(100 * comparisonScore / 64) << endl;

    //Print ranking to file.
    ofstream output;
    output.open("output.txt");
    if(output.is_open()){
        output << "Similarity Score: " << to_string(100 * comparisonScore / 64) << endl;
      for(int i = 0; i < cleanedResultVector.size(); i++ )
       output << cleanedResultVector.at(i)->toString() << endl;
    output.close();
    }
    else cout << "Unable to open file";
}

void bin(vector<Team*> *teamVector, vector<vector<int>> *resultVector) {
    int position = 0;
    int index = 0;
    vector<int> levelVector;
    levelVector.push_back(teamVector->at(index++)->getId());
    resultVector->push_back(levelVector);
    while(position <= 5){
        vector<int> levelVector;
        for(int i = pow(2,position); i < pow(2,position + 1) ; i++){
            levelVector.push_back(teamVector->at(index++)->getId());
        }
        resultVector->push_back(levelVector);
        position++;
    }
}

double comparison(vector<vector<int>> *v1, vector<vector<int>> *v2){
    double score = 0;
    for(int i = 0; i < v1->size(); i++){
        vector<int> intersection;
        std::sort(v1->at(i).begin(), v1->at(i).end());
        std::sort(v2->at(i).begin(), v2->at(i).end());


        std::set_intersection(v1->at(i).begin(), v1->at(i).end(),
                              v2->at(i).begin(), v2->at(i).end(),
                              std::back_inserter(intersection));
  
    score += intersection.size();
    }
    return score;
}


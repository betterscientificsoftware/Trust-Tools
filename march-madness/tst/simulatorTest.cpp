#include "gtest/gtest.h"
#include "Simulator.h"
#include "Team.h"
#include "Game.h"


class SimulatorTest : public ::testing::Test {
protected:
  //runs only once
  static void SetUpTestCase()
  {
    createTeams("/workspace/madness/data/TestSetTeams.txt");
    loadGames("/workspace/madness/data/TestSetGames.txt",0,false);
  }
  //runs for every test case
  SimulatorTest() {
    teamMap = getTeamMap();
    it = teamMap.begin();
    gameMatrix = getGameMatrix();
  }
//can be used anywhere
std::map<int, Team*>::iterator it;
Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> gameMatrix;
std::map<int, Team*> teamMap;
int totalTeams= getNumTeams();
};

//start create teams test
TEST_F(SimulatorTest, teamSize)
{
    EXPECT_EQ(totalTeams, 4);
}

TEST_F(SimulatorTest, createTeams)
{
    EXPECT_EQ("Beast Squares", it->second->getName());
    std::advance(it,1);
    EXPECT_EQ("Likelihood Loggers", it->second->getName());
    std::advance(it,1);
    EXPECT_EQ("Linear Aggressors", it->second->getName());
    std::advance(it,1);
    EXPECT_EQ("Gaussian Eliminators", it->second->getName());
}
//end create teams test

//start populate matrix test
TEST_F(SimulatorTest, populateMatrix)
{
	//checking n-1 diagonal entries because the last row is all ones which would throw off total
	int diagonal_sum = 0;
	for(int i = 0; i < 3; i++)
	{
		diagonal_sum += gameMatrix.coeff(i,i);
	}
	EXPECT_EQ(diagonal_sum, 7);
}

TEST_F(SimulatorTest, numGames)
{
	EXPECT_EQ(getNumGamesPlayed(),5);
}


int main(int argc, char **argv) {

testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();

}

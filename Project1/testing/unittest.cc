
#ifndef UNITTEST
#define UNITTEST

/*******************************************************************************
 * Includes
 ******************************************************************************/
// The Google Test framework
#include <gtest/gtest.h>
#include "src/candidate.h"
#include "src/ballot.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
using namespace std;
//NAMESPACE_BEGIN(std);

class ProjectTest : public ::testing::Test {
protected:
  virtual void SetUp() {

  }
};



/*******************************************************************************
 * Tests
 ******************************************************************************/

 TEST_F(ProjectTest, constructor) {
   Ballot ballot;
   //testing default constructor values
   //EXPECT_EQ(ballot.getList_of_names(), []);
   //EXPECT_NE(ballot.getList_of_ranks(), []);
   EXPECT_EQ(ballot.getNum_candidates(), 0);
   EXPECT_EQ(ballot.getBallot_id(), 5);

   ballot.setBallot_id(10);
   ballot.setNum_candidates(5);
   int ranks[] = {1, 2, 3, 4};
   char* names[] = {"john", "mary", "bromeo"};
   ballot.setList_of_ranks(ranks);
   ballot.setList_of_names(names);

   EXPECT_EQ(ballot.getBallot_id(), 10);
   EXPECT_EQ(ballot.getNum_candidates(), 5);
   EXPECT_EQ(ballot.getList_of_ranks(), ranks);
 }


 TEST(Ballot, toString) {
   Ballot ballot;
   ballot.setBallot_id(10);
   EXPECT_EQ(ballot.getBallot_id(), 10);
   ballot.setNum_candidates(4);
   int ranks[] = {1, 2, 3, 4};
   ballot.setList_of_ranks(ranks);
   string str = "ID: 10 Count: 4\n1 2 3 4 ";
   EXPECT_EQ(ballot.toString(), str);
   EXPECT_NE(ballot.toString(), "");

 }

 TEST(Ballot, findCandidate) {
   Ballot ballot;
   ballot.setNum_candidates(5);
   int ranks[] = {1, 2, 3, 4};
   ballot.setList_of_ranks(ranks);
   EXPECT_EQ(ballot.findCandidate(1), 0);
   EXPECT_NE(ballot.findCandidate(1), 2);

 }

TEST_F(ProjectTest, setListOfRank) {
  Ballot ballot_;
  ballot_.setBallot_id(10);
  ballot_.setNum_candidates(5);
  int a[] = { 1,2,3,4 };
  ballot_.setList_of_ranks(a);

}



#endif  // UNITTEST

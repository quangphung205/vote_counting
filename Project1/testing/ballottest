#ifndef UNITTEST
#define UNITTEST

/*******************************************************************************
 * Includes
 ******************************************************************************/
// The Google Test framework
#include <gtest/gtest.h>
#include "src/candidate.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
using namespace std;
//NAMESPACE_BEGIN(std);

class CandidateTest : public ::testing::Test {
protected:
  virtual void SetUp() {

  }
};



/*******************************************************************************
 * Tests
 ******************************************************************************/

 TEST(Ballot, constructor) {
   Ballot ballot;
   //testing default constructor values
   EXPECT_EQ(ballot.getList_of_names(), []);
   EXPECT_NE(ballot.getList_of_ranks(), []);
   EXPECT_EQ(ballot.getNum_Candidates(), 0);
   EXPECT_EQ(ballot.getBallot_id(5));

   ballot.setBallot_id(10);
   ballot.setNum_candidates(5);
   int ranks[] = [1, 2, 3, 4];
   int names[] = ["john", "mary", "bromeo"];
   ballot.setList_of_ranks(ranks);
   ballot.setList_of_names(names);

   EXPECT_EQ(ballot.getBallot_id(), 10);
   EXPECT_EQ(ballot.getNum_candidates(), 5);
   EXPECT_EQ(ballot.getList_of_ranks(), a);



 }

 TEST(Ballot, toString) {
   Ballot ballot;
   ballot.setBallot_id(10);
   EXPECT_EQ(ballot.getBallot_id(), 10);
   ballot.setNum_candidates(4);
   int ranks[] = [1, 2, 3, 4];
   ballot.setList_of_ranks(ranks);
   string str = "ID: 10 Count: 4 \n 1 2 3 4";
   EXPECT_EQ(ballot.toString(), str);
   EXPECT_NE(ballot.toString(), "");


 }

 TEST(Ballot, findCandidate) {
   Ballot ballot;
   ballot.setNum_candidates(5);
   int a[] = [1, 2, 3, 4];
   ballot.setList_of_ranks(a);
   EXPECT_EQ(ballot.findCandidate(1), 1);
   EXPECT_NE(ballot.findCandidate(1), 3);

 }

#endif  // UNITTEST
© 2018 GitHub, Inc.
Help
Support
API
Training
Shop
Blog
About

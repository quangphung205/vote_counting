
#ifndef BALLOT_TEST
#define BALLOT_TEST

/*******************************************************************************
 * Includes
 ******************************************************************************/
// The Google Test framework
#include <gtest/gtest.h>
#include "src/candidate.h"
#include "src/election.h"
#include "src/ballot.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
using namespace std;

/*******************************************************************************
 * Classes
 ******************************************************************************/

 class BallotTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
 };

/*******************************************************************************
 * Tests
 ******************************************************************************/
/* ballot.h unit tests */
TEST_F(BallotTest, Ballot_Constructor) {
   Ballot ballot;
   //testing default constructor values
   EXPECT_EQ((long)ballot.getList_of_names(), NULL) << "\nFAIL ballot constructor failed";
   EXPECT_EQ((long)ballot.getList_of_ranks(), NULL) << "\nFAIL ballot constructor failed";
   EXPECT_EQ(ballot.getNum_candidates(), 0) << "\nFAIL ballot constructor failed";
   EXPECT_EQ(ballot.getBallot_id(), 5) << "\nFAIL ballot constructor failed";

   ballot.setBallot_id(10);
   ballot.setNum_candidates(5);
   int ranks[] = {1, 2, 3, 4};
   char* names[] = {(char*)"john", (char*)"mary", (char*)"bromeo"};
   ballot.setList_of_ranks(ranks);
   ballot.setList_of_names(names);

   EXPECT_EQ(ballot.getBallot_id(), 10) << "\nFAIL ballot constructor failed";
   EXPECT_EQ(ballot.getNum_candidates(), 5) << "\nFAIL ballot constructor failed";
   EXPECT_EQ(ballot.getList_of_ranks(), ranks) << "\nFAIL ballot constructor failed";
   EXPECT_EQ(ballot.getList_of_names(), names) << "\nFAIL ballot constructor failed";
 }

 TEST_F(BallotTest, Ballot_ToString) {

   Ballot ballot;
   ballot.setBallot_id(10);
   EXPECT_EQ(ballot.getBallot_id(), 10) << "\nFAIL ballot toString failed";
   ballot.setNum_candidates(4);
   int ranks[] = {1, 2, 3, 4};
   ballot.setList_of_ranks(ranks);
   string str = "10: 1 2 3 4 ";
   EXPECT_EQ(ballot.toString(), str) << "\nFAIL ballot toString failed";
   EXPECT_NE(ballot.toString(), "") << "\nFAIL ballot toString failed";
 }

 TEST_F(BallotTest, Ballot_FindCandidate) {
   Ballot ballot;
   ballot.setNum_candidates(5);
   int ranks[] = {1, 2, 3, 4};
   ballot.setList_of_ranks(ranks);
   EXPECT_EQ(ballot.findCandidate(1), 0) << "\nFAIL ballot findCandidate failed";
   EXPECT_NE(ballot.findCandidate(1), 2) << "\nFAIL ballot findCandidate failed";
 }

TEST_F(BallotTest, Ballot_SetListOfRank) {
  Ballot ballot_;
  ballot_.setBallot_id(10);
  ballot_.setNum_candidates(5);
  int* a = new int[4];
  a[0] = 0; a[1] = 1; a[2] = 2; a[3] = 3;
  ballot_.setList_of_ranks(a);
  EXPECT_EQ(ballot_.getList_of_ranks(), a) << "\nFAIL ballot setListOfRanks failed";
}

#endif  // BALLOT_TEST

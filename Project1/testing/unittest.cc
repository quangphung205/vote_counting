
#ifndef UNITTEST
#define UNITTEST

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

 class ProjectTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
 };

/*******************************************************************************
 * Tests
 ******************************************************************************/
/* ballot.h unit tests */
 TEST_F(ProjectTest, Ballot_Constructor) {
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

 TEST_F(ProjectTest, Ballot_ToString) {

   Ballot ballot;
   ballot.setBallot_id(10);
   EXPECT_EQ(ballot.getBallot_id(), 10) << "\nFAIL ballot toString failed";
   ballot.setNum_candidates(4);
   int ranks[] = {1, 2, 3, 4};
   ballot.setList_of_ranks(ranks);
   string str = "ID: 10 Count: 4\n1 2 3 4 ";
   EXPECT_EQ(ballot.toString(), str) << "\nFAIL ballot toString failed";
   EXPECT_NE(ballot.toString(), "") << "\nFAIL ballot toString failed";
 }

 TEST_F(ProjectTest, Ballot_FindCandidate) {
   Ballot ballot;
   ballot.setNum_candidates(5);
   int ranks[] = {1, 2, 3, 4};
   ballot.setList_of_ranks(ranks);
   EXPECT_EQ(ballot.findCandidate(1), 0) << "\nFAIL ballot findCandidate failed";
   EXPECT_NE(ballot.findCandidate(1), 2) << "\nFAIL ballot findCandidate failed";
 }

TEST_F(ProjectTest, Ballot_SetListOfRank) {
  Ballot ballot_;
  ballot_.setBallot_id(10);
  ballot_.setNum_candidates(5);
  int* a = new int[4];
  a[0] = 0; a[1] = 1; a[2] = 2; a[3] = 3;
  ballot_.setList_of_ranks(a);
  EXPECT_EQ(ballot_.getList_of_ranks(), a) << "\nFAIL ballot setListOfRanks failed";
}

/* election.h unit tests */
TEST_F(ProjectTest, Election_Constructor) {
  Election election;

  election.setNum_candidates(0);
  election.setNum_seats(0);
  election.setNum_ballots(3);
  election.setVoting_method(0);

  EXPECT_EQ(election.getNum_candidates(), 0) << "\nFAIL election constructor failed";
  EXPECT_EQ(election.getNum_seats(), 0) << "\nFAIL election constructor failed";
  EXPECT_EQ(election.getNum_ballots(), 3) << "\nFAIL election constructor failed";
  EXPECT_EQ(election.getVoting_method(), 0) << "\nFAIL election constructor failed";
}

TEST_F(ProjectTest, Election_ParseInput) {
  Election election;

  election.parseInput("input.csv");
  EXPECT_EQ(election.getNum_candidates(), 6) << "Fail on num candidate\n";
  EXPECT_EQ(election.getNum_ballots(), 6) << "Fail on num ballots\n";
}

TEST_F(ProjectTest, Election_CalculateDroop) {
  Election election;
  election.setNum_seats(10);
  election.setNum_ballots(44);
  EXPECT_EQ(election.calculateDroop(), 5) << "\nFAIL election calculateDroop failed";
}


TEST_F(ProjectTest, toString_for_election) {
  Election election;
  election.setNum_candidates(1);
  election.setNum_ballots(1);
  Candidate* cand = new Candidate[1];
  cand[0].setCandidate_name("Quang");
  election.setCandidates_list(cand);

  Ballot* bal = new Ballot[1];
  bal[0].setBallot_id(5);
  bal[0].setNum_candidates(1);
  bal[0].setList_of_ranks(new int(3));
  election.setBallot_list(bal);
  EXPECT_EQ(election.toString(), "Quang\nID: 5 Count: 1\n3 \n") << "\nFAIL tostring of Election";
}

TEST_F(ProjectTest, sortCandidateByVotes) {
  Election election;
  Candidate* cand_lst = new Candidate[5];
  cand_lst[0].setNum_ballots(2);
  cand_lst[1].setNum_ballots(3);
  cand_lst[2].setNum_ballots(5);
  cand_lst[3].setNum_ballots(9);
  cand_lst[4].setNum_ballots(7);

  election.setCandidates_list(cand_lst);
  election.setNum_candidates(5);
  election.sortCandidateByVotes();

  cand_lst = election.getCandidates_list();
  EXPECT_EQ(cand_lst[0].getNum_ballots(), 9) << "\nFAIL sort candidate fails";
  EXPECT_EQ(cand_lst[1].getNum_ballots(), 7) << "\nFAIL sort candidate fails";
  EXPECT_EQ(cand_lst[2].getNum_ballots(), 5) << "\nFAIL sort candidate fails";
  EXPECT_EQ(cand_lst[3].getNum_ballots(), 3) << "\nFAIL sort candidate fails";
  EXPECT_EQ(cand_lst[4].getNum_ballots(), 2) << "\nFAIL sort candidate fails";
}

TEST_F(ProjectTest, Candidate_Constructor) {
  // testing default constructor values
        Candidate candidate;
  EXPECT_EQ(candidate.getCandidate_name(), "") << "\nFAIL candidate constructor failed";
  EXPECT_EQ(candidate.getNum_ballots(), 0) << "\nFAIL candidate constructor failed";
  EXPECT_EQ(candidate.getIsWinner(), false) << "\nFAIL candidate constructor failed";

  candidate.setCandidate_name("Test");
  candidate.setNum_ballots(99);
  candidate.setIsWinner(true);

  EXPECT_EQ(candidate.getCandidate_name(), "Test") << "\nFAIL candidate constructor failed";
  EXPECT_EQ(candidate.getNum_ballots(), 99) << "\nFAIL candidate constructor failed";
  EXPECT_EQ(candidate.getIsWinner(), true) << "\nFAIL candidate constructor failed";
}

TEST_F(ProjectTest, Candidate_ToString) {
  // testing default constructor values before alteration
  Candidate candidate;
  EXPECT_EQ(candidate.getCandidate_name(), "") << "\nFAIL candidate constructor failed";
  EXPECT_EQ(candidate.getNum_ballots(), 0) << "\nFAIL candidate constructor failed";
  EXPECT_EQ(candidate.getIsWinner(), false) << "\nFAIL candidate constructor failed";

  // testing alteration
  candidate.setCandidate_name("QWERTY");
  EXPECT_EQ(candidate.getCandidate_name(), "QWERTY") << "\nFAIL candidate tostring failed after alteration";
  EXPECT_EQ(candidate.toString(), "QWERTY") << "\nFAIL candidate tostring failed after alteration";

  candidate.setCandidate_name("");
  // testing default constructor values after alteration
  EXPECT_EQ(candidate.getCandidate_name(), "") << "\nFAIL candidate tostring failed after alteration";
  EXPECT_EQ(candidate.getNum_ballots(), 0) << "\nFAIL candidate tostring failed after alteration";
  EXPECT_EQ(candidate.getIsWinner(), false) << "\nFAIL candidate tostring failed after alteration";
}

TEST_F(ProjectTest, Candidate_ToStringWithVotes) {
  Candidate candidate;

  // testing default constructor values before alteration
  EXPECT_EQ(candidate.getCandidate_name(), "") << "\nFAIL candidate toStringWithVotes failed";
  EXPECT_EQ(candidate.getNum_ballots(), 0) << "\nFAIL candidate toStringWithVotes failed";
  EXPECT_EQ(candidate.getIsWinner(), false) << "\nFAIL candidate toStringWithVotes failed";

  // testing alteration
  candidate.setCandidate_name("default");
  EXPECT_EQ(candidate.getCandidate_name(), "default") << "\nFAIL candidate toStringWithVotes failed";
  candidate.setNum_ballots(1);
  EXPECT_EQ(candidate.getNum_ballots(), 1) << "\nFAIL candidate toStringWithVotes failed";

  Ballot* someBallot = new Ballot;
  someBallot->setBallot_id(1);
  candidate.setBallot_list(someBallot);
  EXPECT_EQ(candidate.toStringWithVotes(), "default: 1 ") << "\nFAIL candidate toStringWithVotes failed";

  candidate.setNum_ballots(6);
  EXPECT_EQ(candidate.getNum_ballots(), 6) << "\nFAIL candidate toStringWithVotes failed";
  EXPECT_EQ(candidate.getIsWinner(), false) << "\nFAIL candidate toStringWithVotes failed";

}

#endif  // UNITTEST

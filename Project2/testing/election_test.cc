#ifndef ELECTION_TEST
#define ELECTION_TEST

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

 class ElectionTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
 };

/*******************************************************************************
 * Tests
 ******************************************************************************/
/* election.h unit tests */
TEST_F(ElectionTest, Election_Constructor) {
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

TEST_F(ElectionTest, Election_ParseInput) {
  Election election;

  election.parseInput("test1");
  EXPECT_EQ(election.getNum_candidates(), 5) << "Fail on num candidate\n";
  EXPECT_EQ(election.getNum_ballots(), 20) << "Fail on num ballots\n";
}

TEST_F(ElectionTest, Election_CalculateDroop) {
  Election election;
  election.setNum_seats(10);
  election.setNum_ballots(44);
  EXPECT_EQ(election.calculateDroop(), 5) << "\nFAIL election calculateDroop failed";
}

TEST_F(ElectionTest, Election_Plurality) {
  Election election;
  election.setNum_candidates(2);
  election.setNum_ballots(1);
  election.setNum_seats(1);

  Candidate* cand_lst = new Candidate[2];
  cand_lst[0].setCandidate_name("A");
  cand_lst[1].setCandidate_name("B");

  Ballot* bal_lst = new Ballot[1];
  int* tmp = new int[2];
  tmp[0] = 0;
  tmp[1] = 1;
  bal_lst[0].setList_of_ranks(tmp);
  bal_lst[0].setNum_candidates(2);

  election.setBallot_list(bal_lst);
  election.setCandidates_list(cand_lst);

  election.runPlurality();

  Candidate* winners = election.getWinner_list();
  Candidate* losers = election.getAlternate_list();

  EXPECT_EQ(winners->getCandidate_name(), "B") << "\nFAIL election plurality failed";
  EXPECT_EQ(losers->getCandidate_name(), "A") << "\nFAIL election plurality failed";
}

TEST_F(ElectionTest, Election_Droop) {
  Election election;
  election.setNum_candidates(2);
  election.setNum_ballots(1);
  election.setNum_seats(1);

  Candidate* cand_lst = new Candidate[2];
  cand_lst[0].setCandidate_name("C");
  cand_lst[1].setCandidate_name("D");

  Ballot* bal_lst = new Ballot[1];
  int* tmp = new int[2];
  tmp[0] = 0;
  tmp[1] = 1;
  bal_lst[0].setList_of_ranks(tmp);
  bal_lst[0].setNum_candidates(2);

  election.setBallot_list(bal_lst);
  election.setCandidates_list(cand_lst);

  election.runDroop();

  Candidate* winners = election.getWinner_list();
  Candidate* losers = election.getAlternate_list();

  EXPECT_EQ(winners->getCandidate_name(), "D") << "\nFAIL election droop failed";
  EXPECT_EQ(losers->getCandidate_name(), "C") << "\nFAIL election droop failed";
}

TEST_F(ElectionTest, toString_for_election) {
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
  EXPECT_EQ(election.toString(), "Quang\n5: 3 \n") << "\nFAIL tostring of Election";
}

TEST_F(ElectionTest, sortCandidateByVotes) {
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

#endif  // ELECTION_TEST

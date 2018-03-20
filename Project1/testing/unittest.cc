
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

TEST_F(CandidateTest, setListOfRank) {
  Ballot ballot_;
  ballot_.setBallot_id(10);
  ballot_.setNum_candidates(5);
  int a[] = { 1,2,3,4 };
  ballot_.setList_of_ranks(a);

}
/* election.h unit tests */
TEST(Election, Constructor) {
  Election election;

  EXPECT_EQ(election.getNum_candidates(), 0);
  EXPECT_EQ(election.getBallot_list(), NULL);
  EXPECT_EQ(election.getNum_ballots(), 0);
  EXPECT_EQ(election.getWinner_list(), NULL);
  EXPECT_EQ(election.getAlternate_list(), NULL);
}

TEST(Election, toString) {
  Election election;
  // testing default constructor values before alteration
  EXPECT_EQ(election.getNum_candidates(), 0);
  EXPECT_EQ(election.getBallot_list(), NULL);
  EXPECT_EQ(election.getNum_ballots(), 0);
  EXPECT_EQ(election.getWinner_list(), NULL);
  EXPECT_EQ(election.getAlternate_list(), NULL);
  // testing alteration
  // TODO

  // testing default constructor values after alteration
  EXPECT_EQ(election.getNum_candidates(), 0);
  EXPECT_EQ(election.getBallot_list(), NULL);
  EXPECT_EQ(election.getNum_ballots(), 0);
  EXPECT_EQ(election.getWinner_list(), NULL);
  EXPECT_EQ(election.getAlternate_list(), NULL);

}

TEST(Election, parseInput) {
  // TODO
  EXPECT_EQ(election.get(), 0);
  EXPECT_EQ(election.getBallot_list(), NULL);
  EXPECT_EQ(election.getNum_ballots(), 0);
  EXPECT_EQ(election.getWinner_list(), NULL);
  EXPECT_EQ(election.getAlternate_list(), NULL);
  // testing alteration
  // TODO

  // testing default constructor values after alteration
  EXPECT_EQ(election.getNum_candidates(), 0);
  EXPECT_EQ(election.getBallot_list(), NULL);
  EXPECT_EQ(election.getNum_ballots(), 0);
  EXPECT_EQ(election.getWinner_list(), NULL);
  EXPECT_EQ(election.getAlternate_list(), NULL);
}

TEST(Election, writeToFile) {
  // TODO
}

TEST(Election, generateAuditFile) {
  // TODO
}

TEST(Election, runPlurality) {

}

TEST(Election, distributeVote) {
  // TODO
}

TEST(Election, sortCandidateByVotes) {
  // TODO
}

TEST(Election, shuffleBallots) {

}


/* candidate.h unit tests */
TEST(CandidateTest, constructor) {
  Candidate candidate;
  // testing default constructor values
  EXPECT_EQ(candidate.getCandidate_name(), "");
  //  EXPECT_NE(candidate.getBallot_list(), NULL);
  EXPECT_EQ(candidate.getNum_ballots(), 0);
  EXPECT_EQ(candidate.getIsWinner(), false);

  candidate.setCandidate_name("a Test");
  // TODO someBallot = new Ballot[]
  // TODO candidate.setBallot_list();
  candidate.setNum_ballots(99);
  candidate.setIsWinner(true);

  EXPECT_EQ(candidate.getCandidate_name(), "a Test");
  // TODO EXPECT_NE(candidate.getBallot_list(), );
  EXPECT_EQ(candidate.getNum_ballots(), 99);
  EXPECT_EQ(candidate.getIsWinner(), true);
}

TEST_F(CandidateTest, toString) {
  Candidate candidate;
  // testing default constructor values before alteration
  EXPECT_EQ(candidate.getCandidate_name(), "");
  //  EXPECT_NE(candidate.getBallot_list(), NULL);
  EXPECT_EQ(candidate.getNum_ballots(), 0);
  EXPECT_EQ(candidate.getIsWinner(), false);
  // testing alteration
  candidate.setCandidate_name("QWERTY");
  EXPECT_EQ(candidate.getCandidate_name(), "QWERTY");
  EXPECT_EQ(candidate.toString(), "QWERTY");
  candidate.setCandidate_name("");
  // testing default constructor values after alteration
  EXPECT_EQ(candidate.getCandidate_name(), "");
  //  EXPECT_NE(candidate.getBallot_list(), NULL);
  EXPECT_EQ(candidate.getNum_ballots(), 0);
  EXPECT_EQ(candidate.getIsWinner(), false);
}

TEST_F(CandidateTest, toStringWithVotes) {
  Candidate candidate;
  // testing default constructor values before alteration
  EXPECT_EQ(candidate.getCandidate_name(), "");
  //  EXPECT_NE(candidate.getBallot_list(), NULL);
  EXPECT_EQ(candidate.getNum_ballots(), 0);
  EXPECT_EQ(candidate.getIsWinner(), false);
  // testing alteration
  candidate.setCandidate_name("default");
  EXPECT_EQ(candidate.getCandidate_name(), "default");
  candidate.setNum_ballots(3);
  EXPECT_EQ(candidate.getNum_ballots(), 3);
  // TODO how to handle ballot_list_[i].getBallot_id()
  // TODO toStringWithVotes
  // testing default constructor values after alteration
  //  EXPECT_NE(candidate.getBallot_list(), NULL);
  EXPECT_EQ(candidate.getNum_ballots(), 0);
  EXPECT_EQ(candidate.getIsWinner(), false);
}

#endif  // UNITTEST

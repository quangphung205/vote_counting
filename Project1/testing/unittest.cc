
#ifndef UNITTEST
#define UNITTEST

/*******************************************************************************
 * Includes
 ******************************************************************************/
// The Google Test framework
#include <gtest/gtest.h>
#include "src/candidate.h"
#include "src/election.h"

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

TEST_F(ProjectTest, setListOfRank) {
  Ballot ballot_;
  ballot_.setBallot_id(10);
  ballot_.setNum_candidates(5);
  int a[] = { 1,2,3,4 };
  ballot_.setList_of_ranks(a);

}
/* election.h unit tests */
TEST_F(ProjectTest, Constructor_election) {
  Election election;

  election.setNum_candidates(0);
  election.setNum_seats(0);
  election.setNum_ballots(3);
  election.setVoting_method(0);

  EXPECT_EQ(election.getNum_candidates(), 0);
  EXPECT_EQ(election.getNum_seats(), 0);
  EXPECT_EQ(election.getNum_ballots(), 3);
  EXPECT_EQ(election.getVoting_method(), 0);



}

TEST_F(ProjectTest, parseInput) {
  Election election;

  // TODO
  election.parseInput("input.csv");
  EXPECT_EQ(election.getNum_candidates(), 6) << "Fail on num candidate\n";
  EXPECT_EQ(election.getNum_ballots(), 6) << "Fail on num ballots\n";

}

TEST_F(ProjectTest, writeToFile) {
  Election election;

  // TODO
  // election.writeToFile(" ");
  // EXPECT_EQ(election.getNum_candidates(), 6)
  // EXPECT_EQ(election.getNum_ballots(), 6)
}

TEST_F(ProjectTest, generateAuditFile) {
  Election election;

  // TODO
  // election.generateAuditFile(" ");
  // EXPECT_EQ(election.getNum_candidates(), 6)
  // EXPECT_EQ(election.getNum_ballots(), 6)
}

TEST_F(ProjectTest, runPlurality) {
  Election election;

  // TODO
  // EXPECT_EQ(election.getNum_candidates(), 6)
  // EXPECT_EQ(election.getNum_ballots(), 6)

}

TEST_F(ProjectTest, toString_for_election) {
  Election election;
  // testing default constructor values before alteration
  EXPECT_EQ(election.getNum_candidates(), 0);
  // EXPECT_EQ(election.getBallot_list(), NULL);
  EXPECT_EQ(election.getNum_ballots(), 0);
  // EXPECT_EQ(election.getWinner_list(), NULL);
  // EXPECT_EQ(election.getAlternate_list(), NULL);
  // testing alteration
  // TODO

  // testing default constructor values after alteration
  EXPECT_EQ(election.getNum_candidates(), 0);
  // EXPECT_EQ(election.getBallot_list(), NULL);
  EXPECT_EQ(election.getNum_ballots(), 0);
  // EXPECT_EQ(election.getWinner_list(), NULL);
  // EXPECT_EQ(election.getAlternate_list(), NULL);

}

TEST_F(ProjectTest, distributeVote) {
  Election election;

  // TODO
  // election.distributeVote(" ");
  // EXPECT_EQ(election.getNum_candidates(), 6)
  // EXPECT_EQ(election.getNum_ballots(), 6)
}

TEST_F(ProjectTest, sortCandidateByVotes) {
  Election election;

  // TODO
  // election.sortCandidateByVotes(" ");
  // EXPECT_EQ(election.getNum_candidates(), 6)
  // EXPECT_EQ(election.getNum_ballots(), 6)
}

TEST_F(ProjectTest, shuffleBallots) {
  Election election;

  // TODO
  // election.shuffleBallots(" ");
  // EXPECT_EQ(election.getNum_candidates(), 6)
  // EXPECT_EQ(election.getNum_ballots(), 6)
}


/* candidate.h unit tests */
TEST_F(ProjectTest, constructor_election) {
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

TEST_F(ProjectTest, toString_for_candidate) {
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

TEST_F(ProjectTest, toStringWithVotes) {
  Candidate candidate;
  // testing default constructor values before alteration
  EXPECT_EQ(candidate.getCandidate_name(), "");
  //  EXPECT_NE(candidate.getBallot_list(), NULL);
  //EXPECT_EQ(candidate.getNum_ballots(), 0);
  EXPECT_EQ(candidate.getIsWinner(), false);
  // testing alteration
  candidate.setCandidate_name("default");
  EXPECT_EQ(candidate.getCandidate_name(), "default");
  candidate.setNum_ballots(3);
  //EXPECT_EQ(candidate.getNum_ballots(), 3);
  // TODO how to handle ballot_list_[i].getBallot_id()
  // TODO toStringWithVotes
  // testing default constructor values after alteration
  //  EXPECT_NE(candidate.getBallot_list(), NULL);
  EXPECT_EQ(candidate.getIsWinner(), false);
}

#endif  // UNITTEST


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

class CandidateTest : public ::testing::Test {
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

/* candidate.h unit tests */
}

TEST_F(CandidateTest, constructor) {
  // testing default constructor values
        Candidate candidate;
  EXPECT_EQ(candidate.getCandidate_name(), "");
  EXPECT_EQ(candidate.getNum_ballots(), 0);
  EXPECT_EQ(candidate.getIsWinner(), false);

  candidate.setCandidate_name("Test");
  candidate.setNum_ballots(99);
  candidate.setIsWinner(true);

  EXPECT_EQ(candidate.getCandidate_name(), "Test");
  EXPECT_EQ(candidate.getNum_ballots(), 99);
  EXPECT_EQ(candidate.getIsWinner(), true);
}

TEST_F(CandidateTest, toString) {
  // testing default constructor values before alteration
        Candidate candidate;
  EXPECT_EQ(candidate.getCandidate_name(), "");
  EXPECT_EQ(candidate.getNum_ballots(), 0);
  EXPECT_EQ(candidate.getIsWinner(), false);
  // testing alteration
  candidate.setCandidate_name("QWERTY");
  EXPECT_EQ(candidate.getCandidate_name(), "QWERTY");
  EXPECT_EQ(candidate.toString(), "QWERTY");
  candidate.setCandidate_name("");
  // testing default constructor values after alteration
  EXPECT_EQ(candidate.getCandidate_name(), "");
  EXPECT_EQ(candidate.getNum_ballots(), 0);
  EXPECT_EQ(candidate.getIsWinner(), false);
}

TEST_F(CandidateTest, toStringWithVotes) {
        Candidate candidate;
  // testing default constructor values before alteration
  EXPECT_EQ(candidate.getCandidate_name(), "");
  EXPECT_EQ(candidate.getNum_ballots(), 0);
  EXPECT_EQ(candidate.getIsWinner(), false);
  // testing alteration
  candidate.setCandidate_name("default");
  EXPECT_EQ(candidate.getCandidate_name(), "default");
  candidate.setNum_ballots(1);
  EXPECT_EQ(candidate.getNum_ballots(), 1);
  Ballot* someBallot = new Ballot;
  someBallot->setBallot_id(1);
  candidate.setBallot_list(someBallot);
  EXPECT_EQ(candidate.toStringWithVotes(), "default: 1 ");
  // TODO how to handle ballot_list_[i].getBallot_id()
  // TODO toStringWithVotes
  // testing default constructor values after alteration
  candidate.setNum_ballots(0);
  EXPECT_EQ(candidate.getNum_ballots(), 0);
  EXPECT_EQ(candidate.getIsWinner(), false);

}

#endif  // UNITTEST

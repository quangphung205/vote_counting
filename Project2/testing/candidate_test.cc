
#ifndef CANDIDATE_TESTS
#define CANDIDATE_TESTS

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

 class CandidateTest : public ::testing::Test {
 protected:
   virtual void SetUp() {
   }
 };

/*******************************************************************************
 * Tests
 ******************************************************************************/
TEST_F(CandidateTest, Candidate_Constructor) {
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

TEST_F(CandidateTest, Candidate_ToString) {
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

TEST_F(CandidateTest, Candidate_ToStringWithVotes) {
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

#endif  // CANDIDATE_TESTS

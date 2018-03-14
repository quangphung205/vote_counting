/*
 * @copyright 2018 CSCI 5801 Team 09, All rights reserved.
 */
#ifndef PROJECT1_SRC_ELECTION_H_
#define PROJECT1_SRC_ELECTION_H_

#include <iostream>
#include "src/ballot.h"
#include "src/candidate.h"


NAMESPACE_BEGIN(std);

class Election {
 public:
  /*
   * @TODO: need getters/setters for each member
   */

  int parseInput(ifstream input);

 private:
    int num_candidates_;
    int num_seats_;
    int num_ballots_;
    int voting_method_;

    Candidate* candidates_list_;
    Candidate* winner_list_;
    Candidate* alternate_list_;
    Ballot* ballot_list_;

    bool shuffle_;  // for testing correctness
};

#endif  // PROJECT1_SRC_ELECTION_H_

#include "ballot.h"
#include "candidate.h"
#include <iostream>

#ifndef ELECTION_H_
#define ELECTION_H_

using namespace std;

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

#endif  // ELECTION_H_

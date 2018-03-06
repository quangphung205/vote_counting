#include "ballot.h"
#include <iostream>
#include <string>

#ifndef CANDIDATE_H_
#define CANDIDATE_H_

using namespace std;
class Candidate {
public:
  /*
   * @TODO: need getters/setters for each member
   */

private:
  string name_;
  Ballot *ballot_list_;  // a list of ballots associated with each candidate
                         // after running the voting method
  int num_ballots_;  // a number of ballots
  bool isWinner;     // check if a candidate is in a winner list (for droop)
};

#endif  // CANDIDATE_H_

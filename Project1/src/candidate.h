/*
 * @copyright 2018 CSCI 5801 Team 09, All rights reserved.
 */
#ifndef PROJECT1_SRC_CANDIDATE_H_
#define PROJECT1_SRC_CANDIDATE_H_

#include <string>
#include <iostream>
#include "ballot.h"

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

#endif  // PROJECT1_SRC_CANDIDATE_H_

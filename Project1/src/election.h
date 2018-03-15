/*
 * @copyright 2018 CSCI 5801 Team 09, All rights reserved.
 */
#ifndef PROJECT1_SRC_ELECTION_H_
#define PROJECT1_SRC_ELECTION_H_

#include <iostream>
#include "ballot.h"
#include "candidate.h"


using namespace std;

class Election {
 public:
  /*
   * @TODO: need getters/setters for each member
   */

  /*
   * @TODO
   * parseInput: get a CSV file name as an argument
   * Return value: 1 if successful, 0 error occurs
   */
  int parseInput(const char *fname) {
    cout << "election.h::parseInput Need to implement" << endl;
    return 1;
  }

  int get_voting_method() { return voting_method_; }
  int runPlurality() {
    cout << "election.h::runPlurality Need to implement" << endl;
    return -1;
  }

  int runDroop() {
    cout << "election.h::runDroop Need to implement" << endl;
    return -1;
  }

  int writeToFile(const char *fname) {
    cout << "election.h::writeToFile Need to implement" << endl;
    return -1;
  }

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

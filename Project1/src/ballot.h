/*
 * @copyright 2018 CSCI 5801 Team 09, All rights reserved.
 */
#ifndef PROJECT1_SRC_BALLOT_H_
#define PROJECT1_SRC_BALLOT_H_

#include <iostream>

NAMESPACE_BEGIN(std);

class Ballot {
 public:
  /*
   * @TODO: need getters/setters for each member
   */
 private:
     int* candidate_ranks_;  // a list of rankings for each candidate
                          // can be blank (0)
     int num_candidates_;
     int id_;
};

#endif  // PROJECT1_SRC_BALLOT_H_

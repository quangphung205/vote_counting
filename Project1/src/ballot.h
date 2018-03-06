#include <iostream>

#ifndef BALLOT_H_
#define BALLOT_H_

using namespace std;

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

#endif  // BALLOT_H_

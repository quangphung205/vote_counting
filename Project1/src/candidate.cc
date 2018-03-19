/*
 * @copyright 2018 CSCI 5801 Team 09, All rights reserved.
 */

#include "candidate.h"

Candidate::Candidate() {
  candidate_name_ = "test";
  ballot_list_ = new Ballot[5];
  num_ballots_ = 5;
}

string Candidate::toString() {
  return candidate_name_;
}

string Candidate::toStringWithVotes() {
  string result = candidate_name_ + ": ";
  for (int i = 0; i < num_ballots_; i++) {
    result += to_string(ballot_list_[i].getBallot_id()) + " ";
  }

  return result;
}

/*
 * @copyright 2018 CSCI 5801 Team 09, All rights reserved.
 */

#include "candidate.h"

Candidate::Candidate() {
  candidate_name_ = "";
  ballot_list_ = new Ballot[MAX_BALLOT];
  num_ballots_ = 0;
  status_ = 0;
  isWinner = false;
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

void Candidate::recordBallot(Ballot bal) {
  ballot_list_[num_ballots_++] = bal;
}

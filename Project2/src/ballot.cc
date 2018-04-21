/**
 * @copyright 2018 CSCI 5801 Team 09, All rights reserved.
 */

#include "ballot.h"
#include <stdio.h>
#include <stdlib.h>

Ballot::Ballot() {
  ballot_id_ = 5;
  list_of_names_ = NULL;
  list_of_ranks_ = NULL;
  num_candidates_ = 0;
}

string Ballot::toString() {
  /**
   * string format to return:
     ID : <ballot id>
     Count: <rank 1> <rank 2> ... <rank n>
   */
  char buff[10];
  /*
  sprintf(buff, "%d", ballot_id_);
  string result = "ID: " + string(buff) + " ";
  sprintf(buff, "%d", num_candidates_);
  result += ("Count: " + string(buff) + "\n");
  for (int i = 0; i < num_candidates_; i++) {
    sprintf(buff, "%d", list_of_ranks_[i]);
    result += (string(buff) + " ");
  }
  */
  sprintf(buff, "%d: ", ballot_id_);
  string result = string(buff);
  for (int i = 0; i < num_candidates_; i++) {
    sprintf(buff, "%d ", list_of_ranks_[i]);
    result += string(buff);
  }
  return result;
}

int Ballot::findCandidate(int rank) {
  // find an index to a candidate who has "rank" in the ballot
  for (int i = 0; i < num_candidates_; i++) {
    if (list_of_ranks_[i] == rank) {
      return i;
    }
  }

  return -1;
}

bool Ballot::isValid() {
  int count = 0;
  for (int i = 0; i < num_candidates_; i++) {
    if (list_of_ranks_[i] > 0) {
      count++;
    }
  }

  return (count >= ((num_candidates_ + 1) / 2));
}

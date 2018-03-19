/*
 * @copyright 2018 CSCI 5801 Team 09, All rights reserved.
 */

#include "ballot.h"
#include <stdio.h>
#include <stdlib.h>

string Ballot::toString() {
  char buff[10];
  sprintf(buff, "%d", ballot_id_);
  string result = "ID: " + string(buff) + " ";
  sprintf(buff, "%d", num_candidates_);
  result += ("Count: " + string(buff) + "\n");
  for (int i = 0; i < num_candidates_; i++) {
    sprintf(buff, "%d", list_of_ranks_[i]);
    result += (string(buff) + " ");
  }  
  return result;
}

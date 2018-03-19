/*
 * @copyright 2018 CSCI 5801 Team 09, All rights reserved.
 */

#include "election.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

Election::Election() {
  candidates_list_ = new Candidate[MAX_CAND];
  ballot_list_ = new Ballot[MAX_BALLOT];
  num_candidates_ = 0;
  num_ballots_ = 0;

  winner_list_ = new Candidate[10];
  num_winners_ = 10;

  alternate_list_ = new Candidate[7];
  num_alternatives_ = 7;
}

int Election::parseInput(const char *fname) {
  if (fname == NULL) {
    return -1;
  }

  ifstream input(fname);
  string names;
  getline(input, names);
  istringstream iss(names);
  while (getline(iss, names, ',')) {
    candidates_list_[num_candidates_].setCandidate_name(names);
    num_candidates_++;
  }

  string ballots;
  string ballot;

  int i = 0;
  while (getline(input, ballots)) {
    if (ballots == "") continue;
    istringstream tmp(ballots);
    i = 0;
    int *lst = new int(num_candidates_);
    while(getline(tmp, ballot, ',')) {
      int temp;
      if (ballot == "")
        temp = 0;
      else temp = stoi(ballot);
      lst[i] = temp;
      i++;
    }
    ballot_list_[num_ballots_].setNum_candidates(num_candidates_);
    ballot_list_[num_ballots_].setBallot_id(num_ballots_);
    ballot_list_[num_ballots_].setList_of_ranks(lst);
    num_ballots_++;
  }

  input.close();
  return 1;
}

int Election::writeToFile(const char *fname) {
  if (fname == NULL) {
    return -1;
  }

  ofstream output(fname);
  output << "Winner list" << endl;
  for (int i = 0; i < num_winners_; i++) {
    output << winner_list_[i].toString() << endl;
  }

  output << endl << "Alternative list" << endl;
  for (int i = 0; i < num_alternatives_; i++) {
    output << alternate_list_[i].toString() << endl;
  }
  return 1;
}

int Election::generateAuditFile(const char *fname) {
  if (fname == NULL) {
    return -1;
  }

  ofstream output(fname);
  for (int i = 0; i < num_winners_; i++) {
    output << winner_list_[i].toStringWithVotes() << endl;
  }
  return 1;
}

string Election::toString() {
  string result;
  for (int i = 0; i < num_candidates_; i++) {
    result += candidates_list_[i].toString() + "\n";
  }
  for (int i = 0; i < num_ballots_; i++) {
    result += ballot_list_[i].toString() + "\n";
  }
  return result;
}

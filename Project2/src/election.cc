/**
 * @copyright 2018 CSCI 5801 Team 09, All rights reserved.
 */

#include "election.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <math.h>

using namespace std;

Election::Election() {
  /**
   * initialize all members of the Election class
   */
  candidates_list_ = new Candidate[MAX_CAND];
  num_candidates_ = 0;

  ballot_list_ = new Ballot[MAX_BALLOT];
  num_ballots_ = 0;

  winner_list_ = new Candidate[MAX_CAND];
  num_winners_ = 0;

  alternate_list_ = new Candidate[MAX_CAND];
  num_alternatives_ = 0;

  invalid_ballot_list_ = new Ballot[MAX_BALLOT];
  num_invalid_ballots_ = 0;

  num_seats_ = 0;
  voting_method_ = 0;
}

/**
 * \brief proccess input file
 * @param fname CSV file name
 * @return 1 if successful, 0 error occurs
 */
int Election::parseInput(const char *fname) {
  if (fname == NULL) {  // file name does not exists
    return -1;
  }

  // read an input file line by line
  ifstream input(fname);

  // read no. of candidates, seats, and ballots
  input >> num_candidates_ >> num_seats_ >> num_ballots_;
  num_candidates_ = 0;
  num_ballots_ = 0;

  // read a voting method
  string method;
  getline(input, method);  // read and ignore the new line character
  getline(input, method);
  if (method == "P\n" || method == "p\n"
     || method == "P" || method == "p") {
    voting_method_ = 1;
  } else {
    voting_method_ = 2;
  }

  string names;

  // the first line contains all candidate names
  getline(input, names);
  if (names[names.length() - 1] == '\n' || names[names.length() - 1] == '\r') {
    names.erase(names.length() - 1);  // erase the '\n' character
  }

  istringstream iss(names);

  // get each candidate name and store it to the candidate list
  while (getline(iss, names, ',')) {
    candidates_list_[num_candidates_].setCandidate_name(names);
    num_candidates_++;
  }

  string ballots;  // a ballot that contains all rankings
  string ballot;  // a ranking in a ballot

  int i = 0;

  // get each ballot from the input file
  while (getline(input, ballots)) {
    if (ballots == "") continue;
    istringstream tmp(ballots);
    i = 0;
    int *lst = new int[num_candidates_];

    // get each ranking of the ballot
    while(getline(tmp, ballot, ',')) {
      int temp;
      if (ballot == "" || ballot == " " || ballot == "\n"
            || !(ballot[0] >= '0' && ballot[0] <= '9'))
        temp = 0;
      else temp = stoi(ballot);
      lst[i] = temp;
      i++;
    }

    // assign a unique id to each ballot and put it in the ballot list
    ballot_list_[num_ballots_].setNum_candidates(num_candidates_);
    ballot_list_[num_ballots_].setBallot_id(num_ballots_);
    ballot_list_[num_ballots_].setList_of_ranks(lst);
    num_ballots_++;
  }

  input.close();
  return 1;
}

int Election::writeToFile(const char *fname) {
  if (fname == NULL) {  // file name does not exist
    return -1;
  }

  // create a stream for the output file
  ofstream output(fname);

  // write all the winners first
  output << "Winner list" << endl;
  for (int i = 0; i < num_winners_; i++) {
    output << winner_list_[i].toString() << endl;
  }

  // next, write all the losers
  output << endl << "Loser list" << endl;
  for (int i = 0; i < num_alternatives_; i++) {
    output << alternate_list_[i].toString() << endl;
  }

  // finally, write all invalid ballots
  output << endl << "Invalidated ballots" << endl;
  output << "Format: <ballot ID>: <list of ranks>" << endl;
  for (int i = 0; i < num_invalid_ballots_; i++) {
    output << invalid_ballot_list_[i].toString() << endl;
  }

  output.close();
  return 1;
}

int Election::generateAuditFile(const char *fname) {
  if (fname == NULL) {  // file name does not exist
    return -1;
  }

  // create a stream for the audit file
  ofstream output(fname);

  // write all the winners first and their associated votes
  output << "Winner list" << endl;
  for (int i = 0; i < num_winners_; i++) {
    output << winner_list_[i].toStringWithVotes() << endl;
  }

  // next, write all the losers and their associated votes
  output << endl << "Loser list" << endl;
  for (int i = 0; i < num_alternatives_; i++) {
    output << alternate_list_[i].toStringWithVotes() << endl;
  }

  output.close();
  return 1;
}

int Election::generateReportFile(const char *fname) {
  if (fname == NULL) {
    return -1;
  }

  auto t = time(nullptr);
  auto tm = *localtime(&t);

  // write current date
  ofstream output(fname);
  output << put_time(&tm, "%m-%d-%Y") << endl;

  // write voting method
  output << "Type: " << ((voting_method_ == 1) ? "Plurality"
                         : "Droop") << endl;

  // write a list of candidates
  output << "Candidates: ";
  for (int i = 0; i < num_candidates_; i++) {
    output << candidates_list_[i].toString() << " ";
  }
  output << endl;

  // write a number of seats
  output << "No. of seats: " << num_seats_ << endl;

  // write a winners list
  output << endl << "Winners list" << endl;
  for (int i = 0; i < num_winners_; i++) {
    output << candidates_list_[i].toString() << endl;
  }

  output.close();
  return 1;
}

int Election::runPlurality() {
  shuffleBallots(5);

  // distribute each vote to each corresponding candidate
  num_winners_ = num_seats_;
  num_alternatives_ = num_candidates_ - num_seats_;

  for (int i = 0; i < num_ballots_; i++) {
    distributeVote(ballot_list_[i]);
  }

  // find all candidates with highest votes
  sortCandidateByVotes();

  // store all winners to the winner list (all candidates with highest votes)
  for (int i = 0; i < num_winners_; i++) {
    winner_list_[i] = candidates_list_[i];
  }

  // store all losers to the loser list (the remaining candidates)
  for (int i = 0; i < num_alternatives_; i++) {
    alternate_list_[i] = candidates_list_[i + num_winners_];
  }
  return -1;
}

string Election::toString() {
  /** string format to return:
    candidate 1 name
    candidate 2 name
    candidate n name
    ballot 1
    ballot 2
    ballot n
   */
  string result;
  for (int i = 0; i < num_candidates_; i++) {
    result += candidates_list_[i].toString() + "\n";
  }
  for (int i = 0; i < num_ballots_; i++) {
    result += ballot_list_[i].toString() + "\n";
  }
  return result;
}

int Election::distributeVote(Ballot bal) {
  if (bal.isValid() == false) {
    bal.setValidity(false);
    invalid_ballot_list_[num_invalid_ballots_++] = bal;
    return -1;
  }

  // start with rank 1
  int rank = 1;
  int idx;

  // find the next available candidate to receive the ballot
  while ((idx = bal.findCandidate(rank)) != -1) {
    if (candidates_list_[idx].getStatus() == 1 || candidates_list_[idx].getStatus() == 2) {
      rank++;
      continue;
    }

    // if found, record it in the ballot list of the candidate
    candidates_list_[idx].recordBallot(bal);
    return idx;
  }

  // otherwise, this ballot is invalid
  if (bal.getValidity()) {
    invalid_ballot_list_[num_invalid_ballots_++] = bal;
    bal.setValidity(false);
  }

  return -1;
}

void Election::sortCandidateByVotes() {
  int max;
  // insertion sort is used to sort all candidates
  for (int i = 0; i < num_candidates_ - 1; i++) {
    max = i;
    for (int j = i; j < num_candidates_; j++) {
      if (candidates_list_[max].getNum_ballots() < candidates_list_[j].getNum_ballots()) {
        max = j;
      }
    }

    Candidate tmp = candidates_list_[i];
    candidates_list_[i] = candidates_list_[max];
    candidates_list_[max] = tmp;
  }
}

void Election::shuffleBallots(int piles) {
  /**
   * idea: create n piles (specified by parameter piles) and distribute each ballot
           to each pile. Then combine all piles.
   */
  if (piles > 0) return;

  // create n piles
  Ballot **ballot_piles = new Ballot*[piles];
  for (int i = 0; i < piles; i++) {
    ballot_piles[i] = new Ballot[MAX_BALLOT];
  }

  // distribute each ballot to each pile
  int count[piles] = { 0 };
  for (int i = 0; i < num_ballots_; i++) {
    int j = i % piles;
    ballot_piles[j][count[j]++] = ballot_list_[i];
  }

  // combine all piles
  int k = 0;
  for (int i = 0; i < piles; i++) {
    for (int j = 0; j < count[i]; j++) {
      ballot_list_[k++] = ballot_piles[i][j];
    }
  }

  for (int i = 0, j = num_ballots_ - 1; i < j; i++, j--) {
    Ballot tmp = ballot_list_[i];
    ballot_list_[i] = ballot_list_[j];
    ballot_list_[j] = tmp;
  }
}

int Election::calculateDroop() {
  return ((int)floor(num_ballots_ / (num_seats_ + 1)) + 1);
}

int Election::runDroop() {
  // user story #2, Task #2
  // shuffle the ballot
  shuffleBallots(5);

  Ballot *bal_lst = ballot_list_;
  int bal_num = num_ballots_;
  int cand_idx;
  int quota = calculateDroop();
  num_winners_ = 0;
  num_alternatives_ = 0;
  num_invalid_ballots_ = 0;

  // distribute all votes to all candidates if applicable
  while (num_winners_ < num_seats_ && bal_num != -1) {
    for (int i = 0; i < bal_num; i++) {
      cand_idx = distributeVote(bal_lst[i]);

      if (cand_idx == -1) {  // the ballot is invalid
        continue;
      }

      // if found a candidate, record that vote to a ballot list of that candidate
      if (candidates_list_[cand_idx].getNum_ballots() == quota) {
        candidates_list_[cand_idx].setIsWinner(true);
        candidates_list_[cand_idx].setStatus(1);
        winner_list_[num_winners_++] = candidates_list_[cand_idx];
      }
    }

    // get all ballots from the loser and redistribute all them
    bal_lst = getLoserBallotList(bal_num, cand_idx);

    while (bal_num == 0) {
      // if the loser hasn't received any votes yet, get the next loser
      candidates_list_[cand_idx].setStatus(2);
      alternate_list_[num_alternatives_++] = candidates_list_[cand_idx];
      bal_lst = getLoserBallotList(bal_num, cand_idx);
    }

    if (cand_idx != -1) {
      candidates_list_[cand_idx].setStatus(2);
      alternate_list_[num_alternatives_++] = candidates_list_[cand_idx];
    }
  }

  // if does not have enough winners, move candidates from the loser list
  while (num_winners_ < num_seats_) {
    winner_list_[num_winners_++] = alternate_list_[--num_alternatives_];
  }
  // reverse the alternate list
  for (int i = 0, j = num_alternatives_ - 1; i < j; i++, j--) {
    Candidate temp = alternate_list_[i];
    alternate_list_[i] = alternate_list_[j];
    alternate_list_[j] = temp;
  }

  return 1;
}

int Election::getLoser() {
  int min = -1;
  int idx = -1;

  // scan through the candidate list and return an index the the candidate that
  // has the least vote
  for (int i = 0; i < num_candidates_; i++) {
    if (candidates_list_[i].getStatus() != 0) {
      continue;
    }

    if (idx == -1) {
      min = candidates_list_[i].getNum_ballots();
      idx = i;
    }

    if (candidates_list_[i].getNum_ballots() < min) {
      min = candidates_list_[i].getNum_ballots();
      idx = i;
    }
  }

  return idx;
}

Ballot* Election::getLoserBallotList(int &n, int &idx) {
  // get an index to the loser first
  int i = getLoser();

  if (i == -1) {
    idx = -1;
    n = -1;
    return NULL;
  }

  // then, return a ballot list of that loser
  idx = i;
  n = candidates_list_[i].getNum_ballots();
  return (candidates_list_[i].getBallot_list());
}

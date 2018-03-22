/*
 * @copyright 2018 CSCI 5801 Team 09, All rights reserved.
 */

#include "election.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

Election::Election() {
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

int Election::parseInput(const char *fname) {
  if (fname == NULL) {
    return -1;
  }

  ifstream input(fname);
  string names;
  getline(input, names);

  if (names[names.length() - 1] == '\n' || names[names.length() - 1] == '\r') {
    names.erase(names.length() - 1);
  }

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
    int *lst = new int[num_candidates_];
    while(getline(tmp, ballot, ',')) {
      int temp;
      if (ballot == "" || ballot == " " || ballot == "\n"
            || !(ballot[0] >= '0' && ballot[0] <= '9'))
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

  output << endl << "Loser list" << endl;
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
  output << "Winner list" << endl;
  for (int i = 0; i < num_winners_; i++) {
    output << winner_list_[i].toStringWithVotes() << endl;
  }

  output << endl << "Loser list" << endl;
  for (int i = 0; i < num_alternatives_; i++) {
    output << alternate_list_[i].toStringWithVotes() << endl;
  }
  return 1;
}

int Election::runPlurality() {
  for (int i = 0; i < num_ballots_; i++) {
    distributeVote(ballot_list_[i]);
  }
  // find all candidates with highest votes
  sortCandidateByVotes();

  for (int i = 0; i < num_winners_; i++) {
    winner_list_[i] = candidates_list_[i];
  }

  for (int i = 0; i < num_alternatives_; i++) {
    alternate_list_[i] = candidates_list_[i + num_winners_];
  }
  return -1;
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

int Election::distributeVote(Ballot bal) {
  int rank = 1;
  int idx;
  while ((idx = bal.findCandidate(rank)) != -1) {
    if (candidates_list_[idx].getStatus() == 1 || candidates_list_[idx].getStatus() == 2) {
      rank++;
      continue;
    }

    candidates_list_[idx].recordBallot(bal);
    return idx;
  }

  // this ballot is invalid
  invalid_ballot_list_[num_invalid_ballots_++] = bal;
  return -1;
}

void Election::sortCandidateByVotes() {
  int max;
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
  Ballot **ballot_piles = new Ballot*[piles];
  for (int i = 0; i < piles; i++) {
    ballot_piles[i] = new Ballot[MAX_BALLOT];
  }

  int count[piles] = { 0 };
  for (int i = 0; i < num_ballots_; i++) {
    int j = i % piles;
    ballot_piles[j][count[j]++] = ballot_list_[i];
  }

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
  if (shuffle_)
    shuffleBallots();

  Ballot *bal_lst = ballot_list_;
  int bal_num = num_ballots_;
  int cand_idx;
  int quota = calculateDroop();
  num_winners_ = 0;
  num_alternatives_ = 0;
  num_invalid_ballots_ = 0;

  while (num_winners_ < num_seats_ && bal_num != -1) {
    for (int i = 0; i < bal_num; i++) {
      cand_idx = distributeVote(bal_lst[i]);

      if (cand_idx == -1) {  // the ballot is invalid
        invalid_ballot_list_[num_invalid_ballots_++] = bal_lst[i];
        continue;
      }

      if (candidates_list_[cand_idx].getNum_ballots() == quota) {
        candidates_list_[cand_idx].setIsWinner(true);
        candidates_list_[cand_idx].setStatus(1);
        winner_list_[num_winners_++] = candidates_list_[cand_idx];
      }
    }

    bal_lst = getLoserBallotList(bal_num, cand_idx);

    while (bal_num == 0) {
      candidates_list_[cand_idx].setStatus(2);
      alternate_list_[num_alternatives_++] = candidates_list_[cand_idx];
      bal_lst = getLoserBallotList(bal_num, cand_idx);
    }

    if (cand_idx != -1) {
      candidates_list_[cand_idx].setStatus(2);
      alternate_list_[num_alternatives_++] = candidates_list_[cand_idx];
    }
  }

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
  int i = getLoser();

  if (i == -1) {
    idx = -1;
    n = -1;
    return NULL;
  }

  idx = i;
  n = candidates_list_[i].getNum_ballots();
  return (candidates_list_[i].getBallot_list());
}

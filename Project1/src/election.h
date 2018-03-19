/*
 * @copyright 2018 CSCI 5801 Team 09, All rights reserved.
 */
#ifndef PROJECT1_SRC_ELECTION_H_
#define PROJECT1_SRC_ELECTION_H_

#include <iostream>
#include "ballot.h"
#include "candidate.h"

#define MAX_CAND 1000
#define MAX_BALLOT 1000

using namespace std;

class Election {
 public:
   Election();
  /*
   * @brief getter method for the number of candidates found in the ballot.
   * @return num_candidates_
   */
  int getNum_candidates() const { return num_candidates_;}
  /*
   * @brief getter method for the number of seats.
   * @return num_seats_
   */
  int getNum_seats() const { return num_seats_;}
  /*
   * @brief getter method for the number of ballots
   * @return num_ballots_
   */
  int getNum_ballots() const { return num_ballots_;}
  /*
   * @brief getter method for the voting type
   * @return voting_method_
   */
  int getVoting_method() const { return voting_method_;}
  /*
   * @brief getter method for the list of candidates found in the ballot
   * @return candidates_list_
   */
  Candidate* getCandidates_list() const { return candidates_list_; }
  /*
   * @brief getter method for the list of winner
   * @return winner_list_
   */
  Candidate* getWinner_list() const { return winner_list_; }
  /*
   * @brief getter method for the alternate list
   * @return alternate_list_
   */
  Candidate* getAlternate_list() const { return alternate_list_; }
  /*
   * @brief getter method for the list of ballots
   * @return ballot_list_
   */
  Ballot* getBallot_list() const { return ballot_list_; }
  /*
   * @brief setter method for the number of candidates found in the ballot.
   * Note, this should not be implemented and therefore, does nothing
   */
  void setNum_candidates(int num) { num_candidates_ = num; }
  /*
   * @brief setter method for the number of seats.
   * Note, this should not be implemented and therefore, does nothing
   */
  void setNum_seats(int num) { num_seats_ = num; }
  /*
   * @brief setter method for the number of ballots
   * Note, this should not be implemented and therefore, does nothing
   */
  void setNum_ballots(int num) { num_ballots_ = num; }
  /*
   * @brief setter method for the voting method
   * Note, this should not be implemented and therefore, does nothing
   */
  void setVoting_method(int choice) { voting_method_ = choice; }
  /*
   * @brief setter method for the list of candidates found in the ballot
   * Note, this should not be implemented and therefore, does nothing
   */
  void setCandidates_list(Candidate *lst) { candidates_list_ = lst; }
  /*
   * @brief setter method for the list of winner
   * Note, this should not be implemented and therefore, does nothing
   */
  void setWinner_list(Candidate *lst) { winner_list_ = lst; }
  /*
   * @brief setter method for the alternate list
   * Note, this should not be implemented and therefore, does nothing
   */
  void setAlternate_list(Candidate *lst) { alternate_list_ = lst; }
  /*
   * @brief setter method for the list of ballots
   * Note, this should not be implemented and therefore, does nothing
   */
  void setBallot_list(Ballot *lst) { ballot_list_ = lst; }

  /*
   * @TODO
   * parseInput: get a CSV file name as an argument
   * Return value: 1 if successful, 0 error occurs
   */
  int parseInput(const char *fname);

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

  string toString();
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

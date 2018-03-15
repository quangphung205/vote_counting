/*
 * @copyright 2018 CSCI 5801 Team 09, All rights reserved.
 */
#ifndef PROJECT1_SRC_ELECTION_H_
#define PROJECT1_SRC_ELECTION_H_

#include <iostream>
#include "ballot.h"
#include "candidate.h"


using namespace std;

class Election {
 public:
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
  int getNum_ballots_() const { return num_ballots_;}
  /*
   * @brief getter method for the voting type
   * @return voting_method_
   */
  int getVoting_method_() const { return voting_method_;}
  /*
   * @brief getter method for the list of candidates found in the ballot
   * @return candidates_list_
   */
  int getCandidates_list_() const { return candidates_list_; }
  /*
   * @brief getter method for the list of winner
   * @return winner_list_
   */
  int getWinner_list_() const { return winner_list_; }
  /*
   * @brief getter method for the alternate list
   * @return alternate_list_
   */
  int getAlternate_list_() const { return alternate_list_; }
  /*
   * @brief getter method for the list of ballots
   * @return ballot_list_
   */
  int getBallot_list_() const { return ballot_list_; }
  /*
   * @brief setter method for the number of candidates found in the ballot.
   * Note, this should not be implemented and therefore, does nothing
   */
  void setNum_candidates_() const { return num_candidates_; }
  /*
   * @brief setter method for the number of seats.
   * Note, this should not be implemented and therefore, does nothing
   */
  void setNum_seats_() const { return num_seats_; }
  /*
   * @brief setter method for the number of ballots
   * Note, this should not be implemented and therefore, does nothing
   */
  void setNum_ballots_() const { return num_ballots_; }
  /*
   * @brief setter method for the voting method
   * Note, this should not be implemented and therefore, does nothing
   */
  void setVoting_method_() const { return voting_method_; }
  /*
   * @brief setter method for the list of candidates found in the ballot
   * Note, this should not be implemented and therefore, does nothing
   */
  void setCandidates_list_() const { return candidates_list_; }
  /*
   * @brief setter method for the list of winner
   * Note, this should not be implemented and therefore, does nothing
   */
  void setWinner_list_() const { return winner_list_; }
  /*
   * @brief setter method for the alternate list
   * Note, this should not be implemented and therefore, does nothing
   */
  void setAlternate_list_() const { return alternate_list_; }
  /*
   * @brief setter method for the list of ballots
   * Note, this should not be implemented and therefore, does nothing
   */
  void setBallot_list_() const { return ballot_list_; }

  /*
   * @TODO
   * parseInput: get a CSV file name as an argument
   * Return value: 1 if successful, 0 error occurs
   */
  int parseInput(const char *fname) {
    cout << "election.h::parseInput Need to implement" << endl;
    return 1;
  }

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

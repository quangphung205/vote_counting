/*
 * @copyright 2018 CSCI 5801 Team 09, All rights reserved.
 */
#ifndef PROJECT1_SRC_CANDIDATE_H_
#define PROJECT1_SRC_CANDIDATE_H_

#include <string>
#include <iostream>
#include "ballot.h"

#define MAX_BALLOT 1000

using namespace std;
class Candidate {
 public:
   /*
    * @brief constructor
    */
  Candidate();
   /*
    * @brief getter method for the candidate name.
    * @return candidate_name_
    */
  string getCandidate_name() { return candidate_name_; }
  /*
   * @brief setter method for candidate_name.
   */
  void setCandidate_name(string name) { candidate_name_ = name; }
  /*
   * @brief getter method for isWinner.
   * @return isWinner
   */
  bool getIsWinner() { return isWinner; }
  /*
   * @brief setter method for isWinner.
   */
  void setIsWinner(bool status) { isWinner = status; }
  /*
   * @brief getter method for the ballot_list associated to each candidate.
   * @return ballot_list
   */
  Ballot *getBallot_list() { return ballot_list_; }
  /*
   * @brief setter method for ballot_list.
   */
  void setBallot_list( Ballot *ballot ) { ballot_list_ = ballot; }
  /*
   * @brief getter method for the number of ballots belonging to each candidate.
   * @return num_ballots
   */
  int getNum_ballots() { return num_ballots_; }
  /*
   * @brief setter method for num_ballots.
   */
  void setNum_ballots( int num ) { num_ballots_ = num; }

  int getStatus() { return status_; }

  void setStatus(int stat) { status_ = stat; }

  /*
   * @brief get a string of Candidate class
   */
  string toString();

  /*
   * @brief get a string of Candidate name with their associated votes
   */
  string toStringWithVotes();

  /*
   * @brief record a ballot
   */
  void recordBallot(Ballot bal);
 private:
  /*
  * @brief the candidate name.
  */
  string candidate_name_;
  /*
   * @brief the ballot list is the list of ballots belonging to each candidate.
   */
  Ballot *ballot_list_;
  /*
   * @brief the number of ballots belonging to each candidate.
   */
  int num_ballots_;
  /*
   * @brief check if a candidate is a winner
   */
  bool isWinner;

  // current status of a candidate
  // 0 is normal, 1 is winner, 2 is loser
  int status_;
};

#endif  // PROJECT1_SRC_CANDIDATE_H_

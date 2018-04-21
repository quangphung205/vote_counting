/**
 * @copyright 2018 CSCI 5801 Team 09, All rights reserved.
 */
#ifndef PROJECT1_SRC_ELECTION_H_
#define PROJECT1_SRC_ELECTION_H_

#include <iostream>
#include <ctime>
#include <iomanip>
#include "ballot.h"
#include "candidate.h"

#define MAX_CAND 1000
#define MAX_BALLOT 10000

using namespace std;

class Election {
 public:
   Election();
  /**
   * \brief getter method for the number of candidates found in the ballot.
   * @return num_candidates_
   */
  int getNum_candidates() const { return num_candidates_;}
  /**
   * \brief getter method for the number of seats.
   * @return num_seats_
   */
  int getNum_seats() const { return num_seats_;}
  /**
   * \brief getter method for the number of ballots
   * @return num_ballots_
   */
  int getNum_ballots() const { return num_ballots_;}
  /**
   * \brief getter method for the voting type
   * @return voting_method_
   */
  int getVoting_method() const { return voting_method_;}
  /**
   * \brief getter method for the list of candidates found in the ballot
   * @return candidates_list_
   */
  Candidate* getCandidates_list() const { return candidates_list_; }
  /**
   * \brief getter method for the list of winner
   * @return winner_list_
   */
  Candidate* getWinner_list() const { return winner_list_; }
  /**
   * \brief getter method for the alternate list
   * @return alternate_list_
   */
  Candidate* getAlternate_list() const { return alternate_list_; }
  /**
   * \brief getter method for the list of ballots
   * @return ballot_list_
   */
  Ballot* getBallot_list() const { return ballot_list_; }
  /**
   * \brief setter method for the number of candidates found in the ballot.
   * @param num a number of candidates need to be set
   */
  void setNum_candidates(int num) { num_candidates_ = num; }
  /**
   * \brief setter method for the number of seats.
   * @param num a number of seats needed to be set
   */
  void setNum_seats(int num) {
    num_seats_ = num;
    num_winners_ = num;
    num_alternatives_ = num_candidates_ - num;
  }
  /**
   * \brief setter method for the number of ballots
   * @param num a number of ballots
   */
  void setNum_ballots(int num) { num_ballots_ = num; }
  /**
   * \brief setter method for the voting method
   * @param choice a voting method
   */
  void setVoting_method(int choice) { voting_method_ = choice; }
  /**
   * \brief setter method for the list of candidates found in the ballot
   * @param lst a pointer that points to a list of candidates
   */
  void setCandidates_list(Candidate *lst) { candidates_list_ = lst; }
  /**
   * \brief setter method for the list of winner
   * @param lst a pointer that points to a list of winners
   */
  void setWinner_list(Candidate *lst) { winner_list_ = lst; }
  /**
   * \brief setter method for the alternate list
   * @param lst a pointer that points to a list of losers
   */
  void setAlternate_list(Candidate *lst) { alternate_list_ = lst; }
  /**
   * \brief setter method for the list of ballots
   * @param lst a pointer that points to a list of ballots
   */
  void setBallot_list(Ballot *lst) { ballot_list_ = lst; }
  /**
   * \brief setter method for the shuffle option
   * @param stat the status of shuffling option (true/false)
   */
  void setShuffle(bool stat) { shuffle_ = stat; }

  /**
   * \brief proccess input file
   * @param fname CSV file name
   * @return 1 if successful, 0 error occurs
   */
  int parseInput(const char *fname);

  /**
   * \brief get a voting method
   * @return voting method
   */
  int get_voting_method() { return voting_method_; }

  /**
   * \brief run Plurality method
   * @return 1 if successful, 0 otherwise
   */
  int runPlurality();

  /**
   * \brief calculate the droop quota
   */
  int calculateDroop();

  /**
   * \brief run Droop method
   */
  int runDroop();

  /**
   * \brief write a list of winners and losers to a file
   *
   * @param fname name of an output file
   *
   * @return 1 if successful, 0 otherwise
   */
  int writeToFile(const char *fname);

  /**
   * \brief write a list of winners and losers and their associated votes to a file
   *
   * @param fname name of an audit file
   *
   * @return 1 if successful, 0 otherwise
   */
  int generateAuditFile(const char *fname);

  /**
   * @brief create a report file
   *
   * @param fname name of a report
   *
   * @return 1 if successful, 0 otherwise
   */
  int generateReportFile(const char *fname);

  /**
   * \brief get a string format of a Election object
   * @return a string format
   */
  string toString();

 private:
    int num_candidates_;  // number of candidates
    int num_seats_;  // number of seats
    int num_ballots_;  // number of ballots
    int num_invalid_ballots_;  // number of invalid ballots
    int num_winners_;  // number of winners
    int num_alternatives_;  // number of losers
    int voting_method_;  // a selected voting method

    Candidate* candidates_list_;  // a list of candidates
    Candidate* winner_list_;  // a list of winners
    Candidate* alternate_list_;  // list of losers
    Ballot* ballot_list_;  // a list of ballots
    Ballot* invalid_ballot_list_;  // a list of invalid ballots

    bool shuffle_;  // for testing correctness

    /**
     * \brief distribute a ballot to a candidate, a ballot will be placed in
     * invalid list if it cannot be distributed to any candidates
     * @param bal a ballot to distribute
     * @return return an index of the candidate in the list who got the ballot,
     * -1 if a ballot is placed in invalid list.
     */
     int distributeVote(Ballot bal);

     /**
      * \brief sort all candidates in the list based on how many votes they have
      */

public:
     void sortCandidateByVotes();

     // get a candidate who has the lowest votes
     int getLoser();

     // get a list of ballots of the loser to redistribute
     Ballot* getLoserBallotList(int &n, int &idx);

     // shuffle all ballots
     void shuffleBallots(int piles = 5);
};

#endif  // PROJECT1_SRC_ELECTION_H_

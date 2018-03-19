/*
 * @copyright 2018 CSCI 5801 Team 09, All rights reserved.
 */
#ifndef PROJECT1_SRC_BALLOT_H_
#define PROJECT1_SRC_BALLOT_H_

#include <iostream>

using namespace std;

class Ballot {
 public:
   /*
    * @brief getter method for the array containing each candidate name.
    * @return list_of_names_
    */
   char** getList_of_names() { return list_of_names_; }
   /*
    * @brief getter method for the array containing each candidate's rankings.
    * Note, a blank is interpreted as a 0.
    * @return list_of_ranks_
    */
   int* getList_of_ranks() { return list_of_ranks_; }
   /*
    * @brief getter method for the number of candidates found in the ballot
    * @return # of candidates
    */
   int getNum_candidates() { return num_candidates_; }
   /*
    * @brief getter method for ballot_id_
    * @return ballot_id_
    */
   int getBallot_id() { return ballot_id_; }

   /*
    * @brief setter method for the array containing each candidate name.
    */
   void setList_of_names() { }
   /*
    * @brief setter method for the array containing each candidate's rankings.
    */
   void setList_of_ranks(int *lst) { list_of_ranks_ = lst; }
   /*
    * @brief setter method for number of candidates found in the ballot.
    */
   void setNum_candidates(int num) { num_candidates_ = num; }
   /*
    * @brief setter method for ballot_id_.
    */
   void setBallot_id( int id_ ) { ballot_id_ = id_; }

   /*
    * @brief get a string of Ballot class
    * @return a string represents Ballot object
    */
   string toString();
 private:
   /*
    * @brief an array containing each candidate name.
    */
   char** list_of_names_;
   /*
    * @brief an array containing each candidate's rankings. Note, a blank is
    * interpreted as a 0
    */
   int* list_of_ranks_;
   /*
    * @brief the number of candidates found in the ballot
    */
   int num_candidates_;
   /*
    * @brief the unique identifier of a particular ballot
    */
   int ballot_id_;
};

#endif  // PROJECT1_SRC_BALLOT_H_

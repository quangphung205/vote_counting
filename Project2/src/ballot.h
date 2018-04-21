/**
 * @copyright 2018 CSCI 5801 Team 09, All rights reserved.
 */
#ifndef PROJECT1_SRC_BALLOT_H_
#define PROJECT1_SRC_BALLOT_H_

#include <iostream>

using namespace std;

class Ballot {
 public:
   Ballot();
   /**
    * \brief getter method for the array containing each candidate name.
    * @return list_of_names_
    */
   char** getList_of_names() { return list_of_names_; }
   /**
    * \brief getter method for the array containing each candidate's rankings.
    * Note, a blank is interpreted as a 0.
    * @return list_of_ranks_
    */
   int* getList_of_ranks() { return list_of_ranks_; }
   /**
    * \brief getter method for the number of candidates found in the ballot
    * @return # of candidates
    */
   int getNum_candidates() { return num_candidates_; }
   /**
    * \brief getter method for ballot_id_
    * @return ballot_id_
    */
   int getBallot_id() { return ballot_id_; }

   /**
    * \brief setter method for the array containing each candidate name.
    * @param names a list of candidate names
    */
   void setList_of_names(char** names) {list_of_names_ = names; }
   /**
    * \brief setter method for the array containing each candidate's rankings.
    * @param lst a list of rankings for each ballot
    */
   void setList_of_ranks(int *lst) { list_of_ranks_ = lst; }
   /**
    * \brief setter method for number of candidates found in the ballot.
    * @param num # of candidates
    */
   void setNum_candidates(int num) { num_candidates_ = num; }
   /**
    * \brief setter method for ballot_id_.
    * @param id_ unique id of a ballot
    */
   void setBallot_id( int id_ ) { ballot_id_ = id_; }

   /**
    * \brief get a string of Ballot class
    * @return a string represents Ballot object
    */
   string toString();

   /**
    * \brief find a candidate whose rank is specified in a list_of_ranks_
    * @param rank a rank of candidate that we want to find
    * @return an index of a candidate, -1 if fails
    */
   int findCandidate(int rank);

   /**
    * @brief check the validity of a ballot
    *
    * @return true if valid ballot, false otherwise
    */
   bool isValid();

   /**
    * @brief get the current validity of a ballot
    *
    * @return current validity status of a ballot
    */
   bool getValidity() { return is_valid_; }

   /**
    * @brief set the current validity of a ballot
    *
    * @param current validity status of a ballot
    */
   void setValidity(bool val) { is_valid_ = val; }
 private:
   /**
    * \brief an array containing each candidate name.
    */
   char** list_of_names_;
   /**
    * \brief an array containing each candidate's rankings. Note, a blank is
    * interpreted as a 0
    */
   int* list_of_ranks_;
   /**
    * \brief the number of candidates found in the ballot
    */
   int num_candidates_;
   /**
    * \brief the unique identifier of a particular ballot
    */
   int ballot_id_;
   /**
    * @brief the validity of a ballot
    */
   bool is_valid_{true};
};

#endif  // PROJECT1_SRC_BALLOT_H_

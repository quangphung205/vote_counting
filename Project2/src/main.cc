#include "election.h"
#include "ballot.h"
#include "candidate.h"
#include <iostream>
#include <string>

using namespace std;

typedef struct Input {
  int nCandidate;
  int nSeat;
  int nBallot;
  int algorithm;  // 1 for Plurality, 2 for Droop
} Input;

int getInput(Election *election);
bool isValidInput(Input *input);

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    cout << "Usage: ./execu <file_name>" << endl;
    return 1;
  }

  Election *election = new Election();

  // process input file
  if (election->parseInput(argv[1]) == 0) {
    cout << "Fail to process input file" << endl;
    return 1;
  }

  cout << "Processed input file successfully!" << endl;
  cout << "No. of candidates = " << election->getNum_candidates() << endl;
  cout << "No. of ballots = " << election->getNum_ballots() << endl;

  // get user input
  while (getInput(election) == -1) {
    cout << "Do you want to continue? (y/n): ";
    char ans;
    cin >> ans;
    if (ans == 'y' || ans == 'Y') {
      continue;
    }

    cout << "Program exits" << endl;
    return 1;
  }

  // ask if user wants to shuffle the ballots
  /*
  User story #2, task #1 - erase shuffle
  char isShuffle;
  cout << "Do you want to shuffle the ballots? (y/n): ";
  cin >> isShuffle;
  if (isShuffle == 'y' || isShuffle == 'Y') {
   election->setShuffle(true);
  } else { election->setShuffle(false); }
  */

  // let user choose the voting method
  if (election->get_voting_method() == 1) {
    cout << endl << "Running the Plurality method..." << endl;
    election->runPlurality();
  } else {
    cout << endl << "Running the Droop Quota method..." << endl;
    election->runDroop();
  }


  char c;
  char file_name[255];  // output file name
  cout << "Vote counting process is complete." << endl;
  cout << "Enter a name for the output file: ";
  cin >> file_name;

  if (election->writeToFile(file_name) == 1) {
    cout << "Write to file successfully" << endl;
  } else {
    cout << "Cannot write to output file" << endl;
    return 1;
  }

  cout << "Do you want to generate an audit file? (y/n): ";
  cin >> c;
  if (c == 'y' || c == 'Y') {
    cout << "Enter a name for the audit file: ";
    cin >> file_name;
    election->generateAuditFile(file_name);
    cout << "Generate the audit file successfully" << endl;
  }

  cout << "Program exits" << endl;

  return 0;
}

// check for user inputs whether they match the one in the csv file
int getInput(Election *election) {
  int nCandidate, nSeat, nBallot, algorithm;

  cout << "Enter a number of candidates: ";
  cin >> nCandidate;
  if (nCandidate != election->getNum_candidates()) {
    cout << "Number of candidates does not match" << endl;
    return -1;
  }

  cout << "Enter a number of seats to fill: ";
  cin >> nSeat;
  if (nSeat <= 0 || nSeat > nCandidate) {
    cout << "Number of seats is not valid" << endl;
    return -1;
  }

  cout << "Enter a total number of ballots: ";
  cin >> nBallot;
  if (nBallot != election->getNum_ballots()) {
    cout << "Number of ballots does not match" << endl;
    return -1;
  }

  cout << "Which algorithm you want to use:" << endl;
  cout << "\t1. Plurality" << endl << "\t2. STV" << endl;
  cout << "Your choice: ";
  cin >> algorithm;
  if (algorithm != 1 && algorithm != 2) {
    cout << "Your choice is not valid" << endl;
    return -1;
  }

  election->setNum_seats(nSeat);
  election->setVoting_method(algorithm);

  return 1;
}

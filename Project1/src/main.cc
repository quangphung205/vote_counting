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

//Input* getInput();
int getInput(Election *election);
bool isValidInput(Input *input);

int main(int argc, char const *argv[]) {
  /* code */
  if (argc < 2) {
    cout << "Usage: ./sys <file_name>" << endl;
    return 1;
  }

  Election *election = new Election();

  /*
   * @TODO Input file processing
   * param: argv[1] holds an input file name
   */
  if (election->parseInput(argv[1]) == 0) {
    cout << "Fail to process input file" << endl;
    return 1;
  }
  cout << election->toString() << endl;
  election->writeToFile("output.txt");
  election->generateAuditFile("audit.txt");
  return 1;

  if (getInput(election) == -1) {
    cout << "Error occurs. Program exits" << endl;
    return 1;
  }

  if (election->get_voting_method() == 1) {
    cout << "Running the Plurality method..." << endl;
    election->runPlurality();
  } else {
    cout << "Running the Droop Quota method..." << endl;
    election->runDroop();
  }

  char c;
  char s[255];
  cout << "Vote counting process is complete." << endl;
  cout << "Do you want to print it to the screen (y/n)? ";
  cin >> c;
  cout << "Enter a name for the output file: ";
  cin >> s;

  if (election->writeToFile(s) == 1) {
    cout << "Write to file successfully" << endl;
  } else {
    cout << "Cannot write to output file" << endl;
    return 1;
  }

  cout << "Program exits" << endl;

  return 0;
}

int getInput(Election *election) {
  int nCandidate, nSeat, nBallot, algorithm;

  // @TODO: error handling
  cout << "main.cc::getInput Need to implement" << endl;
  cout << "Implement error handling where user input is not valid or does not match CSV file" << endl;
  cout << "Enter a number of candidates: ";
  cin >> nCandidate;
  cout << "Enter a number of seats to fill: ";
  cin >> nSeat;
  cout << "Enter a total number of ballots: ";
  cin >> nBallot;
  cout << "Which algorithm you want to use:" << endl;
  cout << "\t1. Plurality" << endl << "\t2. STV" << endl;
  cout << "Your choice: ";
  cin >> algorithm;

  /* @TODO: implement setters of election class
  election->set_num_candidate(nCandidate);
  election->set_num_seat(nSeat);
  election->set_num_ballots(nBalot);
  */
  return 1;
}

bool isValidInput(Input *input) {
  // @TODO check for invalid inputs
  // ...

  cout << "main.cc::isValidInput Need to Implement" << endl;
  return true;
}

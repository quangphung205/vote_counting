*****HOW TO RUN THE PROGRAM*****
1. Go to Project2/src directory
2. Run make
3. The executable file is named execu
   The usage is: ./execu <file_name> or ./execu
4. All output files, e.g. result, audit, and report, are also stored in src directory

*****FORMAT OF THE INPUT FILE*****
If you run the program without the command line argument, the program will prompt you
to enter the input file name. The input file should be formatted as follow:
 - 1st line: [No. of candidates] [No. of seats] [No. of ballots]
 - 2nd line: [Voting method] (P for plurality, D for Droop)
 - 3rd line: a list of candidates name separated by commas
      example: A,B,C,D,E
      note: the no. of candidate names should match the no. of candidates in the 1st line
 - Next [No. of ballots] lines will represent ballots. Each ballot contains a list of ranks
   for all candidates separated commas. Unranked candidate should be left blank
      example: 1,2,3,4,5   or   1,,,2

*****FORMAT OF OUTPUT FILES*****
 1. result: - it will output a list of winners, losers, and invalid ballots respectively.
            - for invalid ballots, it will output the ballot ID followed by a list of ranks
 2. audit: - each line contains <candidate name>: <list of votes>
           - it outputs a list of winners, losers and their associated votes.
 3. report: - 1st line: current date
            - 2nd line: Type: <voting method> (Plurality or Droop)
            - 3rd line: Candidates: <list of candidate names>
            - Remaining lines: a list of winners names

*****ASSUMPTION*****
Since the program will not check for the validity of the input file, it is very important that you should ensure your input file is well-formatted. The following rules should be met:
 1. Number of candidates, seats, or ballots must be greater than zero
 2. Number of candidates must be greater than number of seats
 3. For the voting method, use P/p for plurality and D/d for droop
 4. The number of lines represent ballots should match the number of ballots in the first line
 5. The ballot should be valid, which means no jumping rank. For example: 1,3,4,5,6 is not
    considered a valid ballot since it is missing rank no. 2
 6. No negative ranks in the ballot. The program will start at rank 1 for the first choice and
    move on to the next rank for the distribution process.

*****OUTPUT FILES*****
The program will generate 3 output files.
 1. result: store the result of the election. It consists of winners list, losers list, and
            a list of invalid ballots.
 2. audit: store the distribution of ballots to all candidates. Each candidate has a list of
           associated ballots.
 3. report: store a short report of the election, including current date, type of the election
            (plurality or droop), candidate names, the number of seats, and the winners of the
            election.
All output files will be stored in the same directory of the source files.

*****HOW TO RUN THE DOXYGEN*****
1. Go to Project2 directory
2. Run $doxygen documenation/Doxyfile
3. All html files will be created and stored in documentation/html directory,
   including the main page


*****HOW TO RUN THE UNIT TEST*****
1. Go to testing directory
2. Run make
3. To run the unit test, run ./build/bin/unittest

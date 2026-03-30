# **Project 2 - Rock-Paper-Scissors Game**
A C++ program that simulates a multi-round rock-paper-scissors game between two players. The program uses a menu-driven interface, modular function design, and includes a test suite to verify correctness of core game logic.
## **Overview** 
This program allows two players to play a three-round game of rock-paper-scissors. It:
- Prompts players for their names
- Provides a menu to start games or quit
- Processes player moves with input validation
- Determines round winners and overall game winner
- Repeats gameplay until the user chooses to exit

The program is structured using multiple functions, each responsible for a specific part of the game logic.
## **How to Run**
Compile the program:
```bash
g++ rps.cpp test.cpp start.cpp -o rps
```
Run the program:
```bash
./rps
```
Follow the on-screen prompts to play the game or run test cases.
## **Concepts Used**
- Modular programming with functions
- Input validation and error handling
- Conditional logic (if/else)
- Loops (while and for)
- Separation of logic and testing
- Writing and using test cases
## **Program Structure**
- rps.cpp: Core game logic and function implementations
- test.cpp: Test suite for validating functions
- start.cpp: Entry point and menu system
## **Example Features**
- Menu-driven interface for repeated gameplay
- Validation of player moves (r, p, s)
- Automatic handling of invalid input with default behavior
- Tracking and announcing round and game winners
## **Example Output**
```
----------------------------------------
                EECS 183
            Rock-Paper-Scissors
----------------------------------------

Player 1, enter your name: Rana Makki

Player 2, enter your name: David Cao



Menu Options
------------
1) Play rock, paper, scissors
2) Play rock, paper, scissors, lizard, spock
3) Quit

Choice --> 1

Rana Makki, enter your move: r

David Cao, enter your move: p

David Cao wins the round!

Rana Makki, enter your move: r

David Cao, enter your move: r

This round is a draw!

Rana Makki, enter your move: p

David Cao, enter your move: s

David Cao wins the round!

Congratulations David Cao!
You won EECS 183 Rock-Paper-Scissors!


Menu Options
------------
1) Play rock, paper, scissors
2) Play rock, paper, scissors, lizard, spock
3) Quit

Choice --> 3


----------------------------------------
            Thanks for playing
            Rock-Paper-Scissors!
----------------------------------------

```

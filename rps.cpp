/**
 * rps.cpp
 * Project UID 24b93ce4a6274610f4c3f3e31fe17277c
 *
 * Caitlin Berry
 * cnberry
 *
 * EECS 183: Project 2
 * Fall 2023
 *
 * This program simulates a game of rock, paper, scissors between two
 * opponents, taking input for both players names and allowing them to enter
 * their moves. Then the winner of the round is computed and after playing
 * three rounds, the person with the most wins is deemed the winner.
 */

#include <iostream>
#include <string>

const int MAX_ROUNDS = 3;

using namespace std;

//************************************************************************
// The following four functions have already been implemented for you.
// You should use them when writing the other functions, but do not edit
// their implementations.
//************************************************************************

/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  Prints a pretty header to introduce the user to the game.
 */
void printInitialHeader();

/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  Prints the menu.
 * Prompts:  "1) Play rock, paper, scissors"
 *           "2) Play rock, paper, scissors, lizard, spock"
 *           "3) Quit"
 *           "Choice --> "
 */
void printMenu();

/**
 * Requires: errorNumber be either 1 or 2
 * Modifies: cout
 * Effects:  If errorNumber is 1, prints an error message indicating
 *           an illegal name was entered.
 *           If errorNumber is 2, prints an error message indicating
 *           an illegal move was entered.
 */
void printErrorMessage(int errorNumber);

/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  Prints out the final greeting for the program.
 */
void printCloser();

//************************************************************************
// You must implement all of the following functions. Add your 
// implementations below rps() as indicated.
//************************************************************************

/**
 * Requires: playerNumber is either 1 or 2
 * Modifies: cout, cin
 * Effects:  Prompts the user to enter their name. Names entered may
 *           have spaces within them.
 *               Example: "Kermit the frog"
 *
 *           If an empty name is given, this is invalid input, so print
 *           error message 1, and return a default name.
 *           For player 1, the default name is: Rocky
 *           For player 2, the default name is: Creed
 *           Otherwise, return name entered by user.
 *              
 * Prompt:   Player [playerNumber], enter your name:
 */
string getName(int playerNumber);


/**
 * Requires: nothing
 * Modifies: cout, cin
 * Effects:  Prints the menu, and reads the input from the user.
 *           Checks to make sure the input is within range for the menu.
 *           If it is not, prints "Invalid menu choice". Continues to print 
 *           the menu and read in input until a valid choice is entered,
 *           then returns the user's choice of menu options. You can assume
 *           a user will enter an integer, and nothing else, as their choice.
 *
 * Prompt:   Invalid menu choice
 */
int getMenuChoice();


/**
 * Requires: nothing
 * Modifies: nothing
 * Effects:  Returns true if and only if move represents a valid move character:
 *           one of 'R', 'r', 'P', 'p', 'S', 's'. Returns false otherwise.
 */
bool isMoveGood(char move);


/**
 * Requires: playerName is the name of the player being prompted for their
 *           move.
 * Modifies: cout, cin
 * Effects:  Prompts the player for their move and returns it.
 *           This function should accept the first non-whitespace character as
 *           the move. If an illegal character is entered for their move, print
 *           error message 2 and return rock as a default. You can assume a user
 *           will enter a single character, and nothing else, as their move.
 *
 * Prompt:   [playerName], enter your move:
 */
char getMove(string playerName);


/**
 * Requires: move is the move of the player being checked for a win.
 *           opponentMove is the move of the opponent.
 *           both move and opponentMove are valid moves.
 * Modifies: nothing
 * Effects:  Returns true if and only if the player who made move won
 *           according to the rules to rock-paper-scissors. Returns false
 *           otherwise.
 */
bool isRoundWinner(char move, char opponentMove);


/**
 * Requires: winnerName is the name of the player who won the round.
 * Modifies: cout
 * Effects:  If winnerName is the empty string, i.e., "",
 *           prints a message indicating the round is a draw. 
 *           Otherwise, prints a congratulatory message to the winner.
 * Prompt:   This round is a draw!
 *           ------------- OR -------------
 *           [winner_name] wins the round!
 */
void announceRoundWinner(string winnerName);


/**
 * Requires: p1Name and p2Name are the names of the respective players
 * Modifies: nothing
 * Effects:  Simulates a complete round of rock-paper-scissors, which
 *           consists of three steps:
 *             1. Get player1 move
 *             2. Get player2 move
 *             3. Return 0 if the round was a draw; 1 if player 1 won;
 *                2 if player 2 won.
 */
int doRound(string p1Name, string p2Name);


/**
 * Requires: winnerName is the name of the player who won the game.
 * Modifies: cout
 * Effects:  If winnerName is the empty string, i.e., "", 
 *           prints that the game was a draw.
 *           Otherwise, prints a congratulatory message to the winner.
 * Prompt:   No winner!
 *           ------------- OR -------------
 *           Congratulations [winnerName]!
 *           You won EECS 183 Rock-Paper-Scissors!
 */
void announceWinner(string winnerName);


/**
 * Requires: p1Name and p2Name are the names of the respective players,
 *           gameType can be 1 for regular rock-paper-scissors
 *           or 2 for rock-paper-scissors-lizard-spock
 * Modifies: cout
 *
 * Base Project:
 * Effects:  If gameType is 2, prints "Under Construction" to indicate that the
 *           s'more has not been implemented. Returns empty string.
 *           Otherwise, plays exactly three rounds of rock-paper-scissors while
 *           keeping track of the number of round wins for each player.
 *           When a round results in a draw, neither player is the winner,
 *           so neither player is awarded a point.
 *           After each round is played, the round winner (or draw) is
 *           announced. 
 *           Returns the name of the game winner, or "" in event of a draw.
 * Prompt:   Under Construction
 *
 * S'more Version:
 * Effects:  Has same functionality as base project, but also handles a
 *           gameType of 2. When game_type is 2, plays exactly three rounds of
 *           rock-paper-scissors-lizard-spock. Keeps track of round wins for
 *           each player and announces round winners in the same fashion as 
 *           described above.
 */
string doGame(string p1Name, string p2Name, int gameType);


//************************************************************************
// Implement the functions below this line.
//************************************************************************


void rps() {
        
    printInitialHeader(); 
    string player1Name = getName(1);
    string player2Name = getName(2);
    
    int menuOption = getMenuChoice();
   
    int quitGameNum = 3;
    // check if user is trying to quit; if they're not, proceed with game
    while (menuOption != quitGameNum) {
        
            string gameWinner = doGame(player1Name, player2Name, menuOption);
            announceWinner(gameWinner);
            menuOption = getMenuChoice();

        }
    
    printCloser();

    return;
    
}

string getName(int playerNumber) {
    
    cout << "Player " << playerNumber << ", enter your name: ";
    
    string input;
    getline(cin, input);
    cout << endl;
    
    // assign players names depending on the input (if given)
    if (input == ""){
        printErrorMessage(1);
        if (playerNumber == 1){
            return "Rocky";
        }
        else if (playerNumber == 2){
            return "Creed";
        }
    }
    else {
        if (playerNumber == 1) {
            return input;
        }
        else if (playerNumber == 2) {
            return input;
        }
    }

    return "";
    
}

int getMenuChoice() {

    printMenu();
    int input;
    
    int quitGameNumber = 3;
    // keep reciving input values for menu choice until a valid choice is given
    while (cin >> input){
        
        if (input == 1) {
            return 1;
        }
        else if (input == 2) {
            return 2;
        }
        else if (input == quitGameNumber) {
            return quitGameNumber;
        }
        else {
            cout << endl << "Invalid menu choice" << endl;
            printMenu();
        }
    }
    
    return 0;
    
}

bool isMoveGood(char move) {
    
    // run through all possible plays to see if given input is a valid move
    if (move == 'r') {
        return true;
    }
    else if (move == 'R') {
        return true;
    }
    else if (move == 'p') {
        return true;
    }
    else if (move == 'P') {
        return true;
    }
    else if (move == 's') {
        return true;
    }
    else if (move == 'S') {
        return true;
    }
    else {
        return false;
    }
    
}

char getMove(string playerName) {

    char move;
    
    cout << playerName << ", enter your move: ";
    cin >> move;
    cout << endl;
    
    // check the given input and return said input if the play is valid
    if (isMoveGood(move)) {
        return move;
    }
    else {
        printErrorMessage(2);
    }
    
    return 'r';
    
}

bool isRoundWinner(char move, char opponentMove) {

    // go through all possible combinations of valid moves to deem round winner
    if (move == 'r' || move == 'R') {
        if (opponentMove == 's' || opponentMove == 'S') {
            return true;
        }
        if (opponentMove == 'p' || opponentMove == 'P') {
            return false;
        }
    }
    
    if (move == 'p' || move == 'P') {
        if (opponentMove == 's' || opponentMove == 'S') {
            return false;
        }
        if (opponentMove == 'r' || opponentMove == 'R') {
            return true;
        }
    }
    
    if (move == 's' || move == 'S') {
        if (opponentMove == 'r' || opponentMove == 'R') {
            return false;
        }
        if (opponentMove == 'p' || opponentMove == 'P') {
            return true;
        }
    }
            
    return false;
    
}

void announceRoundWinner(string winnerName) {
    
    if (winnerName == "") {
        cout << "This round is a draw!" << endl << endl;
    }
    else {
        cout << winnerName << " wins the round!" << endl << endl;
    }
    
}

int doRound(string p1Name, string p2Name) {
    
    char move1 = getMove(p1Name);
    char move2 = getMove(p2Name);
    
    // return the number of the player who won the round
    if (isRoundWinner(move1, move2)) {
        return 1;
    }
    else if (isRoundWinner(move2, move1)) {
        return 2;
    }
    else {
        return 0;
    }
    
}

void announceWinner(string winnerName) {

    if (winnerName == "") {
        cout << "No winner!" << endl;
    }
    else {
        cout << "Congratulations " << winnerName << "!" << endl;
        cout << "You won EECS 183 Rock-Paper-Scissors!";
    }
        
    return;
    
}

string doGame(string p1Name, string p2Name, int gameType) {

    int player1Score = 0;
    int player2Score = 0;
    
    if (gameType == 2) {
        cout << "Under Construction" << endl;
        return "";
    }
    else {
        string winnerName;
        for (int i = 0; i < MAX_ROUNDS; ++i) {
            
            int winnerNum = doRound(p1Name, p2Name);
            
            // assign the "winner spot" the correct name of the winning player
            // increase the winner's overall score
            if (winnerNum == 1) {
                winnerName = p1Name;
                player1Score += 1;
            }
            else if (winnerNum == 2) {
                winnerName = p2Name;
                player2Score += 1;
            }
            else {
                winnerName = "";
            }
            
            announceRoundWinner(winnerName);
        }
    }
    
    if (player1Score > player2Score) {
        return p1Name;
    }
    else if (player1Score < player2Score) {
        return p2Name;
    }
    else {
        return "";
    }
    
}



//***********************************************************************
// DO NOT modify the four functions below.
//***********************************************************************
void printInitialHeader() {
    cout << "----------------------------------------" << endl;
    cout << "               EECS 183                 " << endl;
    cout << "          Rock-Paper-Scissors           " << endl;
    cout << "----------------------------------------" << endl << endl;
    
    return;
}

void printMenu() {
    cout << endl << endl;
    cout << "Menu Options" << endl
        << "------------" << endl;
    cout << "1) Play rock, paper, scissors" << endl;
    cout << "2) Play rock, paper, scissors, lizard, spock" << endl;
    cout << "3) Quit" << endl << endl;
    
    cout << "Choice --> ";
    
    return;
}

void printErrorMessage(int errorNumber) {
    if (errorNumber == 1) {
        cout << endl << "ERROR: Illegal name given, using default" 
            << endl << endl;
    }
    else if (errorNumber == 2) {
        cout << endl << "ERROR: Illegal move given, using default" << endl;
    }
    else {
        cout << "This should never print!";
    }
    
    return;
}

void printCloser() {
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "           Thanks for playing           " << endl;
    cout << "          Rock-Paper-Scissors!          " << endl;
    cout << "----------------------------------------" << endl << endl;
    
    return;
}

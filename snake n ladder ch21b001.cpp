
 #include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int WINNING_POSITION = 100;
const int NUM_SNAKES = 5;
const int NUM_LADDERS = 5;

// Array to represent snakes and their positions
int snakes[NUM_SNAKES][2] = {
    {16, 6},
    {47, 26},
    {49, 11},
    {56, 53},
    {62, 19}
};

// Array to represent ladders and their positions
int ladders[NUM_LADDERS][2] = {
    {4, 25},
    {13, 46},
    {33, 49},
    {42, 63},
    {50, 69}
};

// Function to generate a random number between 1 and 6 (dice roll)
int rollDice() {
    return rand() % 6 + 1;
}

// Function to check if a snake is present at the current position
bool isSnake(int position) {
    for (int i = 0; i < NUM_SNAKES; i++) {
        if (snakes[i][0] == position)
            return true;
    }
    return false;
}

// Function to check if a ladder is present at the current position
bool isLadder(int position) {
    for (int i = 0; i < NUM_LADDERS; i++) {
        if (ladders[i][0] == position)
            return true;
    }
    return false;
}

// Function to get the new position after moving through a snake or ladder
int getNewPosition(int position) {
    for (int i = 0; i < NUM_SNAKES; i++) {
        if (snakes[i][0] == position)
        {


            cout << "Player encountered a snake at position " << position << ". ";
            cout << "Player moves down to position " << snakes[i][1] << "." << endl;
            return snakes[i][1];
        }
    }
    for (int i = 0; i < NUM_LADDERS; i++) {
        if (ladders[i][0] == position)
        {


            cout << "Player encountered a ladder at position " << position << ". ";
            cout << "Player moves up to position " << ladders[i][1] << "." << endl;
            return ladders[i][1];}
    }
    return position;
}

// Function to display the current positions of both players
void displayPositions(int player1Position, int player2Position) {
    cout << "Player 1 is at position: " << player1Position << endl;
    cout << "Player 2 is at position: " << player2Position << endl;
    cout << "--------------------------" << endl;
}

int main() {
    srand(time(0));  // Seed the random number generator with current time
    char a,b;
    int player1Position = 0;
    int player2Position = 0;
    int currentPlayer = 1;

    cout << "Welcome to Snake and Ladder Game!" << endl;
    cout << "Press 1 to roll the dice." << endl;

    while (player1Position < WINNING_POSITION && player2Position < WINNING_POSITION) {
        if (currentPlayer == 1) {
            cout << "Player 1's turn. Press 1 to roll the dice: ";
            cin>>a;  // Wait for the user to press 1
            int diceRoll = rollDice();
            cout << "Player 1 rolled a " << diceRoll << "." << endl;
            player1Position += diceRoll;
            player1Position = getNewPosition(player1Position);
            displayPositions(player1Position, player2Position);
            if (player1Position == WINNING_POSITION) {
                cout << "Player 1 wins!" << endl;
                break;}currentPlayer++;}
        if (currentPlayer == 2) {
            cout << "Player 2's turn. Press 2 to roll the dice: ";
            cin>>b;  // Wait for the user to press 1
            int diceRoll = rollDice();
            cout << "Player 2 rolled a " << diceRoll << "." << endl;
            player2Position += diceRoll;
            player2Position = getNewPosition(player2Position);
            displayPositions(player1Position, player2Position);
            if (player1Position == WINNING_POSITION) {
                cout << "Player 2 wins!" << endl;
                break;}currentPlayer--;}}}


// Importing the necessary libraries
#include <iostream>
#include <stdlib.h>

using namespace std;

// Array for the board
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

// Variable Declaration
int choice;
int row, column;
char turn = 'X';
bool draw = false;

// Function to display the current status of the game board
void display_board() {
    cout << "PLAYER - 1 [X]  PLAYER - 2 [O]\n\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    cout << "\t     |     |     \n";
}

// Function to get the player input and update the board
void player_turn() {
    if (turn == 'X') {
        cout << "\nPlayer - 1 [X] turn : ";
    } else if (turn == 'O') {
        cout << "\nPlayer - 2 [O] turn : ";
    }
    
    // Taking input from user
    cin >> choice;
    
    // Switch case to determine which row and column to update
    switch (choice) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "Invalid Move";
    }
    
    // Updating the position on the board if it's not already occupied
    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = 'X';
        turn = 'O';
    } else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = 'O';
        turn = 'X';
    } else {
        // If the chosen position is already filled
        cout << "Box already filled!\nPlease choose another!\n\n";
        player_turn();
    }
    
    // Displaying the updated board
    display_board();
}

// Function to check the game status (win, draw, or continue)
bool gameover() {
    // Checking for win in rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] ||
            board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return false;
        }
    }
    
    // Checking for win in diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] ||
        board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return false;
    }
    
    // Checking if the game is in continue mode or if it's a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return true;
            }
        }
    }
    
    // If all positions are filled and no winner is found
    draw = true;
    return false;
}

// Main function to run the game
int main() {
    cout << "\n\n\tT I C K -- T A C -- T O E -- G A M E\n\n";
    cout << "\tFOR 2 PLAYERS\n\n";
    
    // Main game loop
    while (gameover()) {
        display_board();
        player_turn();
        gameover();
    }
    
    // Displaying the result of the game
    if (turn == 'X' && !draw) {
        cout << "\nCongratulations! Player with 'X' has won the game!\n";
    } else if (turn == 'O' && !draw) {
        cout << "\nCongratulations! Player with 'O' has won the game!\n";
    } else {
        cout << "\nGAME DRAW!!!\n";
    }
    
    return 0;
}

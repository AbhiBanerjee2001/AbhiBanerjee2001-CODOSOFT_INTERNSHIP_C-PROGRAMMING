/*TASK 3
TIC-TAC-TOE GAME
*/
#include <iostream>
#include <vector>
#include <limits> // For std::numeric_limits

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X'; // Player A starts as X
    }

    void displayBoard() {
        cout << "Current Board:\n";
        for (int i = 0; i < 3; ++i) {
            cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " \n";
            if (i < 2) {
                cout << "---|---|---\n";
            }
        }
        cout << endl;
    }

    bool isMoveValid(int row, int col) {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
    }

    void makeMove(int row, int col) {
        board[row][col] = currentPlayer;
    }

    bool checkWin() {
        // Check rows, columns, and diagonals
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) || 
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
                return true;
            }
        }
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) || 
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            return true;
        }
        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    return false; // If there's any empty cell, it's not a draw
                }
            }
        }
        return true; // No empty cells, it's a draw
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch between X and O
    }

    void resetGame() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X'; // Reset current player to Player A
    }

    void playGame() {
        bool playing = true;
        while (playing) {
            displayBoard();
            int row, col;
            bool validInput = false; // Flag to check if input is valid

            while (!validInput) {
                cout << "Player " << (currentPlayer == 'X' ? "A (X)" : "B (O)") << ", enter your move (row and column): ";
                cin >> row >> col;

                // Check for input validity
                if (cin.fail() || row < 1 || row > 3 || col < 1 || col > 3) {
                    cin.clear(); // Clear the error state
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    cout << "Invalid input. Please enter two numbers for row and column (1-3).\n";
                    continue; // Ask for input again
                }

                // Adjust for 0-based index
                row--; col--;

                if (isMoveValid(row, col)) {
                    makeMove(row, col);
                    validInput = true; // Mark input as valid
                } else {
                    cout << "Invalid move. Please enter a valid row (1-3) and column (1-3) that is not already taken.\n";
                }
            }

            if (checkWin()) {
                displayBoard();
                cout << "Player " << (currentPlayer == 'X' ? "A" : "B") << " wins!\n";
                playing = false;
            } else if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                playing = false;
            } else {
                switchPlayer();
            }
        }
    }
};

int main() {
    char playAgain;
    do {
        TicTacToe game;
        game.playGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
    
    cout << "Thanks for playing!\n";
    return 0;
}

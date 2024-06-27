#include <iostream>
using namespace std;

char board[3][3];
char currentMarker;
char currentPlayer;

void displayBoard() {
    // system("cls");
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool placeMarker(int row, int col) {
    if (board[row][col] != ' ') return true;
    board[row][col] = currentMarker;
    return false;
}

int winner() {
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return currentPlayer;
        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return currentPlayer;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return currentPlayer;

    return 0;
}

void swapPlayerAndMarker() {
    if (currentMarker == 'X') currentMarker = 'O';
    else currentMarker = 'X';

    if (currentPlayer == '1') currentPlayer = '2';
    else currentPlayer = '1';
}

void game() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';

    currentPlayer = '1';
    currentMarker = 'X';
    int playerWon = 0;

    for (int i = 0; i < 9; i++) {
        displayBoard();
        int row, col;

        cout << "Player " << currentPlayer << " (" << currentMarker << "), it's your turn. Enter row and column (0-2): ";
        cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2) {
            cout << "Invalid position! Try again." << endl;
            i--;
            continue;
        }

        if (placeMarker(row, col)) {
            cout << "That position is already taken! Try again." << endl;
            i--;
            continue;
        }
            //checking if the player won after his/her turn
        playerWon = winner();
        if (playerWon) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }
        //next player turn!
        swapPlayerAndMarker();
    }
    //after all 9 turns if no player won then it is a Draw!
    if (playerWon == 0)
        cout << "It's a Draw!" << endl;
}

void showInstructions() {
    cout << "Welcome to Tic Tac Toe!" << endl;
    cout << "Player 1: X, Player 2: O" << endl;
    cout << "Enter your move as row and column number (0, 1, or 2)." << endl;
    cout << "For example, to place a marker in the top left, enter: 0 0. (Don't forget to put a space between the row and the colomn!)" << endl;
}

int main() {
    int choice;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Play Game\n";
        cout << "2. View Instructions\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                game();
                break;
            case 2:
                showInstructions();
                break;
            case 3:
                cout << "Thanks for playing!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}

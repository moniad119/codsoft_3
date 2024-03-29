#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<char>> &board) {
    for (const auto &row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

bool checkWin(const vector<vector<char>> &board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool checkTie(const vector<vector<char>> &board) {
    for (const auto & row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return false; 
        }
    }
    return true; 
}

bool makeMove(vector<vector<char>> &board, int row, int col, char player) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
       
        return false;
    }


    board[row][col] = player;
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); 
    char currentPlayer = 'X';

    while (true) {
        printBoard(board);
        int row, col;
        cout << "Player " << currentPlayer << ", Enter your move (row and column): ";
        cin >> row >> col;
        if (makeMove(board, row, col, currentPlayer)) {
            if (checkWin(board, currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }
            if (checkTie(board)) {
                cout << "The game is tie!" << endl;
                break;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move, Try again." << endl;
        }
    }

    return 0;
}

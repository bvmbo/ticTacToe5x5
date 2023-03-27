#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 5;
char board[SIZE][SIZE];
bool a = 0, b = 0;

bool check_row(int row, char player) {
    for (int col = 0; col < SIZE; col++) {
        if (board[row][col] != player) {
            return false;
        }
    }
    if (player == 'A') 
        a = 1;
    else
        b = 1;
    return true;
}

bool check_col(int col, char player) {
    for (int row = 0; row < SIZE; row++) {
        if (board[row][col] != player) {
            return false;
        }
    }

    if (player == 'A')
        a = 1;
    else
        b = 1;
    return true;
}

bool check_diag(char player) {
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < SIZE; i++) {
        if (board[i][i] == player) {
            count1++;
        }
        if (board[i][SIZE - 1 - i] == player) {
            count2++;
        }
    }

    if (player == 'A')
        a = 1;
    else
        b = 1;

    return (count1 == 3 || count2 == 3);
}

bool check_win(char player) {
    for (int i = 0; i < SIZE; i++) {
        if (check_row(i, player) || check_col(i, player)) {
            return true;
        }
    }
    return check_diag(player);
}

bool check_draw() {
    if (a && b)
        return true;
    else
        return false;
}

void play_game() {
    string line;
    for (int row = 0; row < SIZE; row++) {
        cin >> line;
        for (int col = 0; col < SIZE; col++) {
            board[row][col] = line[col];
        }
    }

    if (check_win('A')) {
        cout << "A wygrywa" << endl;
    }
    else if (check_win('B')) {
        cout << "B wygrywa" << endl;
    }
    else if (check_draw()) {
        cout << "remis" << endl;
    }
}

int main(){
	int cases;
	cin >> cases;
	while (cases--) {
        play_game();
	}

	return 0;
}
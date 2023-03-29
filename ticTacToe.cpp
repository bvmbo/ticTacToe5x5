#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 5;
char board[SIZE][SIZE];

bool check_vertical(int col, char player) {
	int count = 0;

	for (int row = 0; row < SIZE; row++) {
		if (board[row][col] != player) {
			count = 0;
		}
		else {
			count++;
		}

		if (count == 3) {

			return true;
		}
	}
	return false;
}

bool check_horizontal(int row, char player) {
	int count = 0;

	for (int col = 0; col < SIZE; col++) {
		if (board[row][col] != player) {
			count = 0;
		}
		else {
			count++;
		}

		if (count == 3) {

			return true;
		}
	}
	return false;
}

bool check_diag(char player) {
	int row = 0;
	int col = 0;
	int count = 0;

	for (int c = col - 2; c <= col + 2; c++) {
		if (c < SIZE && c >= 0) {
			if (board[row][c] != player) {
				count = 0;
			}
			else {
				count++;
			}

			if (count == 3) {

				return true;
			}
		}
		row++;
	}

	count = 0;
	row = 0;

	for (int c = 6; c >= 2; c--) {
		if (c < SIZE && c >= 0) {
			if (board[row][c] != player) {
				count = 0;
			}
			else {
				count++;
			}

			if (count == 3) {

				return true;
			}
		}
		row++;
	}


	return false;
}

bool check_win(char player) {
	for (int i = 0; i < SIZE; i++) {
		if (check_horizontal(i, player) || check_vertical(i, player)) {
			return true;
		}
	}
	return false;
}

bool check_draw() {
	bool a_wins = check_win('A');
	bool b_wins = check_win('B');


	if (!a_wins) a_wins = check_diag('A');
	if (!b_wins) b_wins = check_diag('B');

	return ((!a_wins && !b_wins) || (a_wins && b_wins));
}

void play_game() {
	string line;
	for (int i = 0; i < SIZE; i++) {
		cin >> line;
		for (int j = 0; j < SIZE; j++) {
			board[i][j] = line[j];
		}
	}

	if (check_draw()) {
		cout << "remis" << endl;
	}
	else if (check_win('A')) {
		cout << "A wygrywa" << endl;
	}
	else if (check_win('B')) {
		cout << "B wygrywa" << endl;
	}
}

int main() {
	int t;
	cin >> t;

	while (t--)
		play_game();

	return 0;
}
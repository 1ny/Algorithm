#include "iostream"
#include "vector"
#include "string"
using namespace std;

int R, C, N;
string board[202];
int t;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
vector<pair<int, int>> v;

void output() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] != '.') cout << "O";
			else cout << ".";
		}
		cout << endl;
	}
}

void third() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == '.') board[i][j] = '0';
			else board[i][j]++;
		}
	}
}

void fourth() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == '2') v.push_back({ i,j });
			else board[i][j]++;
		}
	}

	for (int i = 0; i < v.size(); i++) {
		board[v[i].first][v[i].second] = '.';
		for (int d = 0; d < 4; d++) {
			int nx = v[i].first + dx[d];
			int ny = v[i].second + dy[d];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
			board[nx][ny] = '.';
		}
	}
	
	v.clear();
}

int main() {
	ios::sync_with_stdio();
	cin.tie(0); cout.tie(0);

	cin >> R >> C >> N;
	for (int i = 0; i < R; i++) {
			cin >> board[i];
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == 'O') board[i][j] = '0';
		}
	}

	if (N == 1) {
		output(); 
		return 0;
	}
	t++;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == '0') board[i][j]++;
		}
	}

	while (t < N) {
		t++;
		if (t % 2 == 0) {
			third();
		}
		else {
			fourth();
		}

		//for (int i = 0; i < R; i++) {
		//	for (int j = 0; j < C; j++) {
		//		cout << board[i][j];
		//	}
		//	cout << endl;
		//}
		//cout << endl;
	}

	output();

	return 0;
}

#include "iostream"
using namespace std;

#define MAX 10

int n, m;
int arr[MAX];
bool visited[MAX];

void printFunc() {
	for (int i = 0; i < m; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void backTracking(int k) {
	// 끝낼 조건문

	// 트래킹  ex. 1~n까지의 수 할당 -> for문 + 재귀
	// * 중복없는 수열 -> visited 체크
	// * 수열 저장
	// * 다시 visited 해제 (상태 트리를 상상하면 댐)

	
	if (k == m) {
		printFunc();
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		arr[k] = i;
		visited[i] = 1;
		backTracking(k+1);
		visited[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	backTracking(0);

	return 0;
}
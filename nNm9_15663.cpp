#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[10];
int num[10];
bool isused[10];
void solve(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << num[i] << ' ';
		}
		cout << "\n";
		return;
	}
	int tmp = -1;
	for (int i = 0; i < n; i++) {
		if (isused[i] || tmp == arr[i]) continue;
		num[cnt] = arr[i];
		isused[i] = 1;
		tmp = num[cnt];
		solve(cnt + 1);
		isused[i] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	solve(0);
}
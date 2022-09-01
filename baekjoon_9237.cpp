#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int res = 0;
	vector<int> v;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.rbegin(), v.rend());
	for (int i = 0; i < n; i++) {
		int day = v[i] + i + 1;
		res = res > day ? res : day;
	}
	cout << res + 1 << endl;
	return 0;
}

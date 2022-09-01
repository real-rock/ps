#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, l;
	int res = 0;
	int loc = 0;
	vector<int> v;
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	loc = v[0];
	res++;
	for (int &ele: v) {
		if (loc - 0.5 + l > (float)ele) {
			continue;
		} else {
			res++;
			loc = ele;
		}
	}
	cout << res << "\n";
	return 0;
}
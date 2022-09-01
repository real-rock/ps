#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	long long max;
	vector<int> m_weight;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		m_weight.push_back(tmp);
	}
	sort(m_weight.begin(), m_weight.end());
	max = 0;
	for (int i = 0; i < n; i++) {
		long long w_expected = m_weight[i] * (n - i);
		max = max >= w_expected ? max : w_expected;
	}
	cout << max << "\n";
	return 0;
}

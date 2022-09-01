#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> price(n), profit(n);

	for (int &ele: price) {
		cin >> ele;
	}

	profit[0] = k;
	for (int i = 0; i < price.size() - 1; i++) {
		if (price[i + 1] > price[i]) {
			profit[i + 1] = (profit[i] / price[i]) * price[i + 1] + (profit[i] % price[i]);
		}
		else {
			profit[i + 1] = profit[i];
		}
	}
	cout << profit[n - 1] << endl;
	return 0;
}

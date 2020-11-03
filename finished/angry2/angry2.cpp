#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N, K, ub, lb, guess, cowsneeded, last, current;
	int bales[50000] = { 0 };

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> bales[i];
	}

	sort(bales, bales + N);
	ub = 500000000;
	lb = 0;

	while (ub != lb) {
		guess = (ub + lb) / 2;
		cowsneeded = 0;
		last = 0;
		while (last < N) {
			cowsneeded++;
			current = last + 1;
			while ((current < N) && (bales[current] - bales[last] <= 2 * guess)) {
				current++;
			}
			last = current;
		}
		if (cowsneeded <= K) {
			ub = guess;
		}
		else {
			lb = guess + 1;
		}
	}
	cout << lb;
}


#include <iostream>
#include <algorithm>

using namespace std;
int diamonds[50000] = { 0 };
int smallD[50000] = { 0 };
int bigD[50000] = { 0 };

int main()
{
	int N, K, answer, ind1, ind2;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> diamonds[i]; // read diamonds
	}
	answer = 0;
	sort(diamonds, diamonds + N); // sort diamonds
	ind1 = 0;
	for (int i = 0; i < N; i++) {
		while (diamonds[i] - diamonds[ind1] > K) {
			ind1++;
		}
		smallD[i] = i - ind1 + 1;
		if (i > 0) {
			smallD[i] = max(smallD[i], smallD[i - 1]);
		}
	}

	ind2 = N - 1;
	for (int i = N - 1; i >= 0; i--) {
		bigD[i] = 0;
		if (i < N - 1) {
			while (diamonds[ind2] - diamonds[i + 1] > K) {
				ind2--;
			}
			bigD[i] = ind2 - i;
			bigD[i] = max(bigD[i], bigD[i - 1]);
		}
	}

	for (int i = 0; i < N; i++) {
		if (smallD[i] + bigD[i] > answer) {
			answer = smallD[i] + bigD[i];
		}
	}
	cout << answer;
}

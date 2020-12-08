#include <iostream>
#include <map>

using namespace std;

int main()
{
	int N, answer, size;
	int cows[50001] = { };
	int pf[50001] = { 0 };
	map<int, int> seen;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> cows[i];
		cows[i] %= 7;
	}
	for (int i = 1; i <= N; i++) {
		pf[i] = (pf[i - 1] + cows[i]) % 7;
	}

	answer = 0;

	for (int i = 1; i <= N; i++) {
		size = 0;
		if (seen.find(pf[i]) == seen.end() && i < N) {
			seen[pf[i]] = i;
		}
		else if (seen.find(pf[i]) != seen.end()) {
			size = i - seen[pf[i]];
		}
		if (size > answer) {
			answer = size;
		}
	}

	cout << answer;
}

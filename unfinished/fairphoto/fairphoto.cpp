#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct charint {
	int i;
	char c;
};

bool comp(charint x, charint y) {
	return x.i < y.i;
}

int pf[100001] = { 0 };
charint cows[100001] = { };

int main()
{
	int N, answer, size;
	map<int, int> seen;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> cows[i].i >> cows[i].c;
	}

	sort(cows + 1, cows + N + 1, comp);

	for (int i = 1; i <= N; i++) {
		if (cows[i].c == 'G') {
			pf[i] = pf[i - 1] + 1;
		}
		if (cows[i].c == 'H') {
			pf[i] = pf[i - 1] - 1;
		}
	}

	answer = 0;
	for (int i = 1; i <= N; i++) {
		size = 0;
		if (seen.find(pf[i]) == seen.end() && i < N) {
			seen[pf[i]] = cows[i + 1].i;
		}
		else if (seen.find(pf[i]) != seen.end()) {
			size = cows[i].i - seen[pf[i]];
		}
		if (size > answer) {
			answer = size;
		}
	}

	cout << answer;
}


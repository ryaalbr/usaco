#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>

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
	int N, answer, size, linpos;
	unordered_map<int, int> seen;
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
	for (int i = 0; i <= N; i++) {
		size = 0;
		if (seen.count(pf[i])) {
			size = cows[i].i - seen[pf[i]];
		}
		else {
			if (i < N) {
				seen[pf[i]] = cows[i + 1].i;
			}
		}
		if (size > answer) {
			answer = size;
		}
	}

	for (int i = 1; i <= N; i++) {
		// Compute for case that only one breed is in the photo
		if (i == 1) {
			linpos = cows[i].i;
		}
		else if (i > 1 && i < N) {
			if (cows[i].c != cows[i - 1].c) {
				size = cows[i - 1].i - linpos;
				linpos = cows[i].i;
				if (size > answer) {
					answer = size;
				}
			}
		} 
		else if (i == N) {
			if (cows[i].c != cows[i - 1].c) {
				size = cows[i - 1].i - linpos;
				linpos = cows[i].i;
				if (size > answer) {
					answer = size;
				}
			}
			if (cows[i].c == cows[i - 1].c) {
				size = cows[i].i - linpos;
				if (size > answer) {
					answer = size;
				}
			}
		}
	}

	cout << answer;
}


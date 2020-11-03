#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

struct strint {
	string s;
	int i;
};

bool comp(strint a, strint b) {
	return a.i < b.i;
}

int main()
{
	int N, A, B;
	int count = 0;
	strint cows[50002] = {};
	cin >> N >> A >> B;
	
	for (int i = 0; i < N; i++) {
		cin >> cows[i + 1].s >> cows[i + 1].i;
	}
	sort(cows + 1, cows + N + 1);

	cows[0].s = "NS";
	cows[0].i = 1 - cows[1].i;
	cows[N + 1].s = "NS";
	cows[N + 1].i = (2 * N) - cows[N].i;

	for (int i = 0; i <= N; i++) {
		if (cows[i].s == "S" && cows[i + 1].s == "NS") {
			count += ceil(((cows[i + 1].i) - (cows[i].i) + 1) / 2);
		}
		if (cows[i].s == "NS" && cows[i + 1].s == "S") {
			count += floor(((cows[i + 1].i) - (cows[i].i)) / 2);
		}
		if (cows[i].s == "S" && cows[i + 1].s == "S") {
			count += ((cows[i + 1].i) - (cows[i].i));
		}
	}
	cout << count;
}

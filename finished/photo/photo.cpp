#include <iostream>
#include <algorithm>

using namespace std;

struct doubint {
	int ai, bi;
};

bool comp(doubint x, doubint y) {
	return x.bi > y.bi;
}

bool comp2(doubint x, doubint y) {
	return x.ai < y.ai;
}

int main()
{
	int N, K, count, temp;
	count = 0;
	doubint pairs[1000] = { };
	doubint hated[2000] = { };
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> pairs[i].ai >> pairs[i].bi;
	}
	
	for (int i = 0; i < K; i++) {
		if (pairs[i].ai < pairs[i].bi) {
			hated[2 * i].ai = pairs[i].ai;
			hated[2 * i].bi = 0;
			hated[(2 * i) + 1].ai = pairs[i].bi;
			hated[(2 * i) + 1].bi = pairs[i].ai;
		}
		else {
			hated[2 * i].ai = pairs[i].bi;
			hated[2 * i].bi = 0;
			hated[(2 * i) + 1].ai = pairs[i].ai;
			hated[(2 * i) + 1].bi = pairs[i].bi;
		}
	}

	sort(hated, hated + (2 * K), comp);
	sort(hated, hated + (2 * K), comp2);

	temp = hated[0].ai;

	for (int i = 0; i < (2 * K); i++) {
		if (hated[i].bi >= temp) {
			temp = hated[i].ai;
			count++;
		}
	}
	count++;
	cout << count;
}


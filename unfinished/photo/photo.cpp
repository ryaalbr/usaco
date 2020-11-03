#include <iostream>
#include <algorithm>

using namespace std;

struct doubint {
	int ai, bi;
};

bool comp(doubint x, doubint y) {
	return x.bi < y.bi;
}

int main()
{
	int N, K, count, temp;
	count = 0;
	temp = 0;
	doubint pairs[1000] = { };
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> pairs[i].ai >> pairs[i].bi;
	}
	sort(pairs, pairs + K, comp);
	for (int i = 0; i < K; i++) {
		if (pairs[i].ai > temp) {
			count++;
			temp = pairs[i].ai;
		}
	}
	cout << count;
}


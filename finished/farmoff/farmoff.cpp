#include <iostream>
#include <algorithm>

using namespace std;

struct wiui {
	int W_i, U_i;
};

wiui cows[1500000] = { };

bool comp1(wiui a, wiui b){
	return a.U_i < b.U_i;
}

bool comp2(wiui a, wiui b) {
	return a.W_i > b.U_i;
}

int main()
{
	long long N, a, b, c, d, e, f, g, h, M, nlower, nhigher, answer;
	long long p;
	answer = 0;
	cin >> N >> a >> b >> c >> d >> e >> f >> g >> h >> M;
	for (int i = 0; i < 3 * N; i++) {
		p = a;
		for (int j = 0; j < 5; j++) {
			p %= d;
			p *= i;
			p %= d;
		}
		p += (((((b % d) * i) % d) * i) % d + c) % d;
		p %= d;
		cows[i].W_i = p;
		p = e;
		for (int j = 0; j < 5; j++) {
			p %= h;
			p *= i;
			p %= h;
		}
		p += ((((((((f % h) * i) % h) * i) % h) * i) % h) + g) % h;
		p %= h;
		cows[i].U_i = p;
	}
	sort(cows, cows + 3 * N, comp1);
	
	nlower = 2 * N;
	nhigher = 2 * N;
	while (true) {
		if (cows[nlower - 1].U_i == cows[nlower].U_i || nlower == 0) {
			nlower--;
		}
		else {
			break;
		}
	}
	while (true) {
		if (cows[nhigher + 1].U_i == cows[nhigher].U_i || nhigher == (3 * N) - 1) {
			nlower++;
		}
		else {
			break;
		}
	}

	sort(cows + nlower, cows + nhigher + 1, comp2);

	for (int i = 0; i < N; i++) {
		answer += cows[(3 * N) - (i + 1)].W_i;
		answer %= M;
	}
	answer %= M;
	cout << answer;
}


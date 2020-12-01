#include <iostream>

using namespace std;

int main()
{
	int N, K, B, blight, answer, range;
	answer = 100000;
	int broken[100001] = { 0 };
	int pf[100001] = { 0 };
	cin >> N >> K >> B;
	for (int i = 0; i < B; i++) {
		cin >> blight;
		broken[blight] = 1;
	}
	for (int i = 1; i <= N; i++) {
		if (broken[i] == 1) {
			pf[i] = pf[i - 1] + 1;
		}
		else {
			pf[i] = pf[i - 1];
		}
	}
	for (int i = K; i <= N; i++) {
		range = pf[i] - pf[i - K];
		if (range < answer) {
			answer = range;
		}
	}
	cout << answer;
}

#include <iostream>
#include <algorithm> 

using namespace std;

char moves[100001] = { 0 };
int Ppf[100001] = { 0 };
int Hpf[100001] = { 0 };
int Spf[100001] = { 0 };

int main()
{
	int N, answer, sum;
	answer = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> moves[i + 1];
	}

	for (int i = 1; i <= N; i++) {
		Ppf[i] = Ppf[i - 1];
		Hpf[i] = Hpf[i - 1];
		Spf[i] = Spf[i - 1];
		if (moves[i] == 'P') {
			Ppf[i] = Ppf[i - 1] + 1;
		}
		if (moves[i] == 'H') {
			Hpf[i] = Hpf[i - 1] + 1;
		}
		if (moves[i] == 'S') {
			Spf[i] = Spf[i - 1] + 1;
		}
	}

	for (int i = 0; i < N; i++) {
		sum = max(Ppf[i], max(Hpf[i], Spf[i])) + max(Ppf[N] - Ppf[i], max(Hpf[N] - Hpf[i], Spf[N] - Spf[i]));
		if (sum > answer) {
			answer = sum;
		}
	}

	cout << answer;
}

#include <iostream>

using namespace std;

int cows[100001] = { };
int Hpf[100001] = { 0 };
int Gpf[100001] = { 0 };
int Jpf[100001] = { 0 };
int start[100000] = { };
int ending[100000] = { };

int main()
{
	int N, Q;

	cin >> N >> Q;

	for (int i = 1; i <= N; i++) {
		cin >> cows[i];
		Hpf[i] = Hpf[i - 1];
		Gpf[i] = Gpf[i - 1];
		Jpf[i] = Jpf[i - 1];
		if (cows[i] == 1) {
			Hpf[i]++;
		}
		else if (cows[i] == 2) {
			Gpf[i]++;
		}
		else if (cows[i] == 3) {
			Jpf[i]++;
		}
	}
	
	for (int i = 0; i < Q; i++) { 
		cin >> start[i] >> ending[i];
	}

	for (int i = 0; i < Q; i++) {
		cout << Hpf[ending[i]] - Hpf[start[i] - 1] << " " << Gpf[ending[i]] - Gpf[start[i] - 1] << " " << Jpf[ending[i]] - Jpf[start[i] - 1] << endl;
	}
}


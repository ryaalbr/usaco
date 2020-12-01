#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

struct strint {
	string s;
	int i;
};

strint cows[50002] = {};

bool comp(strint a, strint b) {
	return a.i < b.i;
}

int main()
{
	int N, A, B, m;
	cin >> N >> A >> B;
	int count = 0;
	
	
	for (int i = 0; i < N; i++) {
		cin >> cows[i].s >> cows[i].i;
	}
	cows[N].s = "NS";
	cows[N].i = 2147483647;
	cows[N + 1].s = "NS";
	cows[N + 1].i = -2147483647;
	sort(cows, cows + N + 2, comp);
	//cows[N + 1].s = cows[N].s;

	for (int i = 0; i < N+1; i++) {
		if (cows[i + 1].i <= A) {
			continue;
		}

		m = (cows[i].i  / 2) + (cows[i + 1].i / 2) + ((cows[i + 1].i % 2 + cows[i].i % 2) / 2);
		if ((A <= m) && (cows[i].s == "S")) {
			count += (min(m, B) - max(cows[i].i, A) + 1);
		}

		if ((m<=B) && (cows[i + 1].s == "S")){
			count += (min(cows[i + 1].i - 1, B) - max(m + 1, A) + 1);
			if ((cows[i].s == "NS") && ((cows[i + 1].i + cows[i].i) % 2 == 0) && (A <= m) && (m <= B)) {
				count++;
			}
		}
		if (cows[i + 1].i > B) {
			break;
		}
		
		/*if (min(cows[i + 1].i - 1, B) - max(m1 + 1, A) + 1 < 0) {
			break;
		}*/
		
	}

	cout << count;
}

#include <iostream>
#include <algorithm>

using namespace std;
int diamonds[50000] = { 0 };

int main()
{
  int N, K, num1, num2, bestnum1, bestnum2, totalnum, besttotalnum;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> diamonds[i];
	}
	sort(diamonds, diamonds + N);
	besttotalnum = 0;
	for (int i = 0; i <= N; i++) {
		bestnum1 = 0;
		for (int j = 0; j < i; j++) {
			num1 = 0;
			for (int l = j; l < i; l++) {
				if (diamonds[l] <= diamonds[j] + K) {
					num1++;
				}
			}
			if (num1 > bestnum1) {
				bestnum1 = num1;
			}
		}
		bestnum2 = 0;
		for (int j = i; j <= N; j++) {
			num2 = 0;
			for (int l = j; l < N; l++) {
				if (diamonds[l] <= diamonds[j] + K) {
					num2++;
				}
			}
			if (num2 > bestnum2) {
				bestnum2 = num2;
			}
		}
		totalnum = bestnum1 + bestnum2;
		if (totalnum > besttotalnum) {
			besttotalnum = totalnum;
		}
	}
	cout << besttotalnum;
}

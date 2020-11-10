#include <iostream>
#include <algorithm>

using namespace std;
int diamonds[50000] = { 0 };
int uniquediamonds[50000] = { 0 };
int diamondsink[50000] = { 0 };
int smallD[50000] = { 0 };

int main()
{
	int N, K, num1, num2, bestnum1, bestnum2, totalnum, besttotalnum, ind, temp, temp2, temp3, uniqueN;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> diamonds[i]; // read diamonds
	}

	sort(diamonds, diamonds + N); // sort diamonds
	temp = 0;
	for (int i = 0; i < N; i++) { // create unique diamonds
		if (i > 0 && diamonds[i - 1] != diamonds[i]) {
			uniquediamonds[i - temp] = diamonds[i];
		}
		if (i == 0) {
			uniquediamonds[i] = diamonds[i];
		}
		if (i > 0 && diamonds[i - 1] == diamonds[i]) {
			temp++;
		}
	}

	uniqueN = N - temp; // # of unique diamonds

	temp3 = 0; 
	for (int i = 0; i < N; i++) { // create diamond in k for unique diamonds
		if (diamonds[i] > uniquediamonds[temp3]) {
			temp3++;
		}
		temp2 = i;
		diamondsink[temp3] = 0;
		while (diamonds[temp2] + K >= diamonds[i]) {
			diamondsink[temp3]++;
			temp2--;
			if (temp2 == -1) {
				break;
			}
		}
	}

	besttotalnum = 0;

	for (int i = 0; i < uniqueN; i++) { // calculate besttotalnum
		for (int j = 0; j < uniqueN; j++) {
			if (uniquediamonds[j] - K > uniquediamonds[i]) {
				totalnum = diamondsink[j] + diamondsink[i];
				if (besttotalnum < totalnum) {
					besttotalnum = totalnum;
				}
			}
		}
	}

	cout << besttotalnum;
}

#include <iostream>

using namespace std;

int main()
{
	int n, sum;
	int matrix[200][200] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	int best = -20000000;

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			for (int dir = 0; dir < 4; dir++) {
				sum = 0;
				for (int i = 0; i < n; i++) {
					if (dir == 0) {
						sum += matrix[(x + i) % n][y];
					}
					else if (dir == 1) {
						sum += matrix[x][(y + i) % n];
					}
					else if (dir == 2) {
						sum += matrix[(x + i) % n][(y + i) % n];
					}
					else if (dir == 3) {
						sum += matrix[(x - i + n) % n][(y + i) % n];
					}
					if (sum > best) {
						best = sum;
					}
				}
			}
		}
	}

	cout << best;
}

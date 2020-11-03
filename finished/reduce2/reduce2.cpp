#include <iostream>
#include <algorithm>

using namespace std;

struct doubint {
	int ind, cord;
};

bool comp(doubint a, doubint b){
	return a.cord < b.cord;
}

doubint cowsx[50000] = { };
doubint cowsy[50000] = { };
int edges[4] = { 0 };
int N, numofnecess, area;
int temp;

int cowindex(int side, int pos) {
	switch (side) {
	case 0 :
		return cowsx[pos].ind;
	case 1 :
		return cowsy[pos].ind;
	case 2:
		return cowsx[N - 1 - pos].ind;
	case 3:
		return cowsy[N - 1 - pos].ind;
	}
} 

void removecow(int side) {
	edges[side]++;
	temp = cowindex(side, edges[side] - 1);
	for (int l = 0; l < 4; l++) {
		if (l == side) {
			continue;
		}
		switch (l) {
		case 0 :
			if (cowsx[edges[0]].ind == temp) {
				edges[0]++;
			}
		case 1:
			if (cowsy[edges[1]].ind == temp) {
				edges[1]++;
			}
		case 2:
			if (cowsx[N - 1 - edges[2]].ind == temp) {
				edges[2]++;
			}
		case 3:
			if (cowsy[N - 1 - edges[3]].ind == temp) {
				edges[3]++;
			}
		}
	}
}

int main()
{
	int answer = 1600000000;
	bool inlist = true;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cowsx[i].cord >> cowsy[i].cord;
		cowsx[i].ind = i;
		cowsy[i].ind = i;
	}

	sort(cowsx, cowsx + N, comp);
	sort(cowsy, cowsy + N, comp);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				removecow(i);
				removecow(j);
				removecow(k);
				area = (cowsx[N - 1 - edges[2]].cord - cowsx[edges[0]].cord) * (cowsy[N - 1 - edges[3]].cord - cowsy[edges[1]].cord);
				if (answer > area) {
					answer = area;
				}
				edges[0] = 0;
				edges[1] = 0;
				edges[2] = 0;
				edges[3] = 0;
			}
		}
	}

	cout << answer;
}


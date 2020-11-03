#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std;

string ctos(char c1, char c2, char c3) {
	string str = "";
	str.append(1, c1);
	str.append(1, c2);
	str.append(1, c3);
	return str;
}

int main()
{
	int n, m, count;
	string temp1;
	count = 0;
	map<string, int> tripbases;
	string spotted[500] = { };
	string plain[500] = { };
	bool temp;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> spotted[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> plain[i];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < m; j++) {
			if (j > i) {
				for (int k = 2; k < m; k++) {
					if (k > j) {
						tripbases["AAA"] = 0;
						tripbases["AAC"] = 0;
						tripbases["AAG"] = 0;
						tripbases["AAT"] = 0;
						tripbases["ACA"] = 0;
						tripbases["ACC"] = 0;
						tripbases["ACG"] = 0;
						tripbases["ACT"] = 0;
						tripbases["AGA"] = 0;
						tripbases["AGC"] = 0;
						tripbases["AGG"] = 0;
						tripbases["AGT"] = 0;
						tripbases["ATA"] = 0;
						tripbases["ATC"] = 0;
						tripbases["ATG"] = 0;
						tripbases["ATT"] = 0;

						tripbases["CAA"] = 0;
						tripbases["CAC"] = 0;
						tripbases["CAG"] = 0;
						tripbases["CAT"] = 0;
						tripbases["CCA"] = 0;
						tripbases["CCC"] = 0;
						tripbases["CCG"] = 0;
						tripbases["CCT"] = 0;
						tripbases["CGA"] = 0;
						tripbases["CGC"] = 0;
						tripbases["CGG"] = 0;
						tripbases["CGT"] = 0;
						tripbases["CTA"] = 0;
						tripbases["CTC"] = 0;
						tripbases["CTG"] = 0;
						tripbases["CTT"] = 0;

						tripbases["GAA"] = 0;
						tripbases["GAC"] = 0;
						tripbases["GAG"] = 0;
						tripbases["GAT"] = 0;
						tripbases["GCA"] = 0;
						tripbases["GCC"] = 0;
						tripbases["GCG"] = 0;
						tripbases["GCT"] = 0;
						tripbases["GGA"] = 0;
						tripbases["GGC"] = 0;
						tripbases["GGG"] = 0;
						tripbases["GGT"] = 0;
						tripbases["GTA"] = 0;
						tripbases["GTC"] = 0;
						tripbases["GTG"] = 0;
						tripbases["GTT"] = 0;

						tripbases["TAA"] = 0;
						tripbases["TAC"] = 0;
						tripbases["TAG"] = 0;
						tripbases["TAT"] = 0;
						tripbases["TCA"] = 0;
						tripbases["TCC"] = 0;
						tripbases["TCG"] = 0;
						tripbases["TCT"] = 0;
						tripbases["TGA"] = 0;
						tripbases["TGC"] = 0;
						tripbases["TGG"] = 0;
						tripbases["TGT"] = 0;
						tripbases["TTA"] = 0;
						tripbases["TTC"] = 0;
						tripbases["TTG"] = 0;
						tripbases["TTT"] = 0;

						for (int l = 0; l < n; l++) {
							tripbases[ctos(spotted[l][i], spotted[l][j], spotted[l][k])] = 1;
						}

						temp = true;

						for (int l = 0; l < n; l++) {
							if (tripbases[ctos(plain[l][i], plain[l][j], plain[l][k])] == 1) {
								temp = false;
							}
						}
						
						if (temp) {
							count++;
						}
					}
				}
			}
		}
	}

	cout << count;
}

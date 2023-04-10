#include <iostream>

using namespace std;

int dict[255];
char seqence[8] = { 'E', 'H', 'I', 'K', 'L', 'R', 'S', 'T' };

int main() {
	// E H I K L R S T

	//cout <<( 7^ 1);
	
	for (int i = 0; i < 8; i++) {
		dict[(int)seqence[i]] = i;
	}
	//cout << dict['K'];

	char c1[6] = { 'K', 'H', 'H', 'L', 'T', 'K' };
	char c2[6] = { 'K', 'T', 'H', 'L', 'L', 'E' };

	while (true) {
		string s;
		char ret[6] = { 0 };
		cout << "Enter hypothesis of Plain text: ";
		cin >> s;
		cout << "C1 ^ P1 = K: ";
		for (int i = 0; i < 6; i++) {
			ret[i] = dict[(int)s[i]]^dict[(int)c1[i]];
			if(ret[i] < 8)
			cout << seqence[ret[i]];
		}
		cout << endl;
		cout << "K ^ C2 = P2: ";
		for (int i = 0; i < 6; i++) {
			ret[i] = ret[i] ^ dict[(int)c2[i]];
			if (ret[i] < 8)
				cout << seqence[ret[i]];
		}
		cout << endl;
	}

	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main () {
	int r,c;
	cin >> r >> c;
	char a[25][25];
	for (int i=1;i<=r;i++) {
		string s;
		cin >> s;
		for (int j=1;j<=c;j++) {
			a[i][j]=s[j-1];
		}
	}
	vector<string> words;
	for (int i=1;i<=r;i++) {
		string s="";
		for (int j=1;j<=c;j++) {
			if (a[i][j]=='#') {
				if (s.size()>=2) words.push_back(s);
				else s="";
			} else {
				s+=a[i][j];
			}
			if (j==c) {
				if (s.size()>=2) words.push_back(s);
			}
		}
	}
	for (int i=1;i<=c;i++) {
		string s="";
		for (int j=1;j<=r;j++) {
			if (a[j][i]=='#') {
				if (s.size()>=2) words.push_back(s);
				else s="";
			} else {
				s+=a[j][i];
			}
			if (j==r) {
				if (s.size()>=2) words.push_back(s);
			}
		}
	}
	sort (words.begin(),words.end());
	cout << words[0] << endl;
	return 0;
}

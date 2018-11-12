#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	getline(cin,s);
	s+=' ';
	vector<string> a;
	string x="";
	for (int i=0;i<s.size();i++) {
		if (s[i]==' ') {
			a.push_back(x);
			x="";
		} else x+=s[i];
	}
	int cnt=0;
	for (int i=0;i<a.size();i++) {
		bool y=0;
		for (int j=0;j<a[i].size()-1;j++) {
			if (a[i][j]=='a'&&a[i][j+1]=='e') y=1;
		}
		if (y) cnt++;
	}
	if ((double)cnt>=((double)a.size()*2/5)) cout << "dae ae ju traeligt va" << endl;
	else cout << "haer talar vi rikssvenska" << endl;
	return 0;
}

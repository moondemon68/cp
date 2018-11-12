#include <bits/stdc++.h>

using namespace std;

int transform (string s) {
	int ret=0;
	for (int i=0;i<s.size();i++) {
		ret+=s[i]-'0';
		ret*=10;
	}
	return ret;
}

int main () {
	int n;
	cin >> n;
	vector< pair<int,string> > a;
	for (int i=1;i<=n;i++) {
		string c,r;
		cin >> c >> r;
		if (c[0]>='a'&&c[0]<='z') {
			a.push_back(make_pair(transform(r)*2,c));
		}
		else a.push_back(make_pair(transform(c),r));
	}
	sort (a.begin(),a.end());
	for (int i=0;i<a.size();i++) {
		cout << a[i].second << endl;
	}
	return 0;
}

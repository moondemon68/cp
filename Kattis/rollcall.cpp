#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<string,string> a, pair<string,string> b) {
	if (a.second==b.second) return a.first<b.first;
	else return a.second<b.second;
}

int main () {
	string a,b;
	vector< pair<string,string> > s;
	while (cin >> a >> b) {
		s.push_back(make_pair(a,b));
	}
	sort (s.begin(),s.end(),cmp);
	bool t[205];
	memset (t,0,sizeof(t));
	for (int i=0;i<s.size()-1;i++) {
		for (int j=i+1;j<s.size();j++) {
			if (s[i].first==s[j].first) {
				t[i]=1; t[j]=1;
			}
		}
	}
	for (int i=0;i<s.size();i++) {
		if (t[i]) cout << s[i].first << " " << s[i].second << endl;
		else cout << s[i].first << endl;
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b) {
	if (a.first==b.first) return a.second>b.second;
	else return a.first<b.first;
}

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int g,m;
		cin >> g >> m;
		vector< pair<int,int> > a;
		for (int i=1;i<=g;i++) {
			int x;
			cin >> x;
			a.push_back(make_pair(x,1));
		}
		for (int i=1;i<=m;i++) {
			int x;
			cin >> x;
			a.push_back(make_pair(x,2));
		}
		sort (a.begin(),a.end(),cmp);
		if (a[a.size()-1].second==1) cout << "Godzilla" << endl; else cout << "MechaGodzilla" << endl;
	}
	return 0;
}

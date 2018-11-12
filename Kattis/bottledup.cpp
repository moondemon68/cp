#include <bits/stdc++.h>

using namespace std;

bool cmp (pair<int,int> a,pair<int,int> b) {
	return a.first+a.second<b.first+b.second;
}

int main () {
	int s,v1,v2;
	cin >> s >> v1 >> v2;
	vector< pair<int,int> > ans;
	for (int i=0;i<=(s+v1-1)/v1;i++) {
		for (int j=0;j<=(s+v2-1)/v2;j++) {
			if (v1*i+v2*j==s) {
				ans.push_back(make_pair(i,j));
			}
			if (v1*i+v2*j>s) {
				break;
			}
		}
		if (v1*i>s) break;
	}
	sort (ans.begin(),ans.end(),cmp);
	if (ans.empty()) cout << "Impossible" << endl;
	else cout << ans[0].first << " " << ans[0].second << endl;
	return 0;
}

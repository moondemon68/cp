#include <bits/stdc++.h>

using namespace std;

int main () {
	string s;
	vector<int> p;
	int x=0;
	while (getline(cin,s)) {
		p.push_back(s.size());
	}
	x=p[p.size()-1];
	sort (p.begin(),p.end());
	int ans=0;
	for (int i=0;i<p.size();i++) {
		ans+=pow(p[p.size()-1]-p[i],2);
		//cout << ans << endl;
	}
	ans-=pow(p[p.size()-1]-x,2);
	cout << ans << endl;
	return 0;
}

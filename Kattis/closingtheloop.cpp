#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		int n;
		cin >> n;
		pair<int,char> a[1005];
		priority_queue<int> r,b;
		for (int i=1;i<=n;i++) {
			string s;
			cin >> s;
			int x=0;
			for (int i=0;i<s.size()-1;i++) {
				x+=s[i]-'0';
				x*=10;
			}
			x/=10;
			a[i].first=x;
			a[i].second=s[s.size()-1];
			if (a[i].second=='R') r.push(a[i].first); else b.push(a[i].first);
		}
		int ans=0,cnt=0;
		while (!r.empty()&&!b.empty()) {
			ans+=r.top();
			ans+=b.top();
			r.pop();
			b.pop();
			cnt+=2;
		}
		cout <<"Case #" << t << ": "<< max(0,ans-cnt) << endl;
	}
}

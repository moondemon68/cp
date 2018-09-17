#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	long long k;
	cin >> n >> k;
	int cnt=0;
	long long ans=0;
	priority_queue<long long,vector<long long>,greater<long long> > a;
	for (int i=1;i<=n;i++) {
		long long x;
		cin >> x;
		if (x<k) cnt++;
		a.push(x);
	}
	while (a.size()>1&&cnt>0) {
		long long x=a.top();
		//cout << x << endl;
		a.pop();
		if (x<k) cnt--;
		long long y=a.top();
		a.pop();
		if (x<k) cnt--;
		ans++;
		if ((x+y+y)<k) cnt++;
		a.push(x+y+y);
	}
	if (a.top()>=k) cnt=0;
	if (cnt==0) cout << ans << endl;
	else cout << -1 << endl;
	return 0; 
}

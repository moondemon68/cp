#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	long long ans=0;
	priority_queue<long long,vector<long long>,greater<long long> > a;
	for (int i=1;i<=n;i++) {
		long long x;
		cin >> x;
		a.push(x);
	}
	while (a.size()!=1) {
		long long x=a.top();
		a.pop();
		long long y=a.top();
		a.pop();
		ans+=x+y;
		a.push(x+y);
	}
	cout << ans << endl;
	return 0;
}

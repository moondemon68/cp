#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b) {
	if(a.first==b.first) return a.second<b.second;
	else return a.first>b.first;
}

int main() {
		// your code goes here
		int n;
		cin >> n;
		assert(n!=1);
		int a[100005],b[100005];
		priority_queue<int,vector<int>,greater<int> > p;
		for (int i=1;i<=n;i++) cin >> a[i] >> b[i];
		int ans=0;
		for (int i=1;i<=n;i++) ans+=b[i];
		ans+=a[n]-b[n];
		//cout << ans << endl;
		for (int i=n-1;i>1;i-=2) {
			p.push(a[i]-b[i]);
			p.push(a[i-1]-b[i-1]);
			ans+=p.top();
			p.pop();
		}
		//cout<<ans << " " << f.size() << endl;

		cout<<ans<<endl;
		return 0;
}

#include <bits/stdc++.h>

using namespace std;

long long a[200005];
vector<long long> mod[11];
int main () {
	int n;
	cin >> n;
	long long k;
	cin >> k;
	for (int i=1;i<=n;i++) {
		cin >> a[i];	
		long long x=a[i];
		for (int j=1;j<=10;j++) {
			x*=10;
			x%=k;
			mod[j].push_back(x%k);
		}
	}
	for (int i=1;i<=10;i++) {
		sort (mod[i].begin(),mod[i].end());
		//for (int j=0;j<n;j++) {
		//	cout << mod[i][j] << " ";
		//}
		//cout << endl;
		//sort (mod[i].begin(),mod[i].end());
	}
	long long ans=0;
	for (int i=1;i<=n;i++) {
		long long x=a[i];
		long long cnt=0;
		while (x>0) {
			cnt++;
			x/=10;
		}
		//cout << a[i]%k << " = ";
		//for (int j=0;j<n;j++) {
		//	cout << mod[cnt][j] << " ";
		//}
		//cout << endl;
		auto p=lower_bound(mod[cnt].begin(),mod[cnt].end(),k-(a[i]%k));
		auto q=upper_bound(mod[cnt].begin(),mod[cnt].end(),k-(a[i]%k));	
		//cout << q-p << " ";
		ans+=q-p;
		if (a[i]%k==0) {
			p=lower_bound(mod[cnt].begin(),mod[cnt].end(),0);
			q=upper_bound(mod[cnt].begin(),mod[cnt].end(),0);
			ans+=q-p;
		}
		long long y=a[i];
		for (int p=1;p<=cnt;p++) {
			y*=10;
			y%=k;
		}
		if (a[i]%k+y%k==k||a[i]%k+y%k==0) ans--;
	}
	cout << ans << endl;
}

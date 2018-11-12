#include <bits/stdc++.h>

using namespace std;

int main () {
	int n,p;
	cin >> n >> p;
	int a[100005];
	a[0]=0;
	for (int i=1;i<=n;i++) {
		cin >> a[i];
		a[i]-=p;
	}
	int ans=0;
	for (int i=1;i<=n;i++) {
		a[i]+=a[i-1];
		if (a[i]<0) a[i]=0;
		ans=max(ans,a[i]);
	}
	cout << ans << endl;
	return 0;
}

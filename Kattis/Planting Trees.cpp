#include<bits/stdc++.h>

using namespace std;

bool cmp(int x,int y) {
	return x>y;
}

int main () {
	int n;
	cin >> n;
	int a[100005];
	for (int i=1;i<=n;i++) cin >> a[i];
	sort (a+1,a+n+1,cmp);
	int ans=n+1;
	for (int i=1;i<=n;i++) {
		a[i]=max(0,a[i]-(n-i+1));
	}
	int maxi=0;
	for (int i=1;i<=n;i++) {
		maxi=max(maxi,a[i]);
	}
	ans+=maxi+1;
	cout << ans << endl;
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	bool prima[1000005];
	vector<int> p;
	memset (prima,1,sizeof(prima));
	for (int i=2;i*i<=1000000;i++) {
		for (int j=i*i;j<=1000000;j+=i) {
			prima[j]=0;
		}
	}
	for (int i=2;i<=1000000;i++) {
		if (prima[i]) p.push_back(i);
	}
	while (1>0) {
		cin >> n;
		if (n==0) return 0;
		int ans=0;
		for (int i=0;p[i]*p[i]<=n;i++) {
			int x=n,cnt=0;
			while (x%p[i]==0) {
				x/=p[i];
				cnt++;
				if (x==1||p[i]==0) break;
			}
			if (x==1) {
				ans=max(ans,cnt);
				break;
			}
		}
		if (ans==0) ans++;
		cout << ans << endl;
	}
	return 0;
}

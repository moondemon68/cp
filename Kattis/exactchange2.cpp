#include <bits/stdc++.h>

using namespace std;

int dp[20005],a[105];
int n,change;			//types,change

int main () {
	int tc;
	cin >> tc;
	for (int t=1;t<=tc;t++) {
		cin >> change >> n;
		memset (dp,-1,sizeof(dp));
		memset (a,0,sizeof(a));
		for (int i=1;i<=n;i++) cin >> a[i];
		dp[0]=0;
		for (int i=1;i<=n;i++) {
			for (int j=change;j>=0;j--) {
				if (dp[j]==-1) continue;
				if (dp[j+a[i]]==-1||dp[j+a[i]]>dp[j]+1) {
					dp[j+a[i]]=dp[j]+1;
				}
			}
		}
		int ans=0;
		for (int i=change;i<=1000000;i++) {
			if (dp[i]!=-1) {
				ans=i;
				break;
			}
		}
		cout << ans << " " << dp[ans] << endl;
	}
	return 0;
}

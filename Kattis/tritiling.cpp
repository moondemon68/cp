#include <bits/stdc++.h>

using namespace std;

int dp[375];

int solve(int x) {
	if (dp[x]!=-1) return dp[x];
		int sum=3*solve(x-2);
		for (int j=4;j<=x;j+=2) {
			sum+=2*solve(x-j);
		}
	return dp[x]=sum;
}

int main () {
	int n;
	memset (dp,-1,sizeof(dp));
	dp[0]=1;
	while (1>0) {
		cin >> n;
		if (n==-1) return 0;
		if (n%2==1) {
			cout << 0 << endl;
			continue;
		}
		cout << solve(n) << endl;
	}
	return 0;
}

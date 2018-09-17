#include <bits/stdc++.h>
#define MOD 1000000

using namespace std;

int dp[1000005];

int solve(int x) {
	if (dp[x]!=-1) return dp[x];
	dp[x]=solve(x-sqrt(x))+solve(log(x))+solve(x*sin(x)*sin(x));
	dp[x]%=MOD;
	return dp[x];
}

int main () {
	memset (dp,-1,sizeof(dp));
	dp[0]=1;
	int n;
	while (cin >> n) {
		if (n==-1) return 0;
		cout << solve(n) << endl;
	}
	return 0;
}

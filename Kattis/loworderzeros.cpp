#include <bits/stdc++.h>

using namespace std;

int dp[1000005];

int solve(int n) {
	if (dp[n]!=-1) return dp[n];
	if (((n%100)/10)%2==1) return dp[n]=4*solve(n/5)*dp[n%10];
	else return dp[n]=6*solve(n/5)*dp[n%10];
}

int main () {
	int n;
	memset (dp,-1,sizeof(dp));
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	dp[3]=6;
	dp[4]=4;
	dp[5]=2;
	dp[6]=2;
	dp[7]=4;
	dp[8]=2;
	dp[9]=8;
	while (1>0) {
		cin >> n;
		if (n==0) return 0;
		else cout << solve(n)%10 << endl;
	}
	return 0;
}

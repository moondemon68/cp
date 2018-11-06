#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

map<LL,LL> dp;
LL solve(LL n) {
  if (n==0) return 0;
  if (dp[n]!=0) return dp[n];
  return dp[n]=max(n,solve(n/2)+solve(n/3)+solve(n/4));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    while (cin >> n) {
      cout << solve(n) << endl;
    }
    return 0;
}

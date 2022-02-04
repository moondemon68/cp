#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

int distinctSubseqII(string s) {
    const int N = s.length();
    
    vector<int> dp(N+1);
    dp[0] = 1;
    vector<int> last(26, -1);
    
    for(int i = 0; i < N; i++){
        int x = s[i] - 'a';
        dp[i+1] = dp[i] * 2 % MOD;
        if(last[x] >= 0) // if this is the first occurence of ch
            dp[i+1] -= dp[last[x]];
        dp[i+1] %= MOD;
        last[x] = i;
    }
    dp[N]--;
    if(dp[N] < 0) dp[N] += MOD;
    return dp[N];
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    s = "abab";
    cout << distinctSubseqII(s) << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
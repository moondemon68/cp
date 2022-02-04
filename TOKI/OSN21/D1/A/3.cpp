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

int dp[3005][3005];
int n, m, k;
string s;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    if (s[0] == '?') dp[1][1] = 2;
    else dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (s[i-1] == '?') {
                dp[i][j] = 
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
5 1
0 0 0 0 0 32
5 2
2 8 12 8 2 0
5 3
16 10 4 2 0 0
5 4
26 4 2 0 0 0
5 5
30 2 0 0 0 0
*/
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

int a[10005];
int dp[10005][10005];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    int gap, l, h;
    for (gap = 1; gap < n; ++gap)  
        for (l = 0, h = gap; h < n; ++l, ++h)  
            dp[l][h] = (a[l] == a[h])?  
                        dp[l + 1][h - 1] :  
                        (min(dp[l][h - 1],  
                             dp[l + 1][h]) + 1);  
    cout << dp[0][n-1] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
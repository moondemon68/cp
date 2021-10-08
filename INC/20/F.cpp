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

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt[n+5][30];
    memset (cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) {
        cnt[i][s[i-1]-'A']++;
    }
    for (int i=1;i<=n;i++) {
        for (int j=0;j<26;j++) {
            cnt[i][j] += cnt[i-1][j];
            // cerr << cnt[i][j] << " ";
        }
        // cerr << endl;
    }
    int ans = k;
    for (int i=1;i<=n-k+1;i++) {
        for (int j=0;j<26;j++) {
            ans = min(ans, k - (cnt[i+k-1][j] - cnt[i-1][j]));
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
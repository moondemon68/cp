#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    while (cin >> n) {
        if (n==-1) return 0;
        bool a[n+5][n+5];
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) cin >> a[i][j];
        }    
        for (int i=1;i<=n;i++) {
            bool y=0;
            for (int j=1;j<=n;j++) {
                for (int k=j+1;k<=n;k++) {
                    if (a[i][j]&&a[i][k]&&a[j][k]) y=1;
                }
            }
            if (!y) cout << i-1 << " ";
        }
    }
    return 0;
}

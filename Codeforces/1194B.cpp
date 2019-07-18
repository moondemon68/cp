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
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int r,c;
        cin >> r >> c;
        char a[r+5][c+5];
        for (int i=1;i<=r;i++) {
            string s;
            cin >> s;
            for (int j=1;j<=c;j++) {
                a[i][j]=s[j-1];
            }
        }
        int row[r+5],col[c+5];
        memset (row,0,sizeof(row));
        memset (col,0,sizeof(col));
        for (int i=1;i<=r;i++) {
            for (int j=1;j<=c;j++) {
                if (a[i][j]=='*') {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int ans=INT_MAX;
        for (int i=1;i<=r;i++) {
            for (int j=1;j<=c;j++) {
                if (a[i][j]=='*') ans=min(ans,r+c-row[i]-col[j]);
                else ans=min(ans,r+c-row[i]-col[j]-1);
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
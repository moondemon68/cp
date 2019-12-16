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
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        int n = s.size();
        int a[4][2*n+5];
        s+=s;
        memset (a,0,sizeof(a));
        for (int i=1;i<=2*n;i++) {
            if (s[i-1]=='A') a[0][i]=1;
            else if (s[i-1]=='B') a[1][i]=1;
            else if (s[i-1]=='C') a[2][i]=1;
            else a[3][i]=1;
        }
        for (int i=0;i<4;i++) {
            for (int j=1;j<=2*n;j++) {
                a[i][j]+=a[i][j-1];
                // cout << a[i][j] << " ";
            }
        // cout << endl;
        }
        int ca=a[0][n],cb=a[1][n],cc=a[2][n],cd=a[3][n];
        int b[4];
        for (int i=0;i<4;i++)  b[i]=i;
        int p[5];
        int ans=INT_MAX;
        do {
            p[0]=0;
            p[1]=a[b[0]][n] + p[0];
            p[2]=a[b[1]][n] + p[1];
            p[3]=a[b[2]][n] + p[2];
            p[4]=a[b[3]][n] + p[3];
            int maxi = 0;
            for (int i=0;i<n;i++) {
                int tot = 0;
                p[0]++; p[1]++; p[2]++; p[3]++; p[4]++;
                tot += a[b[0]][p[1]]-a[b[0]][p[0]];
                tot += a[b[1]][p[2]]-a[b[1]][p[1]];
                tot += a[b[2]][p[3]]-a[b[2]][p[2]];
                tot += a[b[3]][p[4]]-a[b[3]][p[3]];
                maxi = max (maxi, tot);
            }
            ans = min(ans,n-maxi);
            //cout << p[0] << " " << p[1] << " " << p[2] << " " << p[3] << " " << p[4] << endl;
        } while (next_permutation(b,b+4));
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
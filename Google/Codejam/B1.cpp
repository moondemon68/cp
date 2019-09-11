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
    for (int t=1;t<=tc;t++) {
        int n,q;
        cin >> n >> q;
        int a[105][105];
        memset (a,0,sizeof(a));
        int addx[q+5],addy[q+5];
        memset (addx,0,sizeof(addx));
        memset (addy,0,sizeof(addy));
        for (int i=1;i<=n;i++) {
            int x,y;
            char z;
            cin >> x >> y >> z;
            if (z=='N') {
                for (int j=y+1;j<=q;j++) addy[j]++; 
            }
            if (z=='S') {
                for (int j=0;j<=y-1;j++) addy[j]++;
            }
            if (z=='E') {
                for (int j=x+1;j<=q;j++) addx[j]++;
            }
            if (z=='W') {
                for (int j=0;j<=x-1;j++) addx[j]++;
            }
        }
        int ansx=0,ansy=0,maxi=0;
        for (int i=0;i<=q;i++) {
            if (addx[i]>maxi) {
                maxi=addx[i];
                ansx=i;
            }
        }
        maxi=0;
        for (int i=0;i<=q;i++) {
            if (addy[i]>maxi) {
                maxi=addy[i];
                ansy=i;
            }
        }
        cout << "Case #" << t << ": " << ansx << " " << ansy << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
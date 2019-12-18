#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

map<LL,LL> m;

LL a(LL x) {
    if (x == 1) return 1;
    else if (m[x]!=0) return m[x];
    else if (x%2==0) return 3*a(x/2);
    else return 2*a(x/2+1)+a(x/2);
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int l=0;l<=40;l++) {
        for (int r=0;r<=40;r++) {
            int ans=0;
            for (int i=l;i<=r;i++) {
                for (int j=l;j<=r;j++) {
                    if ((i&j) == 0) ans++;
                }
            }
            cout << ans << " ";
        }
        cout << endl;
    }
    // cout << a(1000000000) << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
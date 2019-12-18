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
    int l,r;
    cin >> l >> r;
    int ans=0;
    for (int i=l;i<=r;i++) {
        int x=i;
        int a[11];
        memset (a,0,sizeof(a));
        while (x) {
            a[x%10]++;
            x/=10;
        }
        bool y=1;
        for (int j=0;j<=9;j++) {
            if (a[j]>1) y=0;
        }
        if (y) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
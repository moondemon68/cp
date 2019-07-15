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
    int n,q;
    cin >> n >> q;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    while (q--) {
        int x;
        cin >> x;
        bool y=0;
        int l=1,h=n;
        while (l<=h) {
            int m=(l+h)/2;
            if (x==a[m]) {
                y=1;
                break;
            } else if (x<a[m]) {
                h=m-1;
            } else l=m+1;
        }
        if (y) cout << "ada" << endl;
        else cout << "tidak ada" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
        int n;
        cin >> n;
        LL a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        sort (a+1,a+n+1);
        LL x=a[1]*a[n];
        //cout << x << endl;
        for (int i=2;i<=n/2+1;i++)  {
            //cout << a[i] << " " << a[n-i+1] << endl;
            if (a[i]*a[n-i+1]!=x) {
                x=-1;
            }
        }
        int f=0;
        for (LL i=2;i*i<=x;i++) {
            if (x%i==0) {
                if (x==i*i) f++; else f+=2;
            }
        }
        if (f!=n) x=-1;
        cout << x << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
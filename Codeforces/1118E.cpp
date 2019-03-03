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
    clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,k;
    cin >> n >> k;
    if (n<=k) {
        LL a=1,b=2;
        cout << "YES" << endl;
        for (LL i=1;i<=n;i++) {
            cout << a << " " << b << endl;
            a++;
            if (a>k) a-=k;
            b++;
            if (b>k) b-=k;
        }
    } else {
        if (n>k*(k-1)) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for (int i=1;i<=k;i++) {
                for (int j=i+1;j<=k;j++) {
                    if (n==0) break;
                    cout << i << " " << j << endl;
                    n--;
                    if (n==0) break;
                    cout << j << " " << i << endl;
                    n--;
                }
            }
        }
    }
    cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
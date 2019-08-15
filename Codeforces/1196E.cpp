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
    int q;
    cin >> q;
    while (q--) {
        int b,w;
        cin >> b >> w;
        if (b<=w&&(b-1)<=w&&w<=3*b) {
            cout << "YES" << endl;
            for (int i=1;i<=b;i++) cout << "2 " << (2*i-1) << endl;
            for (int i=1;i<=min(w,b);i++) cout << "2 " << (2*i) << endl;
            w-=min(w,b);
            for (int i=1;i<=w;i++) {
                if (i%2==1) cout << "1 " << (2*i-1) << endl;
                else cout << "3 " << (2*i-1) << endl; 
            }
        } else if (w<=b&&(w-1)<=b&&b<=3*w) {
            cout << "YES" << endl;
            for (int i=1;i<=w;i++) cout << "3 " << (2*i-1) << endl;
            for (int i=1;i<=min(w,b);i++) cout << "3 " << (2*i) << endl;
            b-=min(w,b);
            for (int i=1;i<=b;i++) {
                if (i%2==1) cout << "2 " << (2*i-1) << endl;
                else cout << "4 " << (2*i-1) << endl; 
            }
        } else cout << "NO" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
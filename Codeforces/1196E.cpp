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
        if (w>=b&&b<=3*w+1) {
            cout << "YES" << endl;
            int m=-1,x=2,y=2;
            while (b--) {
                m++;
                m%=4;
                if (m==0) cout << x << " " << y-1 << endl;
                else if (m==1) cout << x-1 << " " << y << endl;
                else if (m==2) cout << x+1 << " " << y << endl;
                else {
                    cout << x << " " << y+1 << endl;
                    y+=2;
                }
            }
            while (y>=2) {
                w--;
                cout << x << " " << y << endl;
                y-=2;
            }
            m=-1; y=1;
            while (w--) {
                m++;
                m%=2;
                if (m==0) cout << 1 << " " << y << endl;
                else {
                    cout << 3 << " " << y << endl;
                    y+=2;
                }
            }
        } else if (b>=w&&w<=3*b+1) {
            cout << "YES" << endl;
            int m=-1,x=2,y=3;
            while (w--) {
                m++;
                m%=4;
                if (m==0) cout << x << " " << y-1 << endl;
                else if (m==1) cout << x-1 << " " << y << endl;
                else if (m==2) cout << x+1 << " " << y << endl;
                else {
                    cout << x << " " << y+1 << endl;
                    y+=2;
                }
            }
            while (y>=3) {
                b--;
                cout << x << " " << y << endl;
                y-=2;
            }
            m=-1; y=2;
            while (b--) {
                m++;
                m%=2;
                if (m==0) cout << 1 << " " << y << endl;
                else {
                    cout << 3 << " " << y << endl;
                    y+=2;
                }
            }
        } else {
            cout << "NO" << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
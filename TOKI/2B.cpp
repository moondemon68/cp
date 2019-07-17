#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL r,col,q;
    cin >> r >> col >> q;
    cout << "? 1 1" << endl;
    LL w,x,y,z,m;
    cin >> w;
    cout << "? 1 " << col << endl;
    cin >> x;
    cout << "? " << r << " 1" << endl;
    cin >> y;
    cout << "? " << r << " " << col << endl;
    cin >> z;
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=col;j++) {
            for (int k=1;k<=r;k++) {
                for (int l=1;l<=col;l++) {
                    if (min(i-1+j-1,k-1+l-1)==w&&min(i-1+col-j,k-1+col-l)==x&&min(r-i+j-1,r-k+l-1)==y&&min(r-i+col-j,r-k+col-l)==z) {
                        int p,pp;
                        cout << "? " << i << " " << j << endl;
                        cin >> p;
                        if (p!=0) continue;
                        cout << "? " << k << " " << l << endl;
                        cin >> pp;
                        if (p==0&&pp==0) {
                            cout << "! " << i << " " << j << " " << k << " " << l << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
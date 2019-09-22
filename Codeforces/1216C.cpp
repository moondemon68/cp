#include <bits/stdc++.h>
#define x1 first.first
#define y1 first.second
#define x2 second.first
#define y2 second.second
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
    pair<pii,pii> w,b,c;
    cin >> w.x1 >> w.y1 >> w.x2 >> w.y2 >> b.x1 >> b.y1 >> b.x2 >> b.y2 >> c.x1 >> c.y1 >> c.x2 >> c.y2;
    if (b.x2>=w.x2&&b.y2>=w.y2&&b.x1<=w.x1&&b.y1<=w.y1) {
        cout << "NO" << endl;
        return 0;
    }
    else if (c.x2>=w.x2&&c.y2>=w.y2&&c.x1<=w.x1&&c.y1<=w.y1) {
        cout << "NO" << endl;
        return 0;
    }
    else {
        pair<pii,pii> g;
        if (b.y1<=c.y1&&b.y2>=c.y1) {
            g.y1=b.y1;
            g.y2=max(b.y2,c.y2);
            g.x1=max(b.x1,c.x1);
            g.x2=min(b.x2,c.x2);
            if (g.x2>=w.x2&&g.y2>=w.y2&&g.x1<=w.x1&&g.y1<=w.y1) {
                cout << "NO" << endl;
                return 0;
            }
        }
        swap(b,c);
        if (b.y1<=c.y1&&b.y2>=c.y1) {
            g.y1=b.y1;
            g.y2=max(b.y2,c.y2);
            g.x1=max(b.x1,c.x1);
            g.x2=min(b.x2,c.x2);
            if (g.x2>=w.x2&&g.y2>=w.y2&&g.x1<=w.x1&&g.y1<=w.y1) {
                cout << "NO" << endl;
                return 0;
            }
        }
        swap(b,c);
        if (b.x2>=c.x1&&c.x2>=b.x2) {
            g.y1=max(b.y1,c.y1);
            g.y2=min(b.y2,c.y2);
            g.x1=min(b.x1,c.x1);
            g.x2=max(b.x2,c.x2);
            if (g.x2>=w.x2&&g.y2>=w.y2&&g.x1<=w.x1&&g.y1<=w.y1) {
                cout << "NO" << endl;
                return 0;
            }
        }
        swap(b,c);
        if (b.x2>=c.x1&&c.x2>=b.x2) {
            g.y1=max(b.y1,c.y1);
            g.y2=min(b.y2,c.y2);
            g.x1=min(b.x1,c.x1);
            g.x2=max(b.x2,c.x2);
            if (g.x2>=w.x2&&g.y2>=w.y2&&g.x1<=w.x1&&g.y1<=w.y1) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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

vector<pair<pii, pair<int, char>>> v;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x,y,n;
    cin >> x >> y >> n;
    int lx = 0, hx = x, ly = 0, hy = y;
    int quad;
    char dir;
    while ((hx - lx) > 2 || (hy - ly) > 2) {
        int mx = (lx + hx) / 2;
        int my = (ly + hy) / 2;
        // cerr << lx << " " << hx << " " << ly << " " << hy << endl;
        cout << "? " << mx << " " << my << endl;
        cin >> quad >> dir;
        v.pb({{mx, my}, {quad, dir}});
        if (quad == 1) {
            lx = mx;
            ly = my;
        } else if (quad == 2) {
            hx = mx;
            ly = my;
        } else if (quad == 3) {
            hx = mx;
            hy = my;
        } else {
            lx = mx;
            hy = my;
        }

        if (dir == 'U') {
            ly++;
            hy++;
        } else if (dir == 'D') {
            ly--;
            hy--;
        } else if (dir == 'L') {
            lx--;
            hx--;
        } else if (dir == 'R') {
            lx++;
            hx++;
        }

        if (lx <= 0) lx = 0;
        if (ly <= 0) ly = 0;
        if (hx >= x) hx = x;
        if (hy >= y) hy = y;
    }
    // binser sampe hx - lx <= 2 && hy - ly <= 2
    // cerr << "Last: " << lx << " " << hx << " " << ly << " " << hy << endl;
    int mx = (hx + lx) / 2, my = (hy + ly) / 2;
    int p = -1;
    for (int i=0;i<v.size();i++) {
        if (v[i].fi.fi == mx && v[i].fi.se == my) {
            p = i;
        }
    }
    // if (p == -1) {
    //     cout << "? " << mx << " " << my << endl;
    //     cin >> quad >> dir;
    // } else {
    //     quad = v[p].se.fi;
    //     dir = v[p].se.se;
    //     if (dir != 'S') {
    //         cout << "? " << mx << " " << my << endl;
    //         cin >> quad >> dir;
    //     }
    // }
    cout << "? " << mx << " " << my << endl;
    cin >> quad >> dir;
    if (quad == 1) {
        my++;
        mx++;
    } else if (quad == 2) {
        my++;
    } else if (quad == 3) {

    } else {
        mx++;
    }
    if (dir == 'U') {
        my++;
    } else if (dir == 'D') {
        my--;
    } else if (dir == 'L') {
        mx--;
    } else if (dir == 'R') {
        mx++;
    }
    cout << "! " << mx << " " << my << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
1000000 1000000 20
1 S
1 S
1 S
1 S
1 S
1 S
1 S
1 S
1 S
1 S
1 S
1 S
1 S
1 S
1 S
1 S
1 S
1 S
1 S
1 D

1000000 1000000 20
3 S
3 S
3 S
3 S
3 S
3 S
3 S
3 S
3 S
3 S
3 S
3 S
3 S
3 S
3 S
3 S
3 S
3 S
3 S
1 U

5 6 20
3 S
3 S
3 S
3 S
3 S
3 S
*/
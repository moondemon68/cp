#include <bits/stdc++.h>
#define xx first.first
#define yy first.second
#define zz second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

int n;
bitset<2000005> maze;
int a[2000005];
bool sisi(pair<pii,int> v) {
    if (v.xx != 1 && v.xx != n && v.yy != 1 && v.yy != n && v.zz != 1 && v.zz != n) return 0;
    return 1;
}

bool dalem(pair<pii,int> v) {
    if (v.xx >= 1 && v.xx <= n && v.yy >= 1 && v.yy <= n && v.zz >= 1 && v.zz <= n) return 1;
    return 0;
}

int trans(pair<pii,int> v) {
    int ret = 0;
    if (v.xx == 1) ret = v.yy * n + v.zz;
    if (v.xx == n) ret = n*n + v.yy * n + v.zz;
    if (v.yy == 1) ret = 2*n*n + v.xx * n + v.zz;
    if (v.yy == n) ret = 3*n*n + v.xx * n + v.zz;
    if (v.zz == 1) ret = 4*n*n + v.xx * n + v.yy;
    if (v.zz == n) ret = 5*n*n + v.xx * n + v.yy;
    return ret;
}

queue<pair<pii,int>> q;
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                maze[trans({{i,j},1})] = 0;
                maze[trans({{i,j},n})] = 0;
                maze[trans({{i,1},j})] = 0;
                maze[trans({{i,n},j})] = 0;
                maze[trans({{1,i},j})] = 0;
                maze[trans({{n,i},j})] = 0;
                a[trans({{i,j},1})] = 0;
                a[trans({{i,j},n})] = 0;
                a[trans({{i,1},j})] = 0;
                a[trans({{i,n},j})] = 0;
                a[trans({{1,i},j})] = 0;
                a[trans({{n,i},j})] = 0;
            }
        }
        int m;
        cin >> m;
        for (int i=1;i<=m;i++) {
            int x,y,z;
            cin >> x >> y >> z;
            if (!sisi({{x,y},z})) continue;
            maze[trans({{x,y},z})] = 1;
        }
        int sx, sy, sz;
        cin >> sx >> sy >> sz;
        int fx, fy, fz;
        cin >> fx >> fy >> fz;

        a[trans({{sx, sy}, sz})] = 1;
        q.push({{sx, sy}, sz});
        
        // int cnt = 0;
        while (!q.empty()) {
            pair<pii,int> cur = q.front();
            // cnt++;
            q.pop();
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dz = -1; dz <= 1; dz++) {
                        if (abs(dx) + abs(dy) + abs(dz) != 1) continue;
                        pair<pii,int> next = {{cur.xx+dx, cur.yy+dy}, cur.zz+dz};
                        if (!sisi(next) || !dalem(next)) continue;
                        if (maze[trans(next)]) continue;
                        if (a[trans(next)] != 0) continue;
                        a[trans(next)] = a[trans(cur)] + 1;
                        q.push(next);
                    }
                }
            }
        }
        // cout << cnt << endl;
        
        cout << a[trans({{fx,fy},fz})]-1 << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
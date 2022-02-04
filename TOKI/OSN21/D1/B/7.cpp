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

const int MAXN = 2000;
int p[MAXN+5][MAXN+5];
bool vis[MAXN+5][MAXN+5];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    bool y = 0;
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans = 0;
        int p = 1;
        for (int i=1;i<=33;i++) {
            p *= 2;
            if (p > a) break;
        }

    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
/*
12 12 3
1 1 9 8
8 8 11 11
4 3 5 9
*/
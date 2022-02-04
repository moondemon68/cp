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

const int MAXN = 1e5;
LL a[MAXN+5], b[MAXN+5];
vector<int> adj[MAXN + 5];
int color = 0;
int c[MAXN+5];
LL sum[MAXN+5];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i];
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            if ((a[i]^a[j]) > max(a[i], a[j])) {
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }
    memset(c,0,sizeof(c));
    memset(sum,0,sizeof(sum));
    for (int i=1;i<=n;i++) {
        if (c[i] == 0) {
            color++;
            stack<int> s;
            c[i] = color;
            sum[c[i]] += b[i];
            s.push(i);
            while (!s.empty()) {
                int cur = s.top();
                s.pop();
                for (int j=0;j<adj[cur].size();j++) {
                    int next = adj[cur][j];
                    if (c[next] == 0) {
                        c[next] = color;
                        sum[c[next]] += b[next];
                        s.push(next);
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << sum[c[i]] << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
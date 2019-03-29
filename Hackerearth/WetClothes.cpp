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
    int n,m,g;
    cin >> n >> m >> g;
    int ans=0;
    int t[n+5];
    bool r[10005];
    memset (r,0,sizeof(r));
    for (int i=1;i<=n;i++) {
        cin >> t[i];
        r[t[i]]=1;
    }
    priority_queue<int> p;
    for (int i=1;i<=m;i++) {
        int x;
        cin >> x;
        p.push(x);
    }
    int d=1;
    for (int i=t[1];i<=t[n];i++) {
        if (r[i]) d=1;
        else d++;
        //cout << d << endl;
        queue<int> a;
        int k=g;
        while (!p.empty()&&k>0) {
            if (p.top()<=d) {
                k--;
                ans++;
            } else {
                a.push(p.top());
            }
            p.pop();
        }
        while (!a.empty()) {
            p.push(a.front());
            a.pop();
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
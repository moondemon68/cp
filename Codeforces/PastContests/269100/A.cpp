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
    string s;
    cin >> s;
    s += '$';
    int n = s.size();
    
    int k = 0;
    int p[n+5];
    memset (p,0,sizeof(p));
    vector<pii> v;
    for (int i=0;i<s.size();i++) {
        v.pb({s[i], i});
    }
    sort (v.begin(), v.end());
    for (int i=0;i<s.size();i++) {
        p[i] = v[i].se;
    }

    int c[n+5];
    memset (c,0,sizeof(c));
    for (int i=1;i<v.size();i++) {
        if (v[i].fi == v[i-1].fi) c[v[i].se] = c[v[i-1].se];
        else c[v[i].se] = c[v[i-1].se] + 1;
    }

    while ((1 << k) < s.size()) {
        vector<pair<pii, int>> w;
        for (int i=0;i<s.size();i++) {
            w.pb({{c[i], c[(i+(1<<k))%n]}, i});
        }
        sort (w.begin(), w.end());

        memset (p,0,sizeof(p));
        memset (c,0,sizeof(c));
        for (int i=1;i<w.size();i++) {
            if (w[i].fi == w[i-1].fi) c[w[i].se] = c[w[i-1].se];
            else c[w[i].se] = c[w[i-1].se] + 1;
        }
        for (int i=0;i<s.size();i++) {
            p[i] = w[i].se;
        }
        k++;
    }

    for (int i=0;i<s.size();i++) cout << p[i] << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
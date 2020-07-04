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
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    bool a[n+5];
    memset (a,0,sizeof(a));
    for (int i=0;i<=n;i++) a[i]=s[i]-'0';
    vector<int> v;
    int x = n;
    v.pb(x);
    while (x != 0) {
        int y = x - m;
        if (y < 0) y = 0;
        bool ada = 0;
        for (int i=y;i<x;i++) {
            if (!a[i]) {
                ada = 1;
                v.pb(i);
                x=i;
                break;
            }
        }
        if (!ada) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i=v.size()-2;i>=0;i--) cout << v[i]-v[i+1] << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
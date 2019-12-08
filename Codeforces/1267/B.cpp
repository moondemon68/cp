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
    string s;
    cin >> s;
    int l=0,r=s.size()-1;
    char cur = '?';
    int cnt = 0;
    vector<pair<int, char>> v;
    while (l <= r) {
        if (s[l]!=s[r]) {
            cout << 0 << endl;
            return 0;
        }
        cur = s[l];
        cnt = 0;
        while (s[l] == cur && l <= r) {
            cnt++;
            l++;
        }
        while (s[r] == cur && l <= r) {
            cnt++;
            r--;
        }
        v.pb(mp(cnt, cur));
    }
    bool y= 1;
    for (int i=0;i<v.size()-1;i++) {
        //cout << v[i].fi << v[i].se << endl;
        if (v[i].fi < 3) y=0;
    }
    if (y && v[v.size()-1].fi >= 2) cout << v[v.size()-1].fi + 1 << endl;
    else cout << 0 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
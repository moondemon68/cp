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
    set<int> k[30];
    for (int i=0;i<s.size();i++) {
        k[s[i]-'a'].insert(i+1);
    }
    int q;
    cin >> q;
    for (int i=1;i<=q;i++) {
        int t;
        cin >> t;
        if (t==1) {
            int x;
            char c;
            cin >> x >> c;
            k[s[x-1]-'a'].erase(x);
            k[c-'a'].insert(x);
            s[x-1] = c;
        } else {
            int l,r;
            cin >> l >> r;
            int ans=0;
            for (int i=0;i<26;i++) {
                int x = *k[i].lower_bound(l);
                if (x <= r && k[i].lower_bound(l) != k[i].end()) ans++;
            }
            cout << ans << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
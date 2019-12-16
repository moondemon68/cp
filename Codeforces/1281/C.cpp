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
    int tc;
    cin >> tc;
    while (tc--) {
        int x;
        cin >> x;
        string s;
        cin >> s;
        int l=1;
        LL ans=s.size();
        while (s.size() <= x) {
            for (int i=1;i<=s[l-1]-'0';i++) s+=s.substr(l, s.size());
            l++;
        }
        cout << s << endl;
        for (LL i=1;i<=x;i++) {
            cout << i << " " << s[i-1]-'0' << " " << ans-i << endl;
            ans = i + (LL)((s[i-1]-'0')*((ans-i)));
            
        }
        cout << ans%MOD << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
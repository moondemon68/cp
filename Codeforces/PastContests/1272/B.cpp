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
        string s;
        cin >> s;
        int l=0,r=0,d=0,u=0;
        for (int i=0;i<s.size();i++) {
            if (s[i]=='L') l++;
            if (s[i]=='R') r++;
            if (s[i]=='U') u++;
            if (s[i]=='D') d++;
        }
        //cout << l << " " << r << " " << u << " " << d << endl;
        int ans=0;
        ans+=min(l,r);
        ans+=min(u,d);
        ans*=2;
        if (min(l,r)>0 && min(u,d)>0) {
            cout << ans << endl;
            for (int i=1;i<=min(l,r);i++) cout << "L";
            for (int i=1;i<=min(u,d);i++) cout << "U";
            for (int i=1;i<=min(l,r);i++) cout << "R";
            for (int i=1;i<=min(u,d);i++) cout << "D";
        } else if (min(l,r)>0) {
            cout << 2 << endl;
            cout << "LR" << endl;
        } else if (min(u,d)>0) {
            cout << 2 << endl;
            cout << "UD" << endl;
        } else {
            cout << 0 << endl;
            cout << endl;
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
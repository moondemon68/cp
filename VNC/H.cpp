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
    vector<int> h,a;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='H') h.pb(i+1);
        else if (s[i]=='?') a.pb(i+1);
    }
    long double ans = 0;
    for (int i=0;i<h.size();i++) {
        ans+=h[i]*2;
    }
    for (int i=0;i<a.size();i++) {
        ans+=a[i];
    }
    long double l = h.size(), t = a.size();
    ans -= l*l + l*t + t*(t+1)/4;
    cout  << fixed << setprecision(10) << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
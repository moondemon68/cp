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
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    int ans=0;
    vector<int> a;
    for (int i=0;i<s.size();i++) {
        if (s[i]!=t[i]) {
            a.pb(i);
        }
    }
    for (int i=0;i<a.size();i++) {
        if (a[i]==a[i+1]-1&&s[a[i]]!=s[a[i+1]]) {
            i++;
            ans++;
        } else ans++;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
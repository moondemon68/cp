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
    int n;
    cin >> n;
    string s,t;
    cin >> t;
    s="*";
    s+=t;
    vector<int> c;
    for (int i=1;i*i<=n;i++) {
        if (n%i==0) {
            c.pb(i);
            if (i!=n/i) c.pb(n/i);
        }
    }
    int ans=0;
    for (int i=0;i<c.size();i++) {
        int k=c[i];
        bool y=0;
        for (int j=1;j<=n;j++) {
            int cnt=0;
            for (int l=j;l<=n;l+=k) {
                cnt+=s[l]-'0';
            }
            //cout << cnt;
            if (cnt%2==0) {
                y=1;
                break;
            } 
        }
        //cout << endl;
        if (y) ans++;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
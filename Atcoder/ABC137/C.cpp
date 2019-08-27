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
    vector<string> v;
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        sort (s.begin(),s.end());
        v.pb(s);
    }
    sort (v.begin(),v.end());
    v.pb("*");
    LL ans=0,cnt=0;
    for (int i=0;i<v.size()-1;i++) {
        //cout << v[i] << endl;
        if (v[i]==v[i+1]) cnt++;
        else {
            cnt++;
            ans+=(cnt)*(cnt-1)/2;
            cnt=0;
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
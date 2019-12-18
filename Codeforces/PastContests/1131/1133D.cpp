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
    double a[n+5],b[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i];
    vector<double> d;
    int ans=0;
    for (int i=1;i<=n;i++) {
        if (a[i]!=0) d.pb(b[i]/a[i]);
        else ans++;
    }
    sort (d.begin(),d.end());
    int cnt=1,maxcnt=0;
    d.pb(123456789);
    for (int i=0;i<d.size()-1;i++) {
        if (d[i]==d[i+1]) {
            cnt++;
            maxcnt=max(cnt,maxcnt);
        } else {
            cnt=1;
            maxcnt=max(cnt,maxcnt);
        }
    }
    cout << maxcnt+ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
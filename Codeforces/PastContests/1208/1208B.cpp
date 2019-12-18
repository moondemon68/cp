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
    int a[n+5];
    for (int i=1;i<=n;i++) {
        cin >> a[i];
    }
    int ans=INT_MAX;
    for (int i=0;i<=n;i++) {
        set<int> s;
        bool y=1;
        for (int j=1;j<=i;j++) {
            if (s.find(a[j])!=s.end()) {
                y=0;
                break;
            }
            s.insert(a[j]);
        }
        if (!y) break;
        for (int j=n;j>=max(i,1);j--) {
            if (s.find(a[j])==s.end()) {
                s.insert(a[j]);
            } else {
                break;
            }
        }
        //cout << n-s.size() << endl;
        ans=min(ans,(int)(n-s.size()));
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
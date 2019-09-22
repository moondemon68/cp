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
    LL n;
    cin >> n;
    LL p=n*(n+1)/2;
    if (p%2==1) {
        cout << "NO" << endl;
    }  else {
        cout << "YES" << endl;
        vector<int> ans1,ans2;
        LL left=p/2;
        for (int i=n;i>=1;i--) {
            if (i<=left) {
                ans1.pb(i);
                left-=i;
            } else ans2.pb(i);
        }
        cout << ans1.size() << endl;
        for (int i=0;i<ans1.size();i++) cout << ans1[i] << " ";
        cout << endl;
        cout << ans2.size() << endl;
        for (int i=0;i<ans2.size();i++) cout << ans2[i] << " ";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    vector<int> pe,po,ne,no;
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        if (x>0) {
            if (x%2==0) pe.pb(x); else po.pb(x);
        } else {
            if (x%2==0) ne.pb(x); else no.pb(x);
        }
    }
    int ans=0;
    for (int i=0;i<pe.size();i++) ans+=pe[i];
    for (int i=0;i<po.size();i++) ans+=po[i];
    if (ans%2==1) {
        cout << ans << endl;
    } else {
        no.pb(-123456789);
        po.pb(123456789);
        sort (no.begin(),no.end());
        sort (po.begin(),po.end());
        cout << max(ans+no.back(),ans-po.front()) << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
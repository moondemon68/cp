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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q,k;
    cin >> q >> k;
    map<int,int> taste;
    vector<int> a;
    int x=0;
    bool sorted=0;
    while (q--) {
      int b,c,d;
      cin >> b >> c;
      if (b==1||b==2) {
        cin >> d;
        if (taste[c]==0) {
          a.pb(c);
          sorted=0;
        }
        taste[c]+=d;
      } else {
        int ans=0;
        x=x^c;
        if (!sorted) {
          sort(a.begin(),a.end());
          sorted=1;
        }
        auto low=lower_bound(a.begin(),a.end(),x-k);
        auto high=upper_bound(a.begin(),a.end(),x+k);
        //cout << low-a.begin() << high-a.begin();
        for (int i=low-a.begin();i<high-a.begin();i++) {
          //cout << a[i];
          ans+=taste[a[i]];
        }
        cout << ans << "\n";
        x=ans;
      }
    }
    return 0;
}

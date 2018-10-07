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
    string s,t;
    cin >> s >> t;
    sort (s.begin(),s.end());
    sort (t.begin(),t.end());
    int p=0;
    bool y=1;
    //cout << s << endl << t << endl;
    for (int i=0;i<t.size();i++) {
      if (p==s.size()) {
        y=0;
        break;
      }
      //cout << s[p] << " " << t[i] << endl;
      if (s[p]==t[i]) {
        p++;
      } else {
        p++;
        i--;
      }
    }
    if (y) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

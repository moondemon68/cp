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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt[30];
    memset (cnt,0,sizeof(cnt));
    for (int i=0;i<s.size();i++) {
      cnt[s[i]-'a']++;
    }
    vector<pii> a;
    for (int i=0;i<26;i++) {
      if (cnt[i]>0) a.pb(mp(i,cnt[i]));
    }
    string k="";
    for (int i=0;i<a.size();i++) {
      for (int j=0;j<a[i].se;j++) {
        k+=char(a[i].fi+'a');
      }
    }
    cout << k << endl;
    return 0;
}

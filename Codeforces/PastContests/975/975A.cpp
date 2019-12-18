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
    set<string> ans;
    for (int i=1;i<=n;i++) {
      int h[30];
      memset (h,0,sizeof(h));
      string s;
      cin >> s;
      for (int j=0;j<s.size();j++) {
        h[s[j]-'a']++;
      }
      string p="";
      for (int j=0;j<28;j++) {
        if (h[j]>0) p+=(char)j+'a';
      }
      ans.insert(p);
    }
    cout << ans.size() << endl;
    return 0;
}

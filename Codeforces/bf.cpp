#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;
bool pal(string s) {
  for (int i=0;i<s.size()/2;i++) {
    if (s[i]!=s[s.size()-i-1]) return 0;
  }
  return 1;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int ans=0;
    for (int i=0;i<s.size();i++) {
      for (int j=i;j<s.size();j++) {
        string k="";
        for (int p=i;p<=j;p++) k+=s[p];
        if (pal(k)) ans++;
      }
    }
    cout << ans << endl;
    return 0;
}

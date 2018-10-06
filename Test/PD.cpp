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
    string s;
    cin >> s;
    int ans=0;
    for (int i=0;i<s.size();i++) {
      int cnt=0;
      if (s[i]!='a') continue;
      for (int j=i;j<s.size();j++) {
        if (s[j]=='a') cnt++;
        else break;
      }
      ans=max(ans,cnt);
    }
    for (int i=0;i<=ans;i++) cout << "a";
    return 0;
}

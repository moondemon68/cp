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
    char a;
    cin >> a;
    string s;
    cin >> s;
    if (a=='E') {
      int cnt=1;
      s+='=';
      for (int i=0;i<s.size()-1;i++) {
        if (s[i]!=s[i+1]) {
          cout << s[i] << cnt;
          cnt=1;
        } else {
          cnt++;
        }
      }
    } else {
      for (int i=0;i<s.size();i+=2) {
        for (int j=1;j<=s[i+1]-'0';j++) {
          cout << s[i];
        }
      }
    }
    return 0;
}

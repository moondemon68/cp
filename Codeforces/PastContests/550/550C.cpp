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
    for (int i=0;i<s.size();i++) {
      for (int j=i+1;j<s.size();j++) {
        for (int k=j+1;k<s.size();k++) {
          int x=0;
          x+=s[i]-'0';
          x*=10;
          x+=s[j]-'0';
          x*=10;
          x+=s[k]-'0';
          if (x%8==0) {
            cout << "YES" << endl;
            cout << x << endl;
            return 0;
          }
        }
      }
    }
    for (int j=0;j<s.size();j++) {
      for (int k=j+1;k<s.size();k++) {
        int x=0;
        x+=s[j]-'0';
        x*=10;
        x+=s[k]-'0';
        if (x%8==0) {
          cout << "YES" << endl;
          cout << x << endl;
          return 0;
        }
      }
    }
    for (int k=0;k<s.size();k++) {
      int x=0;
      x+=s[k]-'0';
      if (x%8==0) {
        cout << "YES" << endl;
        cout << x << endl;
        return 0;
      }
    }
    cout << "NO" << endl;
    return 0;
}

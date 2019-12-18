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
    bool ab=0,ba=0;
    for (int i=0;i<s.size()-1;i++) {
      if (!ab) {
        if (s[i]=='A'&&s[i+1]=='B') {
          ab=1;
          i++;
        }
      } else {
        if (s[i]=='B'&&s[i+1]=='A') {
          ba=1;
          i++;
        }
      }
    }
    if (ab&&ba) {
      cout << "YES" << endl;
      return 0;
    }

    ab=0;
    ba=0;
    for (int i=0;i<s.size()-1;i++) {
      if (!ab) {
        if (s[i]=='B'&&s[i+1]=='A') {
          ab=1;
          i++;
        }
      } else {
        if (s[i]=='A'&&s[i+1]=='B') {
          ba=1;
          i++;
        }
      }
    }
    if (ab&&ba) {
      cout << "YES" << endl;
      return 0;
    }
    cout << "NO" << endl;
    return 0;
}

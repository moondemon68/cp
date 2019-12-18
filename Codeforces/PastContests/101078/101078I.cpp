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
    int tc;
    cin >> tc;
    while (tc--) {
      string s;
      cin >> s;
      stack<char> a,b;
      int p=0;
      for (int i=0;i<s.size();i++) {
        if (s[i]=='<') {
          if (!a.empty()) {
            b.push(a.top());
            a.pop();
          }
        }
        else if (s[i]=='>') {
          if (!b.empty()) {
            a.push(b.top());
            b.pop();
          }
        }
        else if (s[i]=='-') {
          if (!a.empty()) a.pop();
        }
        else {
          a.push(s[i]);
        }
      }
      while (!b.empty()) {
        a.push(b.top());
        b.pop();
      }
      string out="";
      while (!a.empty()) {
        out+=a.top();
        a.pop();
      }
      reverse(out.begin(),out.end());
      cout << out << endl;
    }
    return 0;
}

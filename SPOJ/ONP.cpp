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
    int tc;
    cin >> tc;
    while (tc--) {
      string s;
      cin >> s;
      stack<char> p;
      for (int i=0;i<s.size();i++) {
        if (s[i]>='a'&&s[i]<='z') cout << s[i];
        else if (s[i]==')') {
          cout << p.top();
          p.pop();
        }
        else if (s[i]!='(') p.push(s[i]);
      }
      cout << endl;
    }
    return 0;
}

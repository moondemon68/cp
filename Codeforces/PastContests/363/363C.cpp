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
    s+='.';
    for (int i=0;i<s.size()-1;i++) {
      if (s[i]==s[i+1]&&s[i+1]==s[i+2]) {
        s.erase(s.begin()+i);
        i--;
      }
    }

    for (int i=0;i<s.size();i++) {
      if (s[i]==s[i+1]&&s[i+1]!=s[i+2]&&s[i+2]==s[i+3]) {
        s.erase(s.begin()+i+2);
        i--;
      }
    }
    s.erase(s.begin()+s.size()-1);
    cout << s << endl;
    return 0;
}

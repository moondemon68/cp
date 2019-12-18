#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

string makestring(int x) {
  string s="";
  while (x>0) {
    s+='0'+(x%10);
    x/=10;
  }
  reverse(s.begin(),s.end());
  return s;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    map<string,int> a;
    for (int i=1;i<=n;i++) {
      string s;
      cin >> s;
      if (!a.count(s)) {
        cout << "OK" << endl;
        a[s]++;
      } else {
        cout << s+makestring(a[s]) << endl;
        a[s]++;
      }
    }
    return 0;
}

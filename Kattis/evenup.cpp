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
    stack<int> a;
    for (int i=1;i<=n;i++) {
      int x;
      cin >> x;
      if (!a.empty()&&(a.top()+x)%2==0) {
        a.pop();
      }  else a.push(x);
    }
    cout << a.size() << endl;
    return 0;
}

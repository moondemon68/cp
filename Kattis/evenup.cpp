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
    stack<int> a,b;
    for (int i=1;i<=n;i++) {
      int x;
      cin >>x;
      a.push(x);
    }
    while (a.size()>=2) {
      int cur1=a.top();
      a.pop();
      int cur2=a.top();
      a.pop();
      if ((cur1+cur2)%2!=0) {
        b.push(cur1);
        a.push(cur2);
      }
    }
    while (!a.empty()) {
      b.push(a.top());
      a.pop();
    }
    cout << b.size() << endl;
    return 0;
}

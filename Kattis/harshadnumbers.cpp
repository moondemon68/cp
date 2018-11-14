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
    while (1>0) {
      int d=0,x=n;
      while (x>0) {
        d+=x%10;
        x/=10;
      }
      if (n%d==0) {
        cout << n << endl;
        return 0;
      } else n++;
    }
    return 0;
}

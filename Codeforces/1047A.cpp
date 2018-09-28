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
    for (int i=1;i<=n;i++) {
      if ((n-i)%2==0&&(i%3)!=0&&((n-i)%3)!=0) {
        cout << i << " " << (n-i)/2 << " " << (n-i)/2 << endl;
        break;
      }
    }
    return 0;
}

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
    long long b;
    cin >> b;
    int ans=0;
    for (LL i=1;i*i<=b;i++) {
      if (b%i==0) ans+=2;
      if (i*i==b) ans--;
    }
    cout << ans << endl;
    return 0;
}

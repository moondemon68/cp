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
    LL l,r;
    cin >> l >> r;
    cout << "YES" << endl;
    for (LL i=l;i<=r;i+=2) {
      cout << i << " " << i+1 << endl;
    }
    return 0;
}

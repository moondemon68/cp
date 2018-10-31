#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

int m[1000005];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL p;
    cin >> p;
    memset (m,-1,sizeof(m));
    for (LL i=0;i<p;i++) {
      if (m[(i*i)%p]==-1) {
        m[(i*i)%p]=i;
      }
    }
    for (int i=0;i<p;i++) {
      cout << m[i] << " ";
    }
    return 0;
}

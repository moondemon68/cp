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
    int a[11]={3,6,2,7,16,77,26,34,66,27,44};
    int x,y,z;
    while (cin >> x >> y >> z) {
      int ret=a[x]^a[y]^a[z];
      cout << ret << endl;
    }
    return 0;
}

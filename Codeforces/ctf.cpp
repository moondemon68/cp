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
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int p[2005];
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) {
        int x;
        int k;
        cin >> x >> k;
        p[x]=k;
    }
    for (int i=1;i<=n;i++) cout << p[i];
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL a[3],d;
    cin >> a[0] >> a[1] >> a[2] >> d;
    sort (a,a+3);
    LL ans=123456789876;
    LL t=a[1]-a[0],u=a[2]-a[1];
    ans=min(ans,max(0LL,d-t)+max(0LL,d-u));
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
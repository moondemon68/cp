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
    int n,k;
    cin >> n >> k;
    double ans=0;
    double now=n-k;
    while (n>0) {
        cout << now << n << endl;
        ans+=now/n;
        n-=now;
        now=(n+1)/2;
    }    
    cout  << fixed << setprecision(10) << ans << endl;
    return 0;
}

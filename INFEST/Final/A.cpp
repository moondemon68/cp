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
    int n;
    cin >> n;
    int a[n+5];
    for (int i=1;i<=n;i++) {
        cin >> a[i];
    }
    sort (a+1,a+n+1);
    int x;
    if (n%2==0) x=(a[n/2]+a[n/2+1]+1)/2;
    else if (n%2==1) x=a[n/2+1];
    int t=0;
    for (int i=1;i<=n;i++) {
        if (a[i]>=x) t++;
    }
    cout << t << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
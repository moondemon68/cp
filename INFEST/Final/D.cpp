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
    int c[10005];
    c[1]=1;
    int p=2,x=9;
    while (x<=1000000) {
        c[p]=x;
        x*=9;
        p++;
    }
    x=6;
    while (x<=1000000) {
        c[p]=x;
        x*=6;
        p++;
    }
    p--;
    sort (c+1,c+p+1);
    int ans=0;
    while (n) {
        for (int i=p;i>=1;i--) {
            if (n>=c[i]) {
                ans++;
                n-=c[i];
                break;
            }
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
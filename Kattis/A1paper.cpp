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
    int a[n+5];
    for (int i=2;i<=n;i++) cin >> a[i];
    int req=1;
    double p=2*(pow(2.0,-0.75)+pow(2.0,-1.25));
    double q=sqrt(2)*p;
    double ans=0;
    for (int i=2;i<=n;i++) {
        req*=2;
        if (a[i]<=req) {
            ans+=a[i]*p;
            req-=a[i];
        } else if (a[i]>req) {
            ans+=req*p;
            req=0;
        }
        //cout << ans << endl;
        p/=sqrt(2);
    }   
    ans=(ans-q)/2;
    if (req==0) cout << fixed << setprecision(10) << ans << endl;
    else cout << "impossible" << endl;
    return 0;
}

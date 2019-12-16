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
    int n,k;
    cin >> n >> k;
    pii a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    int v[205];
    memset (v,0,sizeof(v));
    for (int i=1;i<=n;i++) {
        v[a[i].fi]++;
        v[a[i].se+1]--;
    }
    for (int i=1;i<=200;i++) {
        v[i]+=v[i-1];
    }
    for (int i=1;i<=20;i++) cout << v[i] <<  ' ';
    cout << endl;
    int ans=0;
    for (int i=200;i>=1;i++) {
        if (v[i]!=0) {
            int minx=INT_MIN,mini=-1;
            for (int j=1;j<=n;j++) {
                if (a[j].fi<minx && a[j].se>=i) {
                    minx = a[j].fi;
                    mini = j;
                }
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
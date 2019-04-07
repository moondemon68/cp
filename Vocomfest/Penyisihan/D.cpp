#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bool primaga[100005];
void sieve(int x) {
    memset(primaga,1,sizeof(primaga));
    primaga[0]=0;
    primaga[1]=0;
    for (int i=2;i*i<=x;i++) {
        for (int j=i*i;j<=x;j+=i) {
            primaga[j]=0;
        }
    }
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    sieve(10000);
    vector<int> a;
    for (int i=1;i<=10000;i++) {
        if (primaga[i]) a.pb(i);
    }
    for (int t=1;t<=tc;t++) {
        int n;
        cin >> n;
        int ans=0;
        for (int i=0;i<n;i++) ans+=a[i];
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
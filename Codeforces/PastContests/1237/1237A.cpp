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
    int n;
    cin >> n;
    int a[n+5];
    int tot=0;
    for (int i=1;i<=n;i++) cin >> a[i];
    int b[n+5];
    for (int i=1;i<=n;i++) b[i]=a[i]/2;
    for (int i=1;i<=n;i++) tot+=b[i];
    for (int i=1;i<=n;i++) {
        if (tot>0 && a[i]<0 && a[i]%2==-1) {
            b[i]--;
            tot--;
        }
    }
    for (int i=1;i<=n;i++) {
        if (tot<0 && a[i]>0 && a[i]%2==1) {
            b[i]++;
            tot++;
        }
    }
    for (int i=1;i<=n;i++) cout << b[i] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
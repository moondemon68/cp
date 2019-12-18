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
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        int t=1;
        for (int i=1;i<=n;i++) {
            int mini = a[t], p = t;
            for (int j=t+1;j<=n;j++) {
                if (a[j]<mini) {
                    mini=a[j];
                    p=j;
                }
            }
            for (int j=p-1;j>=t;j--) {
                swap(a[j],a[j+1]);
            }
            t=max(p,i);
            // cout << p << " ";
            // for (int i=1;i<=n;i++) cout << a[i] << " ";
            // cout << endl;
        }
        for (int i=1;i<=n;i++) cout << a[i] << " ";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
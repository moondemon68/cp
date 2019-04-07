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
    for (int t=1;t<=tc;t++) {
        
        int n;
        cin >> n;
        int a[n+5],b[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=n;i++) cin >> b[i];
        sort (a+1,a+n+1);
        sort (b+1,b+n+1);
        cout << "Case #" << t << ": ";
        bool y=0;
        for (int i=1;i<=n;i++) {
            if (a[i]==b[i]) y=1;
        }
        if (y) {
            cout << "EXIST" << endl;
            continue;
        }
        bool ada[105];
        memset (ada,0,sizeof(ada));
        for (int i=1;i<=n;i++) ada[a[i]]=1;
        for (int i=1;i<=n;i++) {
            if (ada[b[i]]) y=1;
        }
        if (y) {
            cout << "MAY EXIST" << endl;
            continue;
        }
        cout << "NOT EXIST" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
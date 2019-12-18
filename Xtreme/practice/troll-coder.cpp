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
    if (n==1) {
        cout << "Q 1" << endl;
        int x;
        cin >> x;
        if (x == 0) cout << "A 0" << endl;
        else cout << "A 1" << endl;
        return 0;
    }
    int a[n+5];
    memset (a,0,sizeof(a));
    for (int i=1;i<=n+1;i++) {
        cout << "Q";
        for (int j=1;j<=n;j++) {
            cout << " ";
            if (i==j || i==n+1) cout << 1; else cout << 0;
        }
        cout << endl;
        int p;
        cin >> p;
        a[i]=p;
    }
    int maxi=0,mini=1234;
    for (int i=1;i<=n;i++) {
        maxi=max(maxi,a[i]);
        mini=min(mini,a[i]);
    }
    int l=0,r=0;
    for (int i=1;i<=n;i++) {
        if (a[i]==maxi) {
            r++;
            a[i]=1;
         } else {
            l++;
            a[i]=0;
         }
    }
    if (a[n+1] == l) {
        for (int i=1;i<=n;i++) a[i]=1-a[i];
    }
    cout << "A";
    for (int i=1;i<=n;i++) cout << " " << a[i];
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
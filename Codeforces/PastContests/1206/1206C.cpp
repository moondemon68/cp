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
    if (n%2==0) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        int p[2*n+5];
        int cnt=0;
        for (int i=1;i<=2*n-2;i++) {
            if (i%4==1) {
                p[cnt*2+1]=i;
            } else if (i%4==2) {
                p[cnt*2+n+1]=i;
            } else if (i%4==3) {
                p[cnt*2+n+2]=i;
            } else {
                p[cnt*2+2]=i;
                cnt++;
            }
        }
        p[n]=2*n-1;
        p[2*n]=2*n;
        for (int i=1;i<=2*n;i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
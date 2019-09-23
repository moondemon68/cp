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
    int a[5];
    for (int i=0;i<4;i++) cin >> a[i];
    int tot=0;
    for (int i=0;i<4;i++) tot+=a[i];
    if (tot%2==1) {
        cout << "NO" << endl;
        return 0;
    }
    tot/=2;
    for (int i=0;i<4;i++) {
        for (int j=i+1;j<4;j++) {
            if ((a[i]+a[j])==tot) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
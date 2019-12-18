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
    memset (a,0,sizeof(a));
    for (int i=1;i<=n;i++) cin >> a[i];
    int l=0,r=0;
    for (int i=1;i<=n;i++) {
        if (a[i]==n) {
            l=i-1;
            r=i+1;
            break;
        } 
    }
    int cur=n-1;
    while (cur>=1) {
        //cout << l << r << cur << endl;
        if (a[l]!=cur&&a[r]!=cur) {
            cout << "NO";
            return 0;
        } else if (a[l]==cur) {
            l--;
            cur--;
        } else if (a[r]==cur) {
            r++;
            cur--;
        }
    }
    cout << "YES";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
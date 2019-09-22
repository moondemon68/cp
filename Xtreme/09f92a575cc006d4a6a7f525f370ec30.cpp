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
    int a[]={0,1,1,2,3,5,8,3,1,4,5,9,4,3,7,0,7,7,4,1,5,6,1,7,8,5,3,8, 1,9,0,9,9,8,7,5,2,7,9,6,5,1,6,7,3,0,3,3,6,9,5,4,9,3,2,5,7,2,9,1};
    while (tc--) {
        int m;
        cin >> m;
        cout << a[(m+1)%60] << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
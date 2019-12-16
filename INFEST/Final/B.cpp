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
    int x1,v1,x2,v2;
    cin >> x1 >> v1 >> x2 >> v2;
    bool y=1;
    if ((x1-x2)%(v2-v1)!=0) y=0;
    if ((x1-x2)>0&&(v2-v1)<0) y=0;
    if ((x1-x2)<0&&(v2-v1)>0) y=0;
    if (y) cout << "YA" << endl; else cout << "TIDAK" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
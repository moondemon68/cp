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
    LL r,c,a,b,x,y;
    cin >> r >> c >> a >> b >> x >> y;
    LL d=(x-a);
    LL miny=b,maxy=b;
    miny-=d;
    maxy+=d;
    if (y>=miny&&y<=maxy&&((a+b)%2==(x+y)%2)) cout << "YA" << endl;
    else cout << "TIDAK" << endl;
    //cout << miny << " " << maxy;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
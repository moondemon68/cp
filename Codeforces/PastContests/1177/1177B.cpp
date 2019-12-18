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
    LL p[25];
    p[0]=1;
    for (int i=1;i<=15;i++) {
        p[i]=p[i-1]*10;
    }
    LL k;
    cin >> k;
    k--;
    LL d=1,v=1,l=9;
    LL t=0;
    while (k/l>=d) {
        LL o=l;
        k-=d*l;
        d++;
        v*=10;
        l*=10;
        if (l<=o) break;
    }
    v+=k/d;
    v/=p[(d-1)-(k%d)];
    cout << v%10 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
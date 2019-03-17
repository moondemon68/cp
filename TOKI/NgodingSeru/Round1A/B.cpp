#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bool isOr(LL x1,LL y1,LL x2,LL y2,LL x3,LL y3) {
    return (x2-x1)*(x2-x3)+(y2-y1)*(y2-y3)==0;
}

bool isRec(LL x1,LL y1,LL x2,LL y2,LL x3,LL y3,LL x4,LL y4) {
    return (isOr(x1,y1,x2,y2,x3,y3))&&(isOr(x2,y2,x3,y3,x4,y4))&&(isOr(x3,y3,x4,y4,x1,y1));
}

bool check(LL x1,LL y1,LL x2,LL y2,LL x3,LL y3,LL x4,LL y4) {
    return isRec(x1,y1,x2,y2,x3,y3,x4,y4)||isRec(x2,y2,x3,y3,x1,y1,x4,y4)||isRec(x3,y3,x1,y1,x2,y2,x4,y4);
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    LL x[n+5],y[n+5];
    for (int i=1;i<=n;i++) {
        cin >> x[i] >> y[i];
    }
    int cnt=0;
    set<pair<pii,pii>> s;
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            
        }
    }
    cout << cnt << endl;
    cout << "TIDAK" << endl;
    return 0;
    //cout << cnt << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
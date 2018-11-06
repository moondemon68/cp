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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n;
    cin >> n;
    LL x,y;
    cin >> x >> y;
    LL dx1=x-1,dy1=y-1,dx2=n-x,dy2=n-y;
    LL m1=min(dx1,dy1)+abs(dx1-dy1);
    LL m2=min(dx2,dy2)+abs(dx1-dy1);
    if (m1<=m2) cout << "White" << endl;
    else cout << "Black" << endl;
    return 0;
}

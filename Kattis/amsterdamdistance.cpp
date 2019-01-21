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
    double r;
    int n,m;
    cin >> n >> m >> r;    
    int ax,ay,bx,by;
    cin >> ax >> ay >> bx >> by;
    double ans=0;
    ans=abs(by-ay)*(r/m);
    double x=min(by,ay)*(r/m);
    //cout << x << endl;
    double peri=acos(-1)*x;
    //cout << peri << endl;
    ans+=peri*abs(bx-ax)/n;
    ans=min(ans,(ay+by)*r/m);
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}

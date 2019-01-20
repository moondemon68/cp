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
    string s;
    double qty=0;
    double avg=0,cost=0;
    while (cin >> s) {
        if (s=="buy") {
            double x,y;
            cin >> x >> y;
            qty+=x;
            cost+=x*y;
            avg=(double)cost/(double)qty;
        } 
        if (s=="sell") {
            double x,y;
            cin >> x >> y;
            qty-=x;
            cost=avg*qty;
        }
        if (s=="split") {
            double x;
            cin >> x;
            qty*=x;
            avg/=x;
            cost=avg*qty;
        }
        if (s=="merge") {
            double x;
            cin >> x;
            qty=floor(qty/x);
            avg*=x;
            cost=avg*qty;
        }
        if (s=="die") {
            double y;
            cin >> y;
            double profit=y-avg;
            if (profit<0) profit=0;
            cout << fixed << setprecision(8) << qty*(y-0.3*profit) << endl;
            return 0;
        }
        //cout << qty << " " << avg << endl;
    }
    return 0;
}

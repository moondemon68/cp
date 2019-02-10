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
    ifstream cin ("input-C.txt");
    ofstream cout ("output-C.txt");
    int tc;
    cin >> tc;
    while (tc--) {
        double a,b,c;
        cin >> a >> b >> c;
        double d=INT_MAX;
        swap(a,d);
        int pro=0;
        while (abs(a-d)>0.000000001&&pro<=100000000) {
            swap(a,d);
            d=a*b-a*a*c;
            if (d<=0) {
                a=0;
                d=0; 
            }
            pro++;
        }
        if (pro==100000000) cout << "-1" << endl;
        else cout << fixed << setprecision(10) << d << endl;
    }
    return 0;
}
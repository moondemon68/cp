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
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
        double a,b,c,d;
        cin >> a >> b >> c >> d;
        double h = sqrt((b+c*c+d*d-a)/2);
        double area = 0.5 * (c*c - h*h) * h + 0.5 * (d*d - h*h) * h + b * h;
        // cout << area << endl;
        double target = area/2;
        double ans = 0, l = 0, r = h, ansc = 0, ansd = 0, ansarea = 0;
        while (abs(l-r) > 1e-7) {
            double m = (l + r) / 2;
            double c2 = (c * m) / h;
            double d2 = (d * m) / h;
            double newarea = 0.5 * (c2*c2 - m*m) * m + 0.5 * (d2*d2 - m*m) * m + (a - (c2*c2 - m*m) - (d2*d2 - m*m)) * m;
            if (newarea >= target) {
                ans = m;
                ansarea = newarea;
                ansc = c2;
                ansd = d2;
                r = m-1e-7;
            } else {
                l = m+1e-7;
            }
        }
        cout << ansarea << " " << area << endl;
        cout << "Lahan #" << t << ": " << fixed << setprecision(6) << ansc << " " << ansd << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
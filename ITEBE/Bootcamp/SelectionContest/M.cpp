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
    while (tc--) {
        int r,c;
        cin >> r >> c;
        for (int i=0;i<3*r;i++) {
            if (i%3==1||i%3==2) {
                string s="*..";
                string t="";
                for (int j=1;j<=c;j++) t+=s;
                cout << t << '*' << endl;
            } else {
                string s="***";
                string t="";
                for (int j=1;j<=c;j++) t+=s;
                cout << t << '*' << endl;
            }
        }
        string s="***";
        string t="";
        for (int j=1;j<=c;j++) t+=s;
        cout << t << '*' << endl;
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i=0;i<=10000000;i++) {
        int x=i,y=1;
        for (int j=0;j<s.size();j++) {
            if (s[j]=='-') x--; else x++;
            if (x<0) {
                y=0;
                break;
            }
        }
        if (y) {
            cout << x << endl;
            return 0;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
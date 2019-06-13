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
    string a,b;
    int x,y;
    while (cin >> a >> x >> b >> y) {
        if (a[0]==b[0]) {
            if (x>y) cout << "Tobby";
            else if (x<y) cout << "Naebbirac";
            else cout << "Draw";
        } else if (a[0]=='B') {
            if (b[0]=='C') {
                if (x>=2*y) cout << "Tobby";
                else cout << "Naebbirac";
            } else if (b[0]=='D') {
                if (x*2>y) cout << "Tobby";
                else cout << "Naebbirac";
            }
        } else if (a[0]=='C') {
            if (b[0]=='D') {
                if (x>=2*y) cout << "Tobby";
                else cout << "Naebbirac";
            } else if (b[0]=='B') {
                if (x*2>y) cout << "Tobby";
                else cout << "Naebbirac";
            }
        } else if (a[0]=='D') {
            if (b[0]=='B') {
                if (x>=2*y) cout << "Tobby";
                else cout << "Naebbirac";
            } else if (b[0]=='C') {
                if (x*2>y) cout << "Tobby";
                else cout << "Naebbirac";
            }
        }
        cout << "\n";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
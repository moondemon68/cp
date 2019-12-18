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
    int a[15];
    bool y=0;
    for (int i=1;i<=9;i++) cin >> a[i]; 
    for (int i=0;i<s.size();i++) {
        int x=s[i]-'0';
        if (y) cout << s[i];
        else {
            if (a[x]>x) {
                cout << a[x];
                y=1;
                bool g=1;
                while (g&&i<s.size()-1) {
                    i++;
                    int xx=s[i]-'0';
                    if (a[xx]>=xx) {
                        cout << a[xx];
                    } else {
                        cout << xx;
                        g=0;
                    }
                }
            } else cout << x;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
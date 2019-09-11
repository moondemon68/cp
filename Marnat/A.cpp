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
    for (int i=1;i<=n;i++) {
        string s1="",s2="",s3="";
        if (i%2==1) {
            for (int j=1;j<=n;j++) {
                s1+=" .--. ";
                s2+="|  oo|";
                s3+="|/\\/\\|";
            }
        } else {
            for (int j=1;j<=n;j++) {
                s1+=" .--. ";
                s2+="|oo  |";
                s3+="|/\\/\\|";
            }
        }
        cout << s1 << endl << s2 << endl << s3 << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
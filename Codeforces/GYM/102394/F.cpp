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
        string s[6];
        for (int i=0;i<6;i++) cin >> s[i];
        int a[6][6];
        memset (a,0,sizeof(a));
        for (int i=0;i<6;i++) {
            for (int j=0;j<s[i].size();j++) {
                if (s[i][j]=='h') a[i][0]=1;
                else if (s[i][j]=='a') a[i][1]=1;
                else if (s[i][j]=='r') a[i][2]=1;
                else if (s[i][j]=='b') a[i][3]=1;
                else if (s[i][j]=='i') a[i][4]=1;
                else if (s[i][j]=='n') a[i][5]=1;
            }
        }
        int p[10];
        for (int i=0;i<6;i++) p[i]=i;
        bool ans=0;
        do {
            bool y=1;
            for (int i=0;i<6;i++) {
                if (a[p[i]][i] == 0) y=0;
            }
            if (y) {
                ans=1;
                break;
            }
        } while (next_permutation(p, p+6));
        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
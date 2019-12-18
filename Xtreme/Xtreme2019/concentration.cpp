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
    int n;
    cin >> n;
    int a[2*n+5];
    cin.ignore();
    memset (a,-1,sizeof(a));
    for (int k=1;k<=n;k++) {
        cout << 2*k-1 << " " << 2*k << endl;
        string s;
        getline(cin,s);
        s+=' ';
        //cout << s << endl;
        if (s[0]!='M') {
            int x=0;
            for (int i=0;i<(int)s.size();i++) {
                if (s[i]>='0'&&s[i]<='9') {
                    x+=s[i]-'0';
                    x*=10;
                } else {
                    x/=10;
                    if (a[2*k-1]==-1) {
                        a[2*k-1]=x;
                        x=0;
                    }
                    else a[2*k]=x;
                }
            }
        }
    }
    // for (int i=1;i<=2*n;i++) cout << a[i] << " ";
    // cout << endl;
    for (int i=1;i<=2*n;i++) {
        for (int j=i+1;j<=2*n;j++) {
            if (a[i]!=-1&&a[j]!=-1&&a[i]==a[j]) {
                cout << i << " " << j << endl;
                string s;
                cin >> s;
                a[i]=-1;
                a[j]=-1;
            }
        }
    }
    cout << -1 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    string s;
    getline(cin,s);
    int p=s.size();
    int n;
    for (int i=0;i<=p;i++) {
        if (i*i<p) n=i;
        else break;
    }
    n++;
    while (s.size() < n*n) {
        s+=' ';
    }
    for (int i=0;i<s.size();i++) {
        if (s[i]==' ') s[i]='*';
    }
    char a[n+5][n+5];
    int k=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            a[i][j]=s[k];
            k++;
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout << a[j][i];
        }
    }
    cout << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
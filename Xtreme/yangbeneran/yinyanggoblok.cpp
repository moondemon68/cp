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
    string s="";
    int l=1,r=4;
    for (int i=1;i<=100;i++) {
        for (int j=1;j<=l;j++) s+='Y';
        for (int j=1;j<=r;j++) s+='y';
        l++;r++;
    }
    for (int i=1;i<=n;i++) cout << s[i-1];
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
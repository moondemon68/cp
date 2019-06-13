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
    int a,b,c;
    cin >> a >> b >> c;
    if (c==0) {
        if (a>b) cout << "+"; else if (a<b) cout << "-"; else cout << "0";
    } else {
        int maxa=a+c-b,mina=a-b-c;
        if (maxa>0&&mina>0) cout << "+";
        else if (maxa<0&&mina<0) cout << "-";
        else cout << "?";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
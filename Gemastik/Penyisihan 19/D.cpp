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
    int a,b;
    string s;
    cin >> a >> b >> s;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='t') a--;
        else if (s[i]=='u') b--;
        else if (s[i]=='b') a++;
        else b++;
    }
    cout << a << " " << b << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
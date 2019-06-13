#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bitset<10000005> prima;
void sieve(int x) {
    prima.set();
    prima[0]=0;
    prima[1]=0;
    for (int i=2;i*i<=x;i++) {
        if (!prima[i]) continue;
        for (int j=i*i;j<=x;j+=i) prima[j]=0;
    }
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve(10000000);
    int n;
    string s;
    while (cin >> n >> s) {
        int x=0,c=0;
        bool y=1;
        for (int i=0;i<s.size();i++) {
            x+=s[i]-'0';
            x*=10;
            c++;
            if (c==n) {
                x/=10;
                if (!prima[x]) {
                    y=0;
                    break;
                }
                x=0;
                c=0;
            }
        }
        if (y) cout << ":)"; else cout << ":(";
        cout << "\n";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
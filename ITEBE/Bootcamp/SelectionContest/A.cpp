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
    string s;
    cin >> s;
    s+='*';
    s+='*';
    for (int i=0;i<s.size()-2;i++) {
        if (s[i]=='1' && s[i+1]=='4' && s[i+2]=='4') {
            i+=2;
        } else if (s[i]=='1' && s[i+1]=='4') {
            i++;
        } else if (s[i]=='1') {
            
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
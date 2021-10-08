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
    getline(cin, s);
    for (int i=0;i<s.size();i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'u' || s[i] =='o' || s[i] == 'i') cout << 'i';
        else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'U' || s[i] =='O' || s[i] == 'I') cout << 'I';
        else cout << s[i];
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
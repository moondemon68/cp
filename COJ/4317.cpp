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
    cin.ignore();
    for (int i=1;i<=n;i++) {
        string s;
        getline(cin,s);
        for (int j=0;j<s.size();j++) {
            if (s[j]=='a'||s[j]=='i'||s[j]=='u'||s[j]=='e'||s[j]=='o') cout << s[j] << 'p' << s[j]; else cout << s[j];
        }
        cout << "\n";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
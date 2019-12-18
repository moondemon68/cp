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
    string s;
    cin >> s;
    int c=0;
    for (int i=0;i<s.size();i+=2) {
        if (s[i]=='a'&&s[i+1]=='b') {

        } else if (s[i]=='a'&&s[i+1]=='a') {
            s[i+1]='b';
            c++;
        } else if (s[i]=='b'&&s[i+1]=='a') {

        } else if (s[i]=='b'&&s[i+1]=='b') {
            s[i+1]='a';
            c++;
        }
    }
    cout << c << endl;
    cout << s << endl;

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    ifstream cin("alchemy_input.txt");
    ofstream cout("alchemy_output.txt");
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int a=0,b=0;
        for (int i=0;i<s.size();i++) {
            if (s[i] == 'A') a++; else b++;
        }
        cout << "Case #" << t << ": ";
        if (abs(a-b) == 1) cout << "Y";
        else cout << "N";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
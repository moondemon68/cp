// Parentheses Balance
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
    while (n--) {
        string s;
        cin >> s;
        stack<char> c;
        bool y=1;
        for (int i=0;i<s.size();i++) {
            if (s[i]=='('||s[i]=='[') c.push(s[i]);
            else {
                if (c.empty()) {
                    y=0;
                    break;
                }
                if (s[i]==')'&&c.top()=='[') {
                    y=0;
                    break;
                }
                if (s[i]==']'&&c.top()=='(') {
                    y=0;
                    break;
                }
                c.pop();
            }
        }
        if (y) cout << "ya" << endl;
        else cout << "tidak" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
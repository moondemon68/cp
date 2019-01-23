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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int ans=0;
    while (1) {
        bool y=0;
        for (int i=0;i<s.size();i++) {
            if (s[i]==s[i+1]) {
                s.erase(s.begin()+i,s.begin()+i+2);
                ans++;
                i++;
                y=1;
            }
        }
        if (!y) {
            if (ans%2==0) {
                cout << "No";
            } else cout << "Yes";
            return 0;
        }
    }    
    return 0;
}

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
    stack<char> a;
    for (int i=0;i<s.size();i++) {
        if (!a.empty()&&a.top()==s[i]) {
            ans++;
            a.pop();
        } else {
            a.push(s[i]);
        }
    }    
    if (ans%2==1) cout << "Yes" << endl; else cout << "No" << endl;
    return 0;
}

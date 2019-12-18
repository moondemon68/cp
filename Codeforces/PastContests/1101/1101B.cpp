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
    int one=MOD,two=0,three=MOD,four=0;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='[') {
            one=i;
            break;
        }
    }    
    for (int i=s.size()-1;i>=0;i--) {
        if (s[i]==']') {
            four=i;
            break;
        }
    }
    if (one>four) {
        cout << -1 << endl;
        return 0;
    }
    for (int i=one;i<s.size();i++) {
        if (s[i]==':') {
            two=i;
            break;
        }
    }
    for (int i=four;i>=0;i--) {
        if (s[i]==':') {
            three=i;
            break;
        }
    }
    if (!(one<two&&two<three&&three<four)) {
        cout << -1 << endl;
        return 0;
    }
    int ans=4;
    for (int i=two;i<=three;i++) {
        if (s[i]=='|') ans++;
    }
    cout << ans << endl;
    return 0;
}

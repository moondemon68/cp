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
    string t;
    cin >> t;
    int d=t.size()-1;
    stack<char> a;
    for (int i=0;i<s.size();i++) a.push(s[i]);
    queue<char> b;
    bool y=0;
    while (d--) {
        if (!a.empty()) {
            if (a.top()!='0') y=1;
            b.push(a.top());
            a.pop();
        }
        else b.push('0');
    }   
    string ansa="",ansb="";
    if (a.empty()) {
        cout << "0.";
        for (int i=1;i<t.size()-s.size();i++) cout << 0;
        while (s.back()=='0') s.pop_back();
        cout << s;
    }
    else {
        while (!a.empty()) {
            ansa+=a.top();
            a.pop();
        }
        reverse(ansa.begin(),ansa.end());
        cout << ansa;
        if (y) {
            cout << ".";
            while (!b.empty()) {
                ansb+=b.front();
                b.pop();
            }
            reverse(ansb.begin(),ansb.end());
            while (ansb.back()=='0') ansb.pop_back();
            cout << ansb;
        }
    }
    return 0;
}

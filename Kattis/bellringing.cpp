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
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    int beda=0,sama=0;
    for (int i=0;i<s.size();i++) {
        if (s[i]==t[i]) sama++; else beda++;
    }    
    int bener=0;
    if (sama>=n) {
        sama-=n;
        bener+=n;
        cout << bener+beda << endl;
    } else {
        bener+=sama;
        n-=sama;
        bener+=beda-n;
        cout << bener << endl;
    }
    return 0;
}

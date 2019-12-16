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

bool p(int x) {
    string s="";
    while (x) {
        s+='0'+(x%10);
        x/=10;
    }
    string t=s;
    reverse(t.begin(),t.end());
    for (int i=0;i<s.size();i++) {
        if (s[i]!=t[i]) return 0;
    }
    return 1;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int l,r;
    cin >> l >> r;
    for (int i=l;i<=r;i++) {
        if (p(i)) cout << "Palindrome!" << endl;
        else cout << i << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
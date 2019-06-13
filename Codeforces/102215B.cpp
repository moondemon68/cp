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
    string s,t;
    cin >> s >> t;
    int a=0,b=0,c=0,d=0;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='#'&&t[i]=='.') a++;
        if (s[i]=='#'&&t[i]=='#') b++;
        if (s[i]=='.'&&t[i]=='#') c++;
        if (s[i]=='.'&&t[i]=='.') d++;
    }
    if (b>0||(b==0&&a>0&&c==0)||(b==0&&a==0&&c>0)) {
        cout << "YES" << endl;
        for (int i=0;i<a;i++) cout << '#';
        for (int i=0;i<b;i++) cout << '#';
        for (int i=0;i<c;i++) cout << '.';
        for (int i=0;i<d;i++) cout << '.';
        cout << endl;
        for (int i=0;i<a;i++) cout << '.';
        for (int i=0;i<b;i++) cout << '#';
        for (int i=0;i<c;i++) cout << '#';
        for (int i=0;i<d;i++) cout << '.';
    } else cout << "NO" << endl;
    
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
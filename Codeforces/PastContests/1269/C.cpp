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

string increase(string t) {
    string s = t;
    int i = s.size()-1;
    if (s[i] == '9') {
        int x = i;
        while (s[x] == '9') x--;
        s[x]++;
        for (int j=i;j>x;j--) {
            s[j] = '0';
        }
    } else {
        s[i]++;
    }
    return s;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int m = s.size();
    string p="";
    for (int i=0;i<k;i++) p+=s[i];
    //cout  << p << endl;
    bool up = 0, gajadi = 0;
    for (int i=k;i<m;i+=k) {
        string q = "";
        for (int j=0;j<k;j++) {
            if (i+j < m) q += s[i+j];
        }
        //cout << q << endl;
        if (p < q) up = 1;
        else if (p > q && !up) gajadi = 1;
    }
    if (up && !gajadi) p = increase(p);
    string a = "";
    while (a.size() < m) a += p;
    cout << m << endl;
    for (int i=0;i<m;i++) cout << a[i];
    cout << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
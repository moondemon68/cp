#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bool v(char a) {
    return a=='a'||a=='e'||a=='i'||a=='u'||a=='o';
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    s+='a';
    int p=0;
    cout << s[0];
    for (int i=1;i<s.size()-1;i++) {
        if (!(s[i]==s[i-1]&&s[i]==s[i+1])&&!v(s[i-1])&&!v(s[i])&&!v(s[i+1])) {
            cout << s[i] << " " << s[i+1];
            i++;
            if (i==s.size()-2) p++;
        } else {
            cout << s[i];
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s,t;
    cin >> s >> t;
    set<char> p;
    for (int i=0;i<t.size();i++) p.insert(t[i]);
    if (p.size()>1) {
        cout << 0 << endl;
        return 0;
    }
    char c=t[0];
    int cnt1=0,cnt2=0;
    for (int i=0;i<s.size();i++) if (s[i]==c) cnt1++; else cnt2++;
    while (1>0) {
        if (cnt1<=0) {
            cout << 0 << endl;
            return 0;
        } else if (cnt2<=0) {
            cout << cnt1-t.size()+1 << endl;
            return 0;
        }
        cnt1-=t.size()-1;
        cnt2--;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
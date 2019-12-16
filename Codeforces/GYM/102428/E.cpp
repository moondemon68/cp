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
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<int> v;
    int ans=0;
    int cnt=0;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='P') {
            cnt++;
        } else {
            v.pb(cnt);
            cnt=0;
            ans++;
        }
    }
    if (cnt>0) v.pb(cnt);
    for (int i=0;i<v.size();i++) cout << v[i] << " ";
    cout << endl;
    for (int i=0;i<k-1;i++) {
        if (s[i]=='P') {
            cnt++;
            if (i==0) {
                if (s[s.size()-1] == 'P') v.pop_back();
                v.pb(cnt);
            } else {
                if (s[i-1] == 'P') v.pop_back();
                v.pb(cnt);
            }
        } else {
            cnt=0;
        }
        for (int j=0;j<v.size();j++) cout << v[j] << " ";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
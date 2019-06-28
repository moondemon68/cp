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
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
        string s;
        cin >> s;
        int cnt[30];
        memset (cnt,0,sizeof(cnt));
        for (int i=0;i<s.size();i++) {
            cnt[s[i]-'a']++;
        }
        string b="",c="";
        for (int i=0;i<26;i+=2) if (cnt[i]>0) b+=(char)(i+'a');
        for (int i=1;i<26;i+=2) if (cnt[i]>0) c+=(char)(i+'a');
        string p=b+c,q=c+b;
        bool y=1;
        for (int i=0;i<p.size();i++) {
            if (abs(p[i]-p[i+1])==1) y=0;
        }
        if (y) {
            for (int i=0;i<p.size();i++) {
                for (int j=0;j<cnt[p[i]-'a'];j++) cout << p[i];
            }
            cout << endl;
            continue;
        } 
        y=1;
        for (int i=0;i<q.size();i++) {
            if (abs(q[i]-q[i+1])==1) y=0;
        }
        if (y) {
            for (int i=0;i<q.size();i++) {
                for (int j=0;j<cnt[q[i]-'a'];j++) cout << q[i];
            }
            cout << endl;
            continue;
        }
        cout << "No answer";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
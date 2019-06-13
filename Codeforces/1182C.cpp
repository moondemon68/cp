#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int cv(string s) {
    int ret=0;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='a'||s[i]=='u'||s[i]=='i'||s[i]=='o'||s[i]=='e') ret++;
    }
    return ret;
}

char lv(string s) {
    for (int i=s.size()-1;i>=0;i--) {
        if (s[i]=='a'||s[i]=='u'||s[i]=='i'||s[i]=='o'||s[i]=='e') return s[i];
    }
    return '*';
}

bool cmp(string a,string b) {
    return cv(a)<cv(b);
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string s[n+5];
    for (int i=1;i<=n;i++) cin >> s[i];
    vector<string> a[6];
    for (int i=1;i<=n;i++) {
        char x=lv(s[i]);
        if (x=='a') a[0].pb(s[i]);
        else if (x=='e') a[1].pb(s[i]);
        else if (x=='u') a[2].pb(s[i]);
        else if (x=='i') a[3].pb(s[i]);
        else if (x=='o') a[4].pb(s[i]);
        else a[5].pb(s[i]);
    }
    for (int i=0;i<=5;i++) sort (a[i].begin(),a[i].end(),cmp);
    vector<pair<string,string>> cand2;
    for (int k=0;k<=4;k++) {
        if ((int)a[k].size()>=2) {
            for (int i=0;i<(int)a[k].size()-1;i++) {
                if (cv(a[k][i])==cv(a[k][i+1])) {
                    cand2.pb(mp(a[k][i],a[k][i+1]));
                    a[k][i]="*";
                    a[k][i+1]="*";
                    i++;
                }
            }
        }
    }
    vector<string> p;
    for (int k=0;k<=5;k++) {
        for (int i=0;i<(int)a[k].size();i++) {
            if (a[k][i]!="*") p.pb(a[k][i]);
        }
    }
    sort (p.begin(),p.end(),cmp);
    vector<pair<string,string>> cand1;
    for (int i=0;i<(int)p.size()-1;i++) {
        if (cv(p[i])==cv(p[i+1])) {
            cand1.pb(mp(p[i],p[i+1]));
            i++;
        }
    }
    //cand2 num same, last same
    //cand1 num same
    int l=0,g=min(cand1.size(),cand2.size());
    cout << g+max((int)0,(int)(cand2.size()-g)/2) << endl;
    while (l<g) {
        cout << cand1[l].fi << " " << cand2[l].fi << endl;
        cout << cand1[l].se << " " << cand2[l].se << endl;
        l++;
    }
    while (l<(int)cand2.size()-1) {
        cout << cand2[l].fi << " " << cand2[l+1].fi << endl;
        cout << cand2[l].se << " " << cand2[l+1].se << endl;
        l++;
        l++;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
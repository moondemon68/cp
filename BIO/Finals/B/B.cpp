#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bool cmp(pair<string,int> a,pair<string,int> b) {
    return a.se>b.se;
}

int main () {
    clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream cin ("input_1.txt");
    ofstream cout ("output_1.txt");
    int n;
    cin >> n;
    string s[n+5];
    //cin >> s[1];
    
    int p=5; //1: 5, 2: 20, 3: 93, 4: 63
    for (int i=1;i<=p;i++) {
        cin >> s[i];
    }
    vector<string> a,b;
    int x=s[1].size();
    int ans[x+5];
    memset (ans,0,sizeof(ans));
    for (int i=0;i<x;i++) {
        string t="";
        for (int j=1;j<=p;j++) t+=s[j][i];
        a.push_back(t);
        b.push_back(t);
    }
    sort(a.begin(),a.end());
    a.push_back("2");
    map<string,int> m;
    for (int i=0;i<a.size();i++) {
        m[a[i]]++;
    }
    vector<pair<string,int>> type;
    for (int i=0;i<a.size()-1;i++) {
        if (a[i]!=a[i+1]) {
            type.push_back(mp(a[i],m[a[i]]));
        }
    }
    sort (type.begin(),type.end(),cmp);
    //for (int i=0;i<(int)type.size();i++) cout << type[i].fi << " " << type[i].se << endl;
    int group[20]={0,0,1,0,0,0,0,0,2,0,0,0,0,0,0,0,0,3,0};
    memset (ans,0,sizeof(ans));
    for (int i=1;i<=(int)b.size();i++) {
        for (int j=0;j<(int)type.size();j++) {
            if (b[i-1]==type[j].fi) {
                ans[i]=group[j];
                break;
            }
        }
    }
    for (int i=1;i<=(int)b.size();i++) cout << ans[i] << ' ';

    cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
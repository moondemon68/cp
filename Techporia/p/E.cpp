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

LL hash1(vector<vector<char>> v) {
    LL x = 1;
    LL ret = 0;
    for (int i=0;i<v.size();i++) {
        for (int j=0;j<v[0].size();j++) {
            ret += (LL)(v[i][j]) * x;
            ret %= MOD;
            x *= 256;
            x %= MOD;
        }
    }
    return ret;
}
LL hash2(vector<vector<char>> v) {
    LL x = 1;
    LL ret = 0;
    for (int j=0;j<v[0].size();j++) {
        for (int i=v.size()-1;i>=0;i--) {
            ret += (LL)(v[i][j]) * x;
            ret %= MOD;
            x *= 256;
            x %= MOD;
        }
    }
    return ret;
}
LL hash3(vector<vector<char>> v) {
    LL x = 1;
    LL ret = 0;
    for (int i=v.size()-1;i>=0;i--) {
        for (int j=v[0].size()-1;j>=0;j--) {
            ret += (LL)(v[i][j]) * x;
            ret %= MOD;
            x *= 256;
            x %= MOD;
        }
    }
    return ret;
}
LL hash4(vector<vector<char>> v) {
    LL x = 1;
    LL ret = 0;
    for (int j=v[0].size()-1;j>=0;j--) {
        for (int i=0;i<v.size();i++) {
            ret += (LL)(v[i][j]) * x;
            ret %= MOD;
            x *= 256;
            x %= MOD;
        }
    }
    return ret;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<pair<string,int>> nama;
    vector<pair<pair<LL, string>, int>> a;
    vector<bool> done;
    int cnt = 0;
    for (int i=0;i<n;i++) {
        string name;
        int m;
        cin >> name >> m;
        nama.pb({name, m});
        for (int j=1;j<=m;j++) {
            vector<vector<char>> tmp;
            for (int r=1;r<=k;r++) {
                vector<char> tmp2;
                string s;
                cin >> s;
                for (int c=1;c<=k;c++) {
                    tmp2.pb(s[c-1]);
                }
                tmp.pb(tmp2);
            }
            a.pb({{hash1(tmp), name}, cnt});
            a.pb({{hash2(tmp), name}, cnt});
            a.pb({{hash3(tmp), name}, cnt});
            a.pb({{hash4(tmp), name}, cnt});
            done.pb(0);
            cnt++;
        }
    }
    sort (nama.begin(), nama.end());
    sort (a.begin(), a.end());
    // for (int i=0;i<a.size();i++) {
    //     cout << a[i].fi.fi << " " << a[i].fi.se << " " << a[i].se << endl;
    // }
    a.pb({{-1LL, "BUDI"}, -1});
    // cout << "-" << endl;
    int last = 0;
    for (int i=0;i<a.size()-1;i++) {
        if (a[i].fi.fi != a[i+1].fi.fi) {
            if (a[last].se == a[i].se || done[a[i].se]) {
                last = i+1;
                continue;
            }
            
            // set<int> belum;
            // for (int j=last;j<=i;j++) {
            //     if (!done[a[j].se]) belum.insert(a[j].se);
            // }
            // if (belum.empty()) {
            //     last = i+1;
            //     continue;
            // }

            bool saved = 0;
            for (int j=last;j<=i;j++) {
                if (done[a[j].se]) continue;
                if (!saved) {
                    done[a[j].se] = 1;
                    saved = 1;
                    continue;
                }
                // cout << a[j].fi.fi << " " << a[j].fi.se << endl;
                for (int p=0;p<nama.size();p++) {
                    if (nama[p].fi == a[j].fi.se) {
                        nama[p].se--;
                        done[a[j].se] = 1;
                        break;
                    }
                }
            }
            last = i+1;
        }
    }

    for (int i=0;i<nama.size();i++) {
        cout << nama[i].fi << " " << nama[i].se << endl;
    }
    
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
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
    // ifstream cin("input.txt");
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++){
        string ans = "----------";
        int u;
        cin >> u;
        pair<LL, string> a[10005];
        for (int i=1;i<=10000;i++) {
            cin >> a[i].fi >> a[i].se;
        }
        sort (a+1,a+10001);
        int cnt[10][30];
        memset (cnt,0,sizeof(cnt));
        for (int i=1;i<=10000;i++) {
            // while (a[i].fi >= 10) a[i].fi /= 10;
            // for (int j=a[i].fi;j<=a[i].fi;j++) {
            //     cnt[j][a[i].se[0]-'A']++;
            // }
            // for (int j=0;j<a[i].se.size();j++) {
            if (a[i].se.size() >= 14) cnt[0][a[i].se[0]-'A']++;
            // }
        }
        string al = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        set<int> s;
        deque<pair<int, char>> anss;
        for (int i=1;i<=9;i++) {
            int maxcnt = 0, cand = -1;
            for (int j=0;j<=25;j++) {
                if (i == 1 && cnt[0][j] > 0) {
                    // cerr << cnt[0][j] << " " << al[j] << " ";
                    anss.pb({cnt[0][j], al[j]});
                }
                if (cnt[i][j] >= maxcnt) {
                    if (s.find(j) == s.end()) {
                        maxcnt = cnt[i][j];
                        cand = j;
                    }
                }
            }
            s.insert(cand);
            ans[i] = al[cand];
        }
        sort (anss.begin(), anss.end());
        reverse(anss.begin(), anss.end());
        anss.push_front(anss.back());
        cout << "Case #" << t << ": ";
        for (int i=0;i<anss.size()-1;i++) cout << anss[i].se;
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
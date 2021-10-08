#include <bits/stdc++.h>

using namespace std;

const LL N = 1005;
const LL M = 5005;
const LL INF = 1e9 + 7;
LL n, m, k;
vector<pair<LL, LL>> arr[9];
LL se[9][50 * M], res[3][N];

bool cmp(pair<LL, LL> a, pair<LL, LL> b) {
    return (a.second * b.first) < (a.first * b.second);
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<string, LL> mp;
    mp["Zulian"] = 0; // 3,4
    mp["Razzashi"] = 1; // 5
    mp["Hakkari"] = 2;// 7

    mp["Sandfury"] = 3;
    mp["Skullsplitter"] = 4;
    mp["Bloodscalp"] = 5;

    mp["Gurubashi"] = 6;
    mp["Vilebranch"] = 7;
    mp["Witherbark"] = 8;

    cin >> n >> m;
    for(LL i = 1; i <= m; i++) {
        string s;
        LL a, b;
        cin >> s >> a >> b;

        arr[mp[s]].push_back({a, b});
    }
    for(LL i = 0; i < 9; i++) {
        sort(arr[i].begin(), arr[i].end(), cmp);
        for(LL j = 1; j <= n; j++) {
            se[i][j] = -1;
        }
    }

    for(LL i = 0; i < 9; i++) {
        LL cur = 1;
        for(auto x : arr[i]) { 
            LL h = se[i][cur - 1] + x.second;
            for(LL j = cur; j <= cur + x.first - 1; j++){
                se[i][j] = h;
            }
            cur = cur + x.first;
        }
    }

    for(LL i = 0; i < 9; i += 3) {
        for(LL j = 1; j <= n; j++){
            if(se[i][j] != -1 && se[i + 1][j] != -1 && se[i + 2][j] != -1){
                res[i / 3][j] = se[i][j] + se[i + 1][j] + se[i + 2][j];
            } else {
                res[i / 3][j] = -1;
            };
        }
    }
    LL ans = INF;
    for(LL i = 0; i <= n; i++) {
        for(LL j = 0; j <= n; j++){
            
            LL k = n - i - j;
            if(k >= 0) {
                vector<LL> ve = {0, 1, 2};
                do {
                    if(res[ve[0]][i] != -1 && res[ve[1]][j] != -1 && res[ve[2]][k] != -1) {
                        ans = min(ans, res[ve[0]][i] + res[ve[1]][j] + res[ve[2]][k]);
                    }
                } while(next_permutation(ve.begin(), ve.end()));
            }
        }
    }

    if(ans == INF) {
        cout << "impossible\n";
    } else {
        cout << ans << '\n';
    }
    return 0;
}
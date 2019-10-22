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
    while (tc--) {
        string s;
        cin >> s;
        vector<int> a[30];
        for (int i=0;i<s.size();i++) {
            a[s[i]-'a'].pb(i+1);
        }
        int cnt=0;
        for (int i=0;i<26;i++) {
            if (a[i].size() % 2 == 1) cnt++;
        }
        if (cnt > 1) {
            cout << -1;
        } else {
            deque<int> ans;
            int p=-1;
            for (int i=0;i<26;i++) {
                if (a[i].size() % 2 == 1) {
                    p=i;
                    for (int j=1;j<a[i].size();j+=2) {
                        ans.push_back(a[i][j]);
                        ans.push_front(a[i][j+1]);
                    }
                } else {
                    for (int j=0;j<a[i].size();j+=2) {
                        ans.push_back(a[i][j]);
                        ans.push_front(a[i][j+1]);
                    }
                }
            }
            if (p != -1) {
                for (int i=0;i<ans.size()/2;i++) {
                    cout << ans[i] << " ";
                }
                cout << a[p][0] << " ";
                for (int i=ans.size()/2;i<ans.size();i++) {
                    cout << ans[i] << " ";
                }
            } else {
                for (int i=0;i<ans.size();i++) {
                    cout << ans[i] << " ";
                }
            }
        }
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
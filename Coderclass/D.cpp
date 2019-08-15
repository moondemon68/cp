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
    int tc;
    cin >> tc;
    for (int t=1;t<=tc;t++) {
        int n;
        cin >> n;
        cin.ignore();
        queue<int> p[n+5];
        for (int i=1;i<=n;i++) {
            string s;
            getline(cin,s);
            int cnt=0,last=0,g=0;
            for (int j=0;j<s.size();j+=2) {
                if (s[j]=='m'||s[j]=='k'||s[j]=='b') g=1;
                else if (s[j]=='a'||s[j]=='p') g=2;
                else g=3;
                if (j==0) {
                    last=g;
                    cnt++;
                } else {
                    if (g==last) {
                        if (cnt<5) cnt++;
                        else {
                            p[i].push(last);
                            cnt=1;
                        }
                    } else {
                        p[i].push(last);
                        cnt=1;
                        last=g;
                    }
                }
            }
            p[i].push(g);
            //for (int j=0;j<p[i].size();j++) cout << p[i][j].fi << p[i][j].se << " ";
            //cout << endl;
        }
        queue<pii> q1,q2,q3; // id
        for (int i=1;i<=n;i++) {
            if (p[i].front()==1) q1.push({i,1});
            else if (p[i].front()==2) q2.push({i,2});
            else q3.push({i,3});
        }
        //cerr << q1.size() << q2.size() << q3.size();
        int m=3;
        vector<pii> ans;
        while (!(q1.empty()&&q2.empty()&&q3.empty())) {
            if (m==3) m=1;
            else if (m==1) m=2;
            else if (m==2) m=3;
            if (m==1) {
                if (q1.empty()) continue;
                else {
                    ans.pb(q1.front());
                    p[q1.front().fi].pop();
                    if (p[q1.front().fi].empty()) {
                        q1.pop();
                        continue;
                    }
                    if (p[q1.front().fi].front()==1) q1.push({q1.front().fi,1});
                    else if (p[q1.front().fi].front()==2) q2.push({q1.front().fi,2});
                    else q3.push({q1.front().fi,3});
                    q1.pop();
                }
            } else if (m==2) {
                if (q2.empty()) continue;
                else {
                    ans.pb(q2.front());
                    p[q2.front().fi].pop();
                    if (p[q2.front().fi].empty()) {
                        q2.pop();
                        continue;
                    }
                    if (p[q2.front().fi].front()==1) q1.push({q2.front().fi,1});
                    else if (p[q2.front().fi].front()==2) q2.push({q2.front().fi,2});
                    else q3.push({q2.front().fi,3});
                    q2.pop();
                }
            } else {
                if (q3.empty()) continue;
                else {
                    ans.pb(q3.front());
                    p[q3.front().fi].pop();
                    if (p[q3.front().fi].empty()) {
                        q3.pop();
                        continue;
                    }
                    if (p[q3.front().fi].front()==1) q1.push({q3.front().fi,1});
                    else if (p[q3.front().fi].front()==2) q2.push({q3.front().fi,2});
                    else q3.push({q3.front().fi,3});
                    q3.pop();
                }
            }
        }
        cout << "Kasus #" << t << endl;
        for (int i=0;i<ans.size();i++) {
            bool y=1;
            for (int j=i;j<ans.size();j++) {
                if (ans[i]!=ans[j]) y=0;
            }
            if (i==ans.size()-1||!y) cout << "Pembeli #" << ans[i].fi << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a;
    getline(cin, a);
    vector<pair<int, int>> v;
    a = '#' + a;
    string temp = "";
    int x = -1, y = -1, cnt = 0;
    for (int i = 1; i <= (int) a.size(); i++) {
        if ('0' <= a[i] && a[i] <= '9') {
            temp += a[i];
        } else if (temp != ""){
            cnt++;
            if (cnt & 1) {
                x = stoi(temp);
            } else {
                y = stoi(temp);
                v.push_back({x, y});
            }
            temp = "";
        }
    }
    for (int i=0;i<v.size();i++) {
        if (v[i].se<v[i].fi) v[i].se+=50;
    }
    stack<pii> t;
    t.push(v[0]);
    for (int i=1;i<v.size();i++) {
        pii top = t.top();
        if (top.se<v[i].fi) t.push(v[i]);
        else if (top.se<v[i].se) {
            top.se = v[i].se;
            t.pop();
            t.push(top);
        }
    }
    vector<pii> p;
    while (!t.empty()) {
        cout << t.top().fi << " " << t.top().se << endl;
        p.push_back(t.top());
        t.pop();
    }
    return 0;
}
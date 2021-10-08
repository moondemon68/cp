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

set<string> stop;

string normalize(string s) {
    string t = "";
    for (int i=0;i<s.size();i++) {
        if (s[i] == ',' || s[i] == '.' || s[i] == '?' || s[i] == '!' ) {
            continue;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            t += s[i]+32;
        } else if ((s[i] >= 'a' && s[i] <= 'z') || s[i] == '\'') {
            t += s[i];
        }
    }
    if (stop.count(t)) return "";
    return t;
}

bool cmp(pair<int, string> a, pair<int, string> b) {
    if (a.fi == b.fi) return a.se < b.se;
    else return a.fi > b.fi;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");

    string s;

    // stop words
    getline(cin, s);
    s+= ';';
    string curword = "";
    for (int i=0;i<s.size();i++) {
        if (s[i] == ';') {
            stop.insert(curword);
            curword = "";
        } else {
            curword += s[i];
        }
    }

    // index terms
    getline(cin, s);
    s+= ';';
    set<string> index;
    map<string, int> indexscore;
    curword = "";
    for (int i=0;i<s.size();i++) {
        if (s[i] == ';') {
            index.insert(curword);
            indexscore[curword] = 0;
            curword = "";
        } else {
            curword += s[i];
        }
    }

    // pain and suffering
    int type = 0; // 0 gaada, 1 tag, 2 kata, 3 title, 4 abstract, 5 body
    vector<string> title, abstract, body;
    bool clostag = 0;
    string curtag = "";
    while (getline(cin, s)) {
        s+= ' ';
        curword = "";
        for (int i=0;i<s.size();i++) {
            if (s[i] == '<') {
                clostag = 0;
                if (curtag == "title") {
                    if (normalize(curword).size() >= 4) {
                        // cout << "title" << " -> " << normalize(curword) << endl;
                        title.pb(curword);
                    }
                } else if (curtag == "abstract") {
                    if (normalize(curword).size() >= 4) {
                        // cout << "abstract" << " -> " << normalize(curword) << endl;
                        abstract.pb(curword);
                    }
                } else if (curtag == "body") {
                    if (normalize(curword).size() >= 4) {
                        // cout << "body" << " -> " << normalize(curword) << endl;
                        body.pb(curword);
                    }
                }
                curword = "";
                continue;
            } else if (s[i] == '/') {
                clostag = 1;
                continue;
            } else if (s[i] == '>') {
                if (curword == "title" || curword == "abstract" || curword == "body") {
                    if (clostag) {
                        clostag = 0;
                        curtag = "";
                    } else {
                        curtag = curword;
                    }
                }
                curword = "";
                continue;
            } else if (s[i] == ' ') {
                if (curtag == "title") {
                    if (normalize(curword).size() >= 4) {
                        // cout << "title" << " -> " << normalize(curword) << endl;
                        title.pb(curword);
                    }
                } else if (curtag == "abstract") {
                    if (normalize(curword).size() >= 4) {
                        // cout << "abstract" << " -> " << normalize(curword) << endl;
                        abstract.pb(curword);
                    }
                } else if (curtag == "body") {
                    if (normalize(curword).size() >= 4) {
                        // cout << "body" << " -> " << normalize(curword) << endl;
                        body.pb(curword);
                    }
                }
                curword = "";
                continue;
            }
            curword += s[i];
        }
    }
    
    // cout << title.size() << " " << abstract.size() << " " << body.size() << endl;

    for (int i=0;i<title.size();i++) title[i] = normalize(title[i]);
    for (int i=0;i<abstract.size();i++) abstract[i] = normalize(abstract[i]);
    for (int i=0;i<body.size();i++) body[i] = normalize(body[i]);

    // for (int i=0;i<title.size();i++) cout << title[i] << " ";
    // cout << endl;
    // for (int i=0;i<abstract.size();i++) cout << abstract[i] << " ";
    // cout << endl;
    // for (int i=0;i<body.size();i++) cout << body[i] << " ";
    // cout << endl;

    for (int i=0;i<title.size();i++) {
        indexscore[title[i]] += 5; 
    }
    for (int i=0;i<abstract.size();i++) {
        indexscore[abstract[i]] += 3; 
    }
    for (int i=0;i<body.size();i++) {
        indexscore[body[i]] += 1; 
    }

    vector<pair<int, string>> v;
    set<string> done;
    for (int i=0;i<title.size();i++) {
        if (index.count(title[i]) && !done.count(title[i])) {
            v.pb({indexscore[title[i]], title[i]});
            done.insert(title[i]);
        }
    }
    for (int i=0;i<abstract.size();i++) {
        if (index.count(abstract[i]) && !done.count(abstract[i])) {
            v.pb({indexscore[abstract[i]], abstract[i]});
            done.insert(abstract[i]);
        }
    }
    for (int i=0;i<body.size();i++) {
        if (index.count(body[i]) && !done.count(body[i])) {
            v.pb({indexscore[body[i]], body[i]});
            done.insert(body[i]);
        }
    }
    
    sort (v.begin(), v.end(), cmp);
    int tot = title.size() + abstract.size() + body.size();
    for (int i=0;i<min(3, (int)v.size());i++) {
        cout << v[i].se << ": " << fixed << setprecision(9) << (double)v[i].fi / tot * 100  << endl;
    }
    if (v.size() > 3) {
        for (int i=3;i<v.size();i++) {
            if (v[i].fi == v[2].fi) cout << v[i].se << ": " << fixed << setprecision(9) << (double)v[i].fi / tot * 100  << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

map<string, string> m;

string sulap(string p) {
    string ret = "";
    bool y=0;
    for (int i=0;i<p.size();i++) {
        if (p[i]=='`' && !y) {
            y = 1;
        } else if (p[i]=='`' && y) {
            y = 0;
            return ret;
        } else if (p[i]=='$') {
            if (p[i+2]=='`') {
                i+=3;
                int cnt = 1;
                string tmp = "`";
                while (cnt) {
                    if (p[i]=='{') cnt++;
                    if (p[i]=='}') {
                        cnt--;
                        if (cnt == 0) break;
                    }
                    tmp+=p[i];
                    i++;
                }
                if (p[i]!='}') i++;
                // cout << tmp << endl;
                ret += sulap(tmp);
            } else {
                string tmp = "";
                i+=2;
                while (p[i]!='}') {
                    tmp+=p[i];
                    i++;
                }
                ret += m[tmp];
            }
        } else {
            ret += p[i];
        }
    }
    return ret;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s="ayamgoreng";
    while (s != "end.") {
        getline(cin, s);
        string cmd = "";
        int p=0;
        while (p < s.size()-1) {
            if (s[p]==';') break;
            else if (s[p]==' ') break;
            else cmd+=s[p];
            p++;
        }
        p++;
        if (cmd == "var") {
            string var = "";
            while (p < s.size()-1) {
                if (s[p]==';') break;
                else if (s[p]==' ') break;
                else var+=s[p];
                p++;
            }
            p+=3;
            string sisanya = "";
            while (p < s.size()-1) {
                if (s[p]==';') break;
                else sisanya+=s[p];
                p++;
            }
            if (sisanya[0]=='\"') {
                string tmp = "";
                for (int i=1;i<sisanya.size()-1;i++) tmp+=sisanya[i];
                m[var]=tmp;
            } else if (sisanya[0]=='`') {
                sisanya.insert(sisanya.begin(), '{');
                sisanya.insert(sisanya.begin(), '$');
                sisanya += '}';
                // cout << sisanya << endl;
                m[var]=sulap(sisanya);
            } else {
                m[var]=m[sisanya];
            }
        } else if (cmd == "print") {
            string sisanya = "";
            while (p < s.size()-1) {
                if (s[p]==';') break;
                else sisanya+=s[p];
                p++;
            }
            if (sisanya[0]=='\"') {
                string tmp = "";
                for (int i=1;i<sisanya.size()-1;i++) tmp+=sisanya[i];
                cout << tmp << endl;
            } else if (sisanya[0]=='`') {
                sisanya.insert(sisanya.begin(), '{');
                sisanya.insert(sisanya.begin(), '$');
                sisanya += '}';
                // cout << sisanya << endl;
                cout << sulap(sisanya) << endl;
            } else {
                cout << m[sisanya] << endl;
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
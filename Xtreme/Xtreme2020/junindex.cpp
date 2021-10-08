#include <bits/stdc++.h>

using namespace std;

string res = "", s, stopword, indexword;
map<string, int> score, cnt;
set<string> st;

const double EPS = 0.000001;

bool cmp(pair<pair<int, int>, string> a, pair<pair<int, int>, string> b){
    if(a.first.first == b.first.first && a.first.second && b.first.second) {
        return a.second < b.second;
    } else {
        pair<int, int> x = a.first;
        pair<int, int> y = b.first;
        return x.first * y.second > x.second * y.first;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ifstream cin("input.txt");

    getline(cin, stopword);
    getline(cin, indexword);

    string cur = "";
    for(auto x : stopword) {
        if(x == ';'){
            if(cur != ""){
                st.insert(cur);
                cur = "";
            }
        } else {
            cur += x;
        }
    }
    if(cur != ""){
        st.insert(cur);
        cur = "";
    }
    cur = "";
    for(auto x : indexword) {
        if(x == ';'){
            if(cur != ""){
                score[cur] = 0;
                cnt[cur] = 0;
                cur = "";
            }
        } else {
            cur += x;
        }
    }
    if(cur != ""){
        score[cur] = 0;
        cnt[cur] = 0;
        cur = "";
    }

    while(getline(cin, s)) {
        res += s + ' ';
    }

    int len = res.size();
    for(int i = 0; i < len; i++) {
        if(res[i] >= 'A' && res[i] <= 'Z'){
            res[i] = res[i] - 'A' + 'a';
        }
    }

    int idxf = -1;
    int idxl = -1;
    cur = "";
    string curtag = "";
    int total = 0;
    for(int i = 0; i < len; i++) {
        if(res[i] == '<') {
            idxf = i;

            if(i + 1 < len && res[i + 1] == '/'){
                if(curtag == "title" || curtag == "abstract" || curtag == "body") {
                    if(cur.size() >= 4 && !st.count(cur)){
                        //cout << cur << '\n';
                        total++;
                        cout << cur << " ";

                    }

                    if(cnt.find(cur) != cnt.end()) {
                        if(curtag == "title"){
                            score[cur] += 5;
                            cnt[cur]++;
                        } else if(curtag == "abstract") {
                            score[cur] += 3;
                            cnt[cur]++;
                        } else if(curtag == "body") {
                            score[cur]++;
                            cnt[cur]++;
                        }
                    }
                }

               
                cur += '/';
            } else {
                cur += res[i];
            }
        } else if(res[i] == '>') {
            idxl = i;
            if(res[idxf] == '<') {
                if(res[idxf + 1] != '/') {
                    //opening tag
                    string tmp = "";
                    for(int j = idxf + 1; j <= idxl - 1; j++){
                        tmp += res[j];
                    }
                    if(tmp == "title" || tmp == "abstract" || tmp == "body") { 
                        curtag = tmp;
                    }
                } else {
                    //closing tag
                    string tmp = "";
                    for(int j = idxf + 1; j <= idxl - 1; j++){
                        tmp += res[j];
                    }
                    if(tmp == "/title" && curtag == "title"){
                        curtag = "";
                    } else if(tmp == "/abstract" && curtag == "abstract") {
                        curtag = "";
                    } else if(tmp == "/body" && curtag == "body") {
                        curtag = "";
                    }
                }
            }
            cur = "";
        } else if((res[i] >= 'a' && res[i] <= 'z') || res[i] == '\'' || res[i] == '/'){
            if(i == 0 || res[i - 1] == '>' || res[i - 1] == '.' || res[i - 1] == '?' || res[i - 1] == ',' || res[i - 1] == '!' || res[i - 1] == ' ' || res[i - 1] == '\n') {
                idxf = i;
            }
            cur += res[i];
        } else {
            if(res[i] == '<' || res[i] == ' ' || res[i] == '\n'){
                if(cur != "") {
                    if(curtag == "title" || curtag == "abstract" || curtag == "body") {
                        if(cur.size() >= 4 && !st.count(cur)){
                            //cout << cur << '\n';
                            total++;
                            cout << cur << " ";
                        }

                        if(cnt.find(cur) != cnt.end()) {
                            if(curtag == "title"){
                                score[cur] += 5;
                                cnt[cur]++;
                            } else if(curtag == "abstract") {
                                score[cur] += 3;
                                cnt[cur]++;
                            } else if(curtag == "body") {
                                score[cur]++;
                                cnt[cur]++;
                            }
                        }
                    }
                    
                    cur = "";
                }
            }
            
        }
    }
    if(cur != "") {
        if(curtag == "title" || curtag == "abstract" || curtag == "body") {
            if(cur.size() >= 4 && !st.count(cur)){
                //cout << cur << '\n';
                total++;
                cout << cur << " ";
            }

            if(cnt.find(cur) != cnt.end()) {
                if(curtag == "title"){
                    score[cur] += 5;
                    cnt[cur]++;
                } else if(curtag == "abstract") {
                    score[cur] += 3;
                    cnt[cur]++;
                } else if(curtag == "body") {
                    score[cur]++;
                    cnt[cur]++;
                }
            }
        }
        
        cur = "";
    }
    vector<pair<pair<int, int>, string>> ans;
    for(auto x : score) {
        if(x.second > 0){
            //cout << x.first << " -> " << x.second << '\n';
            int gc = __gcd(x.second, total);
            pair<int, int> gege = {x.second / gc, total / gc};
            ans.push_back({gege, x.first});
        }
    }

    sort(ans.begin(), ans.end(), cmp);
    int siz  = ans.size();
    for(int i = 0; i < min(3, siz); i++){
        double re = ans[i].first.first;
        double pe = ans[i].first.second;
        double ge = re / pe;
        ge = ge * 100.00;
        cout << ans[i].second << ": ";
        cout << fixed << setprecision(9) << ge << '\n';
    }

    if(siz > 3) {
        for(int i = 3; i < siz; i++){
            if(ans[i].first.first == ans[2].first.first && ans[i].first.second == ans[2].first.second){
                double re = ans[i].first.first;
                double pe = ans[i].first.second;
                double ge = re / pe;
                ge = ge * 100.00;
                cout << ans[i].second << ": ";
                cout << fixed << setprecision(9) << ge << '\n';
            } else {
                break;
            }
        }
    }

    return 0;
}
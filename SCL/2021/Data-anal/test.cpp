#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
int n, par[N], siz[N], val[N];
long long groupsum[N];
vector<int> group[N];


//first initialize all the value
void build(){
    for(int i = 0; i < n; i++){
        par[i] = i;
        siz[i] = 1;
    }
}

int find(int v){
    if(par[v] == v){
        return v;
    } else {
        return (par[v] = find(par[v]));
    }
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(siz[a] < siz[b]){
            swap(a, b);
        }
        siz[a] += siz[b];
        par[b] = a;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    n = 500000;

    build();


    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        val[a] = b;
        if(c != -1) {
            unite(a, c);
        }
    }


    for(int i = 0; i < n; i++) {
        int parr = find(i);
        group[parr].push_back(i);

        groupsum[parr] += (long long) val[i];
    }

    for(int i = 0; i < n; i++) {
        sort(group[i].begin(), group[i].end());
    }
    cout << "ticket_id,ticket_trace/contact\n";
    for(int i = 0; i < n; i++) {
        cout << i << ",\"";
        int parr = find(i);
        int siz = group[parr].size();
        for(int j = 0; j < siz; j++) {
            cout << group[parr][j] << ((j == siz - 1) ? ", " : "-");
        }

        cout << groupsum[parr] << "\"\n";
    }

    return 0;
}
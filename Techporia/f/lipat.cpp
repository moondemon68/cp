#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> vc;

void gen(int n){
    int g = n - 1;
    int h = 1;
    for(int i = 1; i <= n / 2; i += 2){
        vc.push_back({h, n});
        if(g != h)
            vc.push_back({g, n});
        g -= 2;
        h += 2;
    }
}

void gentot(int n){
    int m = 2;
    for(int i = 1; i <= n; i++){
        gen(m);
        m *= 2;
    }
}

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    gentot(10);
    int t;
    cin >> t;
    while(t--){
        cin >> n;

        n--;
        cout << vc[n].first << " " << vc[n].second << " ";
    }
    return 0;
}
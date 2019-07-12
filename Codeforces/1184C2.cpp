#include<bits/stdc++.h>
using namespace std;
    
struct E{
    int u,v;
    long long w;
};
    
int n,m;
E s;
vector<E> g;
vector<int> par;
    
int find(int x){
    if(par[x] == x)return x;
    return par[x] = find(par[x]);
}
    
bool cmpr(E a, E b){
    return a.w < b.w;
}
    
bool can(long long x){
    vector<E> t = g; s.w = x;
    t.push_back(s);
    for(int i=1;i<=n;i++)par[i] = i;
    sort(t.begin(),t.end(),cmpr);
    int cnt = 0;
    long long cur = 0;
    
    int len = t.size();
    
    for(int i=0;i<len;i++){
        int pu = find(t[i].u);
        int pv = find(t[i].v);
    
        if(pu != pv){
            par[pu] = pv;
            cur += t[i].w;
    
            cnt++;
            if(cnt == n - 1)break;
        }
    }
    
    for(int i=1;i<=n;i++)par[i] = i;
    cnt = 1;
    long long cur2 = x;
    par[s.v] = s.u;
    
    for(int i=0;i<len;i++){
        int pu = find(t[i].u);
        int pv = find(t[i].v);
    
        if(pu != pv){
            par[pu] = pv;
            cur2 += t[i].w;
    
            cnt++;
            if(cnt == n - 1)break;
        }
    }
    
    //cerr << x << " => " << cur << " " << cur2 << '\n';
    
    return cur == cur2;
}
    
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    par.resize(n+3);
    for(int i=1;i<=m;i++){
        E temp;
        cin >> temp.u >> temp.v >> temp.w;
        if(i == 1){
            s = temp;
        }else{
            g.push_back(temp);
        }
    }
    
    long long l = 0, r = 1e9, ans = 0;
    while(l <= r){
        long long mid = (l+r)>>1;
        if(can(mid)){
            l = mid+1;
            ans = mid;
        }else{
            r = mid-1;
        }
    }
    cout << ans << '\n';
    
    return 0;
}
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define LL long long
#define pii pair<LL,int>
using namespace std;

LL a[200005];
pii tree[800005];
LL lazy[800005];

pii mini (pii a,pii b) {
    if (a.fi==b.fi) {
        if (a.se>b.se) return a;
        else return b;
    }
    else if (a.fi<b.fi) return a;
    else return b;
}

void build(int n,int s,int e) {
    if (s==e) {
        tree[n]={a[s],s};
        return;
    }
    int m=(s+e)/2;
    build(2*n,s,m);
    build(2*n+1,m+1,e);
    tree[n]=mini(tree[2*n],tree[2*n+1]);
}

void fix(int n,int s,int e) {
    if (lazy[n]==0) return;
    tree[n].fi-=lazy[n];
    if (s!=e) {
        lazy[2*n]+=lazy[n];
        lazy[2*n+1]+=lazy[n];
    }
    lazy[n]=0;
}

void update(int n,int s,int e,int ql,int qr,LL val) {
    fix(n,s,e);
    if (e<ql||s>qr) return;
    if (s>=ql&&e<=qr) {
        lazy[n]+=val;
        fix(n,s,e);
        return;
    }
    int m=(s+e)/2;
    update(2*n,s,m,ql,qr,val);
    update(2*n+1,m+1,e,ql,qr,val);
    tree[n]=mini(tree[2*n],tree[2*n+1]);
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    build(1,1,n);
    int ans[n+5];
    memset (ans,0,sizeof(ans));
    for (int i=1;i<=n;i++) {
        fix(1,1,n);
        pii ret=tree[1];
        ans[ret.se]=i;
        update(1,1,n,ret.se,ret.se,-1000000000000000);
        update(1,1,n,ret.se+1,n,i);
    }
    for (int i=1;i<=n;i++) cout << ans[i] << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
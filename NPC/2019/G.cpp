#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long
using namespace std;

pii p[100115],c[100115],P0;

double triangleArea(pii a,pii b, pii c) {
    return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}

LL sqDist(pii a,pii b) {
    return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

bool cmp(pii a,pii b) {
    double d=triangleArea(P0,a,b);
    if (d<0) return 0;
    return !(d==0&&sqDist(P0,a)>sqDist(P0,b));
} 

bool normal(pii a,pii b) {
    if (a.x==b.x) {
        return a.y<b.y;
    } else {
        return a.x<b.x;
    }
}

bool same(pii a,pii b) {
    return a.x==b.x && a.y==b.y;
}

void nosame(LL &np) {
    sort (p,p+np,normal);
    np=unique(p,p+np,same)-p;
}

void convexhull(LL &np, LL &nc) {
    LL pos=0,j;
    for (LL i=1;i<np;i++) {
        if (p[i].y<p[pos].y || (p[i].y==p[pos].y && p[i].x<p[pos].x)) pos=i;
    }
    swap(p[0],p[pos]);
    P0 = p[0];
    sort(&p[1],&p[np],cmp);
    for (LL i=0;i<3;i++) {
        c[i]=p[i];
    }
    for (LL i=j=3;i<np;i++) {
        while (triangleArea(c[j-2],c[j-1],p[i])<0) j--;
        c[j++]=p[i];
    }
    nc=j;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    double ans;
    LL np,nc;
    cin >> np;
    for (LL i=0;i<np;i++) cin >> p[i].x >> p[i].y;
    nosame(np);
    convexhull(np,nc);
    sort (c,c+nc,cmp);
    c[nc]=c[0];
    ans=0;
    //cout << endl;
    for (LL i=1;i<nc-1;i++) {
        ans+=abs(triangleArea(c[0], c[i], c[i+1]));
    }
    cout << fixed << setprecision(2) << ans/2 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
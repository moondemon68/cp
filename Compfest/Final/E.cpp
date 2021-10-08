/**
arF: 2 1 1 1 9  | -8
arA: 5 6 7 8 10 | 2
arD: 3 5 6 7 1  | 10
dikasih arF dimana arF = arA-arD, bagi jadi k + 1, supaya tot(sub arF[i]) + tot(arD di sub[i]) - 2 * min(arD di sub[i]) yang positif semuanya ditotalin max
tot(sub[i]) > 2*min(arD di sub[i]) - tot(arD di sub[i])
tot(sub[i]) + tot(arD di sub[i]) - 2 * min(arD di sub[i]) > 0

https://www.geeksforgeeks.org/cutting-a-rod-dp-13/

5 6 7 8 10 2
3 5 6 7 1 10

-8 + 

N = 6
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
1 -> 3 -> 4 -> 2 -> 5 -> 1 

To make a cycle, we HAVE to change E[n-1] to 1.
We can switch nodes for cycle of size 3, while keeping it connected.

tot(arA) - min(arD)
if (K == 0) udah dikerjain

untuk K >= 1,

node paling kanan gabisa diapa2in, nanti di jawaban tambahin sama max(0, a[N]-d[N]) aja.
if (K-1 % 3 == 0) ans = tot(arA) - 1 minimum val dari arD, harus handle gabisa diambil // max(tot(arA) - min(arD) , 0)
if (K-1 % 3 == 1) ans = tot(arA) - 2 minimum val dari arD, harus handle gabisa diambil // max(preftot(arA[i]) - prefmin(arD[i]) , 0) + max(suftot(arA[i]) - sufmin(arD[i]) , 0)
if (K-1 % 3 == 2) ans = tot(arA) - 3 minimum val dari arD, harus handle gabisa diambil -> ini kalo di iterate pake prefix sama min? segtree? O(n2logn)

yang ketiga -> tot(arA) - 3 minimum, tot(arA) - 3 minimum + 1 minimum + subarray yg gakepake, tot(arA) - 3 minimum  + 2minimum + 2 subarray

**/

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using ll = long long;
#define LL long long

int n, k;

// all example usages assume that array a is 1-indexed
const int NMAX = 100000;
LL t[4*NMAX+3];
LL lazy[4*NMAX+3];
ll a[NMAX + 5], d[NMAX + 5];

// build(1,1,n);
void build(int v, int s, int e) {
    if (s == e){
        t[v] = a[s];
    } else {
        int m = (s+e)/2;
        build(2*v, s, m);
        build(2*v+1, m+1, e);
        t[v] = min(t[2*v], t[2*v+1]);
    }
}

// updateRange(1,1,n,1,3,5); --> adds a[1..3] with 5
void updateRange(int v, int s, int e, int l, int r, LL val) {
    if (lazy[v] != 0){
        t[v] += lazy[v];
        if(s != e){
            lazy[2*v] += lazy[v];
            lazy[2*v+1] += lazy[v];
        }
        lazy[v] = 0;
    }
    if (s > e || s > r || l > e) {
        return;
    }
    if (l <= s && e <= r) {
        t[v] += val;
        if(s != e){
            lazy[2*v] += val;
            lazy[2*v+1] += val;
        }
        return;
    }
    int m = (s+e)/2;
    updateRange(2*v, s, m, l, r, val);
    updateRange(2*v+1, m+1, e, l, r, val);
    t[v] = min(t[2*v], t[2*v+1]);
}

// queryRange(1,1,n,1,3); --> find min between a[1..3]
LL queryRange(int v, int s, int e, int l, int r){
    if (s > e || s > r || l > e) {
        return INT_MAX;
    }
    if (lazy[v] != 0) {
        t[v] += lazy[v];
        if (s != e) {
            lazy[2*v] += lazy[v];
            lazy[2*v+1] += lazy[v];
        }
        lazy[v] = 0;
    }
    if (l <= s && e <= r) {
        return t[v];
    }
    int m = (s+e)/2;
    LL p1 = queryRange(2*v, s, m, l, r);
    LL p2 = queryRange(2*v+1, m+1, e, l, r);
    return min(p1, p2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    vector<ll> sumA(n + 1), prefD(n + 1), sufD(n + 2);
    prefD[0] = 1e18;
    sumA[0] = 0;
    for (int i = 1; i <= n; i++) {
        sumA[i] = a[i] + sumA[i - 1];
        prefD[i] = min(prefD[i - 1], d[i]);
    }
    

    sufD[n + 1] = 1e18;
    for (int i = n; i >= 1; i--) {
        sufD[i] = min(sufD[i + 1], d[i]);
    }

    if (k == 0) {
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, sumA[n] - sumA[i - 1] - d[i]);
        }
        cout << ans << '\n';
        exit(0);
    }

    // k >= 1
    if ((k-1) % 3 == 0) {
        ll ans3 = 0;
        if (k != 1) ans3 = sumA[n]-prefD[n-1];
        ll ans1 = max(0ll, a[n]-d[n]);
        ll ans2 = max(0ll, sumA[n-1] - prefD[n-1]);
        cout << max(ans1 + ans2, ans3) << endl;
    } else if ((k-1) % 3 == 1) {
        ll ans3 = sumA[n]-prefD[n-1];
        ll ans1 = max(0ll, a[n]-d[n]);
        ll ans2 = 0;
        for (int i=2;i<n;i++) {
            ans2 = max(ans2, max(0ll, sumA[i] - prefD[i]) + max(0ll, sumA[n-1]-sumA[i] - sufD[i]));
        }
        cout << max(ans1 + ans2, ans3) << endl;
        // mantap nanti anak UI nonton ini jadi tau itb toksik
        //daripada cf malem mending ngerjain tugas :kuliah: :D qaqa aku lolos CJ aku jadi heker
        // KAK TUBES IMK AKU GA ADA YANG NGERJAIN :(A(A(SD(ASD(AS(DA(SD(SA(D())))))))))
        // KAK TUBES IMK AKU GAK DIKERJAIN KOMUNIS KALASHNIKOV
    } else {
        ll ans3 = sumA[n]-prefD[n-1];
        // ans3 = 0;
        ll ans1 = max(0ll, a[n]-d[n]);
        ll ans2 = 0;
        build(1,1,n);
        for (int i=2;i<n;i++) {
            for (int j=i+1;j<=min(n,i+1);j++) {
                ans2 = max(ans2, max(0ll, sumA[i] - prefD[i]) + max(0ll, sumA[n-1]-sumA[j] - sufD[j]) + max (0ll, sumA[j-1]-sumA[i-1] - queryRange(1,1,n,i,j)));
            }
            // cout << sumA[i] << " " << prefD[i] << " " << sumA[n-1] << " " << sufD[i] << " " << ans2 <<  endl;
        }
        cout << max(ans1 + ans2, ans3) << endl;
    }
    
    return 0;
}
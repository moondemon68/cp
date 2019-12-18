#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define inf INT_MAX
#define MOD 1000000007
#define fori(i,n) for(int i=0;i<(int)n;++i)
#define forri(i,n) for(int i=n-1;i>=0;--i)
#define forii(i,start,end) for(int i=start;i<end;++i)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define sizearr(arr) sizeof(arr)/sizeof(arr[0])
#define LEN(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
#define reset(arr, val) fori(i, MAX) arr[i] = val;

#define print(var) cout << var << endl;
#define ENDL cout << endl;
#define coutarr(arr) for(auto a:arr)print(a); ENDL;
#define coutpii(arr) for(pii a:arr)cout << '(' << a.fi << ',' << a.se << ") "; ENDL;
#define cinvec(arr, n) fori(i, n) {int tmp; cin >> tmp; arr.pb(tmp);}
#define cinarr(arr, n) fori(i, n) {int tmp; cin >> tmp; arr[i]=tmp ;}

const int MAX = 1e5 + 5;

bool grid[105][105];

vector<int> parent;
vector<int> size_set;

int find_set(int v){
    if (parent[v] == v) return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(pii x, pii y){
	int u = x.fi*1000+x.se;
	int v = y.fi*1000+y.se;
    u = find_set(u);
    v = find_set(v);
    if (u != v){
        if (size_set[u] < size_set[v]){
            int tmpp; tmpp = u; u = v; v = tmpp;
        }
        parent[v] = u;
        size_set[u] += size_set[v] - 4;
    }
}

void activate(pii n){
	size_set[n.fi*1000+n.se] = 6;
}

bool isActivated(pii n){
	return size_set[n.fi*1000+n.se] != 0;
}

void init_ds(int n){
    for (int i = 0; i < n+1; i++){
        parent.push_back(i);
        size_set.push_back(0);
    }
}


int main(){
	int n, m; cin >> n >> m;
	init_ds(100105);
	fori(i, n){
		if(i%2){
			fori(j, m-1){
				int tmp; cin >> tmp;
				grid[i][j] = tmp==1;
				activate(mp(i,j));
				vector<pii> neigh;
    			forii(k, -1, 2){
    				forii(l, -1, 2){
    					if(k == -1 && l == -1) continue;
    					if(k == 1 && l == 1) continue;
    					if(0 <= i-k && i-k < n){
    						if(0 <= j-l && j-l < m){
    							neigh.pb(mp(i-k, j-l));
    						}
    					}
    				}
    			}
    			for(pii n: neigh){
					if(find_set(i*1000+j) != find_set(n.fi*1000+n.se) and isActivated(n)){
						union_set(mp(i,j), n);
					}
				}
			}
		} else {
			fori(j, m){
				int tmp; cin >> tmp;
				grid[i][j] = tmp==1;
				activate(mp(i,j));
				vector<pii> neigh;
    			forii(k, -1, 2){
    				forii(l, -1, 2){
    					if(k == -1 && l == -1) continue;
    					if(k == 1 && l == 1) continue;
    					if(0 <= i-k && i-k < n){
    						if(0 <= j-l && j-l < m){
    							neigh.pb(mp(i-k, j-l));
    						}
    					}
    				}
    			}
    			for(pii n: neigh){
					if(find_set(i*1000+j) != find_set(n.fi*1000+n.se) and isActivated(n)){
						union_set(mp(i,j), n);
					}
				}
			}
		}
	}

	fori(i, n){
		fori(j, m){
			if (grid[i][j]){
				cout << i << " " << j << " " << size_set[find_set(i*1000+j)] << endl;
			}
		}
	}
	
	int q; cin >> q;
	fori(i, q){
		char x; int r, c; cin >> x >> r >> c;
		if (x == 'a'){
			vector<pii> neigh;
			forii(i, -1, 2){
				forii(j, -1, 2){
					if(i == -1 && j == -1) continue;
					if(i == 1 && j == 1) continue;
					if(0 <= r-i && r-i < n){
						if(0 <= c-j && c-j < m){
							neigh.pb(mp(r-i, c-j));
						}
					}
				}
			}
			activate(mp(r,c));
			for(pii n: neigh){
				if(find_set(r*1000+c) != find_set(n.fi*1000+n.se) and isActivated(n)){
					union_set(mp(r,c), n);
				}
			}
		} else {
			cout << size_set[find_set(r*1000+c)] << endl;
		}
	}
	
	return 0;	
}
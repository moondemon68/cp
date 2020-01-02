#include <bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define ALL(v) v.begin(),v.end()
#define RALL(v) v.rbegin(),v.rend()
#define ss second
#define ff first
	
using namespace std;
	
const int MAXN = 1e5+5;
int a[MAXN];
int n;
	
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int tc; 
	cin >> tc;
	while(tc--){
		int last[35];
		map<int,int> m;
		cin >> n;
		for(int i=0; i<32; i++){
			last[i]=0;
		}
	
		vector<pii> pos;
		for(int i=1; i<=n; i++){
			pos.clear();
			cin >> a[i];
			m[a[i]]++;
			for(int j=0; j<32; j++){
				if(a[i]&(1<<j)){
					last[j]=i;
				} else {
					if(last[j]!=0){
						pos.pb({last[j],j});
					}	
				}
			}
			if(!pos.empty()){
				sort(RALL(pos));
				int cur = a[i];
				for(int j=0; j<(int)pos.size(); j++){
					if(j>0 && pos[j].ff!=pos[j-1].ff){
						m[cur]++;
					} 
					cur |= (1<<pos[j].ss);
				}
				m[cur]++;
			}
		}
	
		int ans = 0;
		for(auto i : m){
			ans++;
		}
		cout << ans << "\n";
	
	}
}
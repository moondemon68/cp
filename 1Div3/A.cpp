#include <bits/stdc++.h>
#define f first
#define sf second.first
#define ss second.second

using namespace std;

int main () {
	int n;
	cin >> n;
	int b[100000];
	for (int i=1;i<=n;i++) cin >> b[i];
	vector< pair<int, pair<int,int> > > a;
	int cnt[8];
	memset (cnt,0,sizeof(cnt));
	for (int i=1;i<=n;i++) {
		cnt[b[i]]++;
	}
	while (cnt[1]>0&&cnt[2]>0&&cnt[4]>0) {
		cnt[1]--;
		cnt[2]--;
		cnt[4]--;
		n-=3;
		a.push_back(make_pair(1,make_pair(2,4)));
	}
	while (cnt[1]>0&&cnt[2]>0&&cnt[6]>0) {
		cnt[1]--;
		cnt[2]--;
		cnt[6]--;
		n-=3;
		a.push_back(make_pair(1,make_pair(2,6)));
	}
	while (cnt[1]>0&&cnt[3]>0&&cnt[6]>0) {
		cnt[1]--;
		cnt[3]--;
		cnt[6]--;
		n-=3;
		a.push_back(make_pair(1,make_pair(3,6)));
	}
	if (n>0) {
		cout << -1 << endl;
	} else {
		for (int i=0;i<a.size();i++) {
			cout << a[i].f << " " << a[i].sf << " " << a[i].ss << endl;
		}
	}
	return 0;
}

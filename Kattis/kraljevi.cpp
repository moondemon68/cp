#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

int main () {
	int r,c;
	cin >> r >> c;
	vector< pair<int,int> > a,b;
	for (int i=1;i<=r;i++) {
		string s;
		cin >> s;
		for (int j=1;j<=c;j++) {
			if (s[j-1]=='S') b.push_back(make_pair(i,j)); else a.push_back(make_pair(i,j));
		}
	}
	int ans=0;
	for (int i=0;i<a.size();i++) {
		for (int j=i+1;j<a.size();j++) {
			//int minj=min(a[j].x,a[j].y);
			//int mini=min(a[i].x,a[i].y);
			cout << a[j].x << " " << a[j].y << " " << a[i].x << " " << a[i].y << endl;
			int dif=a[j].x-a[i].x;
			int newx=dif+a[i].x,newy=a[i].y+dif;
			cout << a[j].x << " " << a[j].y << " " << newx << " " << newy << " ";
 			ans+=(a[j].y-newy);
			cout << ans << endl;
		}
	}
	cout << ans << endl;
	return 0;
}

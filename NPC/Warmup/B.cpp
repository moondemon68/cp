#include <bits/stdc++.h>

using namespace std;

int main () {
	int x,y,p;
	cin >> y >> x >> p;
	string s;
	for (int i=1;i<=x*(p+1);i++) {
		if (i%(p+1)==1) s+='+'; else s+='-';
	}
	s+='+';
	string t;
	for (int i=1;i<=y*(p+1);i++) {
		if (i%(p+1)==1) t+='+'; else t+='|';
	}
	t+='+';
	char a[50][50];
	memset (a,' ',sizeof(a));
	for (int i=0;i<t.size();i++) {
		if (i%(p+1)==0) {
			for (int r=0;r<s.size();r++) {
				a[i][r]=s[r];
			}
		}
	}
	for (int i=0;i<s.size();i++) {
		if (i%(p+1)==0) {
			for (int r=0;r<t.size();r++) {
				a[r][i]=t[r];
			}
		}
	}
	if (p%2==0) {
		for (int i=0;i<t.size();i++) {
			for (int j=0;j<s.size();j++) {
				if (i%(p+1)!=0&&j%(p+1)!=0) {
					int b=i%(p+1),c=j%(p+1);
					if (b==c) a[i][j]=char(92);
					if (b+c==(p+1)) a[i][j]='/';
				}
			}
		}
	} else {
		for (int i=0;i<t.size();i++) {
			for (int j=0;j<s.size();j++) {
				if (i%(p+1)!=0&&j%(p+1)!=0) {
					int b=i%(p+1),c=j%(p+1);
					if (b==c) {
						a[i][j]=char(92);
						if (b==((p+1)/2)) a[i][j]='x';
					}
					if (b+c==(p+1)&&a[i][j]==' ') a[i][j]='/';
				}
			}
		}
	}
	
	for (int i=0;i<t.size();i++) {
		for (int j=0;j<s.size();j++) {
			cout << a[i][j];
		}
		cout << endl;
	}
}

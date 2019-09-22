#include<iostream>
#include<cstdlib>
#include<cstring>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const long long inf=1e18;
int n,a[110000],b[110000],st[110000],en[110000],list[110000],cnt_list,ch[110000],pa[110000],queue[110000],temp1,temp2,temp,vis[110000],times;
long long dp[110000];
vector<int>adj[110000];
void dfs(int id,int pr)
{
	int i,j,s,p,q,ip;
	st[id]=cnt_list;
	list[cnt_list++]=id;
	pa[id]=pr;
	for(i=0;i<adj[id].size();i++)
	{
		ip=adj[id][i];
		if(ip==pr)
		   continue;
        dfs(ip,id);
	}
	en[id]=cnt_list-1;
}
void bfs(int id,int ie)
{
	int deep=0,i,j;
	queue[0]=ie;
	temp1=temp2=0;
	temp=1;
	vis[ie]=times;
	while(temp1<=temp2)
	{
		deep++;
		if(deep>200)
		   return;
        for(i=temp1;i<=temp2;i++)
        {
        	ie=queue[i];
        	if(dp[id]>dp[ie]+1LL*a[id]*b[ie])
        	{
	        	dp[id]=dp[ie]+1LL*a[id]*b[ie];
	        	ch[id]=st[ie];
	        }
	        for(j=0;j<adj[ie].size();j++)
	        {
     		    if(adj[ie][j]==id||vis[adj[ie][j]]==times)
     		        continue;
	            vis[adj[ie][j]]=times;
   		        queue[temp++]=adj[ie][j];
        	}
        }
        temp1=temp2+1;
        temp2=temp-1;
	}
}
int main()
{
	scanf("%d",&n);
	int i,j,s,p,q;
	for(i=0;i<n;i++)
	   scanf("%d",&a[i]);
    for(i=0;i<n;i++)
       scanf("%d",&b[i]);
    int u,v;
    for(i=0;i<n;i++)
       adj[i].clear();
    for(i=0;i<n-1;i++)
    {
    	scanf("%d%d",&u,&v);
    	u--;
    	v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    cnt_list=0;
    dfs(0,-1);
    for(i=0;i<n;i++)
    {
    	dp[i]=inf;
        if(i&&adj[i].size()==1)
        {
           dp[i]=0;
           ch[i]=st[i];
        }
	}
	for(i=cnt_list-1;i>=0;i--)
    { 
    	if(dp[list[i]]==inf)
    	{
    		int id=list[i];
	    	for(j=0;j<adj[id].size();j++)
	    	{
	    		int ip=adj[id][j];
	    		if(st[ip]<st[id])
	    		   continue;
  		        times++;
	            bfs(id,list[ch[ip]]);
	    	}
	    }
    }
    for(i=0;i<n;i++)
    {
    	if(i)
    	   putchar(' ');
 	    printf("%lld",dp[i]);
    }
    printf("\n");
}
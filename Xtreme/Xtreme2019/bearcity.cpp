    #include <bits/stdc++.h>
     
    using namespace std;
     
    const int maxn = 200010;
    int fa[maxn],n,m,head[maxn],to[maxn],nextt[maxn],w[maxn],ans[maxn];
    int pre[maxn],tot = 1,low[maxn],dfs_clock;
     
    struct node
    {
        int x,y,z,id;
    }e[maxn];
     
    bool cmp(node a,node b)
    {
        return a.z < b.z;
    }
     
    int find(int x)
    {
        if (x == fa[x])
            return x;
        return fa[x] = find(fa[x]);
    }
     
    void add(int x,int y,int z)
    {
        w[++tot] = z;
        to[tot] = y;
        nextt[tot] = head[x];
        head[x] = tot;
    }
     
    void tarjan(int u,int last)
    {
        pre[u] = low[u] = ++dfs_clock;
        for (int i = head[u];i;i = nextt[i])
        {
            if (i == last)
                continue;
            int v = to[i];
            if (!pre[v])
            {
                tarjan(v,(i ^ 1));
                low[u] = min(low[u],low[v]);
                if (low[v] > pre[u])
                    ans[w[i]] = 0;
            }
            else
                low[u] = min(low[u],pre[v]);
        }
    }
     
    void solve()
    {
        int last = 1;
        for (int i = 1; i <= m; i = last + 1)
        {
            while (last + 1 <= m && e[last + 1].z == e[i].z)
                last++;
            tot = 1;
            dfs_clock = 0;
            for (int j = i; j <= last; j++)
            {
                int x = find(e[j].x),y = find(e[j].y);
                if (x == y) //这条边一定不会在MST中!
                    ans[e[j].id] = 2;
                else
                {
                    ans[e[j].id] = 1;  //一定在MST
                    head[x] = head[y] = 0;  //可能用到的点
                    pre[x] = pre[y] = low[x] = low[y] = 0;
                }
            }
            for (int j = i; j <= last; j++)
            {
                int x = find(e[j].x),y = find(e[j].y);
                if (x == y)
                    continue;
                else
                {
                    add(x,y,e[j].id);
                    add(y,x,e[j].id);
                }
            }
            for (int j = i; j <= last; j++)
            {
                int temp = find(e[j].x);
                if (!pre[temp])
                    tarjan(temp,0);
            }
            for (int j = i; j <= last; j++)
            {
                int x = find(e[j].x),y = find(e[j].y);
                if (x != y)
                    fa[x] = y;
            }
        }
    }
     
    int main()
    {
        scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
            e[i].id = i;
        }
        sort(e + 1,e + 1 + m,cmp);
        solve();
        int cnt=0;
        for (int i = 1; i <= m; i++)
        {
            if (ans[i]==0) cnt++;
        }
        cout << cnt << endl;
     
        return 0;
    }
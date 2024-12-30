#include <bits/stdc++.h>
using namespace std;
int pos[100005];
vector<int> v[100005],col[100005],s;
vector<int> cyc;
bool dfs(int node)
{
    pos[node]=s.size();
    col[pos[node]%2].push_back(node);
    s.push_back(node);
    int low=-1;
    for (int u:v[node])
    {
        if (pos[u]!=-1 && pos[node]-pos[u]>1)
        low=max(low,pos[u]);
    }
    if (low!=-1)
    {
        for (int i=low;i<=pos[node];i++)
        cyc.push_back(s[i]);
        return 1;
    }
    for (int u:v[node])
    {
        if (pos[u]==-1)
        {
            if (dfs(u))
            return 1;
        }
    }
    s.pop_back();
    return 0;
}
int main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define endl '\n'
#endif
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    while (m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(pos,-1,sizeof(pos));
    dfs(1);
    if (cyc.empty())
    {
        if (col[0].size()<col[1].size())
        swap(col[0],col[1]);
        printf("1\n");
        for (int i=0;i<(k+1)/2;i++)
        printf("%d ",col[0][i]);
    }
    else
    {
        if (cyc.size()<=k)
        {
            printf("2\n%d\n",cyc.size());
            for (int i:cyc)
            printf("%d ",i);
        }
        else
        {
            printf("1\n");
            for (int i=0;i<(k+1)/2;i++)
            printf("%d ",cyc[2*i]);
        }
    }
}
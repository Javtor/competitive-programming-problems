
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+6;
const int inf = 1e9+1e7;
vector<pair<int,int> > E[maxn];
int n,k,l;
int vis[maxn],use[maxn],dis[maxn],color[maxn];
vector<int> st;
int main(){
    scanf("%d%d%d",&n,&k,&l);
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        st.push_back(x);
    }
    for(int i=1;i<=l;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        E[a].push_back(make_pair(b,c));
        E[b].push_back(make_pair(a,c));
    }
    int ans = inf;
    for(int i=1;i<=k;i++){
        dis[i]=inf;
        vis[i]=-1;
    }
    set<pair<int,int> >S;
    for(int i=0;i<st.size();i++){
        dis[st[i]]=0;
        color[st[i]]=i;
        S.insert(make_pair(0,st[i]));
        if(use[st[i]]){
            ans=0;
        }
        use[st[i]]=1;
    }
    while(!S.empty()){
        int now = S.begin()->second;
        S.erase(S.begin());
        for(int i=0;i<E[now].size();i++){
            int x = E[now][i].first;
            int v = E[now][i].second;
            if(color[x]!=color[now]&&color[x]!=-1)
                ans=min(ans,v+dis[x]+dis[now]);
            if(dis[x]>dis[now]+v){
                S.erase(make_pair(dis[x],x));
                dis[x]=dis[now]+v;
                color[x]=color[now];
                S.insert(make_pair(dis[x],x));
            }
        }
    }
    cout<<ans*3<<endl;
}
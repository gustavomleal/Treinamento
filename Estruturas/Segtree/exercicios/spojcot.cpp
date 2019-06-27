#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sd second 
#define ft first
const int N=100100;
typedef struct node{
	int l,r,at;
	int  value;
	node(){}	
	node(int a,int b,int c,int d):l(a),r(b),value(c),at(d){}


}Node;
Node NUL=Node(0,0,0,0);

Node merg(Node a,Node b,int x){
	Node rs;
	rs.l=a.at;
	rs.r=b.at;
	rs.at=x;
	rs.value=a.value+b.value;

	return rs;
}


int k=1,t=0;
map<ll,int> mp,rmp;
int head[N],a[4*N],peso[N],pai[N];
Node tree[80*N];
vector<int> lista[N];
vector<int> mapea;
pair<pair<int,int> , int> que[N];

void build(int p,int l,int r){
	if(l==r)
		tree[p]=Node(-1,-1,a[l],p);
	else{
		int mid=(l+r)/2;
		build(2*p,l,mid);
		build(2*p+1,mid+1,r);
		tree[p]=merg(tree[2*p],tree[2*p+1],p);
	}
	k=max(p,k);
}

Node query(int p,int l,int r,int tl,int tr){
	if(l>r)
		return NUL;
	if(tl==l && tr==r){
		// cout<<l<<" "<<r<<" "<<tree[p].at<<"\n";
		return tree[p];
	}
	int mid=(tl+tr)/2;
	return merg(query(tree[p].l,l,min(r,mid),tl,mid),
		query(tree[p].r,max(l,mid+1),r,mid+1,tr),0);
}

int walk(int u,int v,int lc,int plc,int d,int tl,int tr){
	if(tl==tr)
		return tl;
	int at=0;
	int mid=(tl+tr)/2;
	at+=tree[tree[u].l].value;
	at+=tree[tree[v].l].value;
	at-=tree[tree[lc].l].value;
	at-=tree[tree[plc].l].value;
	// cout<<at<<" "<<tl<<" "<<tr<<"\n";
	if(at>=d)
		return walk(tree[u].l,tree[v].l,tree[lc].l,tree[plc].l,d,tl,mid);
	if(at<d)
		return walk(tree[u].r,tree[v].r,tree[lc].r,tree[plc].r,d-at,mid+1,tr);
}

void update(int olp,int p,int tl,int tr,int atp){
	if(tl==tr){
		tree[p]=tree[olp];
		tree[p].value++;
		tree[p].at=p;
		// cout<<tree[p].at<<"fim\n";
		k++;
	}else{
		int mid=(tl+tr)/2;
		if(mid>=atp){
			update(tree[olp].l,p+1,tl,mid,atp);
			tree[p]=merg(tree[p+1],tree[tree[olp].r],p);
		}else{
			update(tree[olp].r,p+1,mid+1,tr,atp);
			tree[p]=merg(tree[tree[olp].l],tree[p+1],p);
		}
		k++;
	}
}

int n, l;


int timer;
vector<int> tin, tout;
vector< vector<int> > up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int i = 0; i < lista[v].size(); ++i)
	{
		int u=lista[v][i];
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n+1);
    tout.resize(n+1);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n+1, vector<int>(l + 1));
    dfs(root, root);
}

void dfs1(int u,int p){
	for (int i = 0; i < lista[u].size(); ++i)
	{
		int v=lista[u][i];
		if(v!=p){
			pai[v]=u;
			head[v]=k;
			// cout<<mp[peso[v]]<<"comeco\n";
			update(head[u],head[v],1,t,mp[peso[v]]);
			// cout<<tree[head[v]].l<<" "<<tree[head[v]].r<<"\n";
			dfs1(v,u);

		}
	}
}





int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	head[1]=1;
	int x,y,q;
	cin>>n>>q;
	for (int i = 0; i < n; ++i)
	{
		cin>>peso[i+1];
		mapea.push_back(peso[i+1]);
	}
	for (int i = 0; i < n-1; ++i)
	{
		cin>>x>>y;
		lista[x].push_back(y);
		lista[y].push_back(x);
	}
	for (int i = 0; i < q; ++i)
	{
		cin>>que[i].ft.ft>>que[i].ft.sd>>que[i].sd;
	}
	t=1;
	sort(mapea.begin(),mapea.end());
	for(int c=0;c<mapea.size();c++){
		mp[mapea[c]]=t;
		rmp[t]=mapea[c];
		t++;
	}
	lista[0].push_back(1);
	lista[1].push_back(0);
	preprocess(0);
	// a[ mp[ peso[1] ] ]=1;
	build(1,1,t);
	k++;
	dfs1(0,0);
	// cout<<head[2]<<" "<<t<<" "<<mp[peso[2]]<<"\n";
	// cout<<query(head[3],1,t,1,t).value<<"\n";
	for (int h = 0; h < q; ++h)
	{
		int l,r,mid,x,ans=-1;
		int lim=que[h].sd;
		int u=que[h].ft.ft,v=que[h].ft.sd;
		x=lca(u,v);
		cout<<rmp[walk(head[u],head[v],head[x],head[pai[x]],lim,1,t)]<<"\n";
		// cout<<u<<" "<<v<<" "<<x<<"\n";
		// l=1,r=t-1;
		// // cout<<lim<<" limite\n";
		// while(l<r){
		// 	mid=(l+r)/2;
		// 	int rsp=0;
		// 	rsp=query(head[u],1,mid,1,t).value+query(head[v],1,mid,1,t).value-2*query(head[x],1,mid,1,t).value;
		// 	if(mid>=mp[peso[x]])
		// 		rsp++;
		// 	if(rsp<lim){
		// 		l=mid+1;
		// 	}else{
		// 		r=mid;
		// 	}
		// 	// cout<<l<<" "<<r<<" "<<mid<<" "<<rsp<<"\n";
		// 	// cout<<mid<<" "<<rsp<<"\n";
			
		// 	// cout<<l<<" "<<r<<"\n";		
		// }
		// // ans++;
		// cout<<rmp[r]<<"\n";
	}

	return 0;
}
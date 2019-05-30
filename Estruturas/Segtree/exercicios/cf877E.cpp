#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lef(x) (x<<1)
#define rig(x) lef(x) + 1
#define sd second
#define ft first
const int N=200100;
vector<int> euler,lista[N];
int visited[N],lazy[16*N];
pair<int,int> tree[16*N],b[N],a[4*N],ori[N];
pair<int, int> operator +(const pair<int, int>& x, const pair<int, int>& y) {
    return make_pair(x.first + y.first, x.second + y.second);
}
void dfs(int p){
	visited[p]=1;
	euler.push_back(p);
	for (int i = 0; i < lista[p].size(); ++i)
	{
		int u=lista[p][i];
		if(!visited[u])
			dfs(u);
	}
	euler.push_back(p);
}
void build(int p,int l,int r){
	if(l==r)
		tree[p]=a[l];
	else{
		int mid=(l+r)/2;
		build(lef(p),l,mid);
		build(rig(p),mid+1,r);
		tree[p]=tree[lef(p)]+tree[rig(p)];
	}
}

void push(int p){
	if(lazy[p]){
		swap(tree[lef(p)].ft,tree[lef(p)].sd);
		swap(tree[rig(p)].ft,tree[rig(p)].sd);
		lazy[lef(p)]=!lazy[lef(p)];
		lazy[rig(p)]=!lazy[rig(p)];
		lazy[p]=0;	
	}
}

void update(int p,int l,int r,int tl,int tr){
	if(l>r)
		return ;
	push(p);
	if(tl==l && tr==r){

		// cout<<l<<" "<<r<<"\n";
		swap(tree[p].ft,tree[p].sd);
		lazy[p]=1;
	}else{
		
		int mid=(tl+tr)/2;
		update(lef(p),l,min(r,mid),tl,mid);
		update(rig(p),max(l,mid+1),r,mid+1,tr);
		tree[p]=tree[lef(p)]+tree[rig(p)];
	}
}


pair<int,int> query(int p,int l,int r,int tl,int tr){
	if(l>r)
		return {0,0};
	push(p);
	if(tl==l && tr==r){
		return tree[p];
	}else{
		int mid=(tl+tr)/2;
		return query(lef(p),l,min(r,mid),tl,mid) +
			query(rig(p),max(l,mid+1),r,mid+1,tr);
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x,q;
	string s;
	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>x;
		lista[x].push_back(i+2);
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x){
			b[i].ft=1;
		}else
			b[i].sd=1;
	}
	dfs(1);
	for (int i = 0; i <(int)euler.size() ; ++i)
	{
		if(ori[euler[i]].ft==0)
			ori[euler[i]].ft=i+1;
		else
			ori[euler[i]].sd=i+1;
	}
	for (int i = 0; i <(int)euler.size() ; ++i)
	{
		a[ori[euler[i]].ft]=b[euler[i]];
		a[ori[euler[i]].sd]=b[euler[i]];
	}
	build(1,1,n*2);
	cin>>q;
	while(q--){
		cin>>s>>x;
		if(s[0]=='g'){
			cout<<query(1,ori[x].ft,ori[x].sd,1,n*2).ft/2<<"\n";
		}else{
			// cout<<ori[x].ft<<" "<<ori[x].sd<<" "<<1<<" "<<n*2<<"\n";
			update(1,ori[x].ft,ori[x].sd,1,n*2);
		}
	}

}
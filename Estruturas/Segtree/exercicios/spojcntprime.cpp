#include<bits/stdc++.h>
using namespace std;
#define rig(x) ((x<<1))+1
#define lef(x) ((x<<1))
#define ll long long
const int N=10100;
const int M=1000100;
ll tree[4*N];
ll lazy[4*N];
ll isp[M];
ll a[N];
void sieve(){

	for (int i = 2; i < M; ++i)
		isp[i]=1;
	for (int i = 2; i < M; ++i)
	{
		if(isp[i]==1LL){
			for (int j = i+i; j < M; j+=i)
			{
				isp[j]=0;
			}
		}
	}
}




void push(ll p,ll l,ll r){
		if(lazy[p]==-1LL)
			return;
		ll mid=(r+l)/2LL;
		lazy[lef(p)]=lazy[p];
		lazy[rig(p)]=lazy[p];
		tree[lef(p)]=max((mid-l+1LL),1LL)*(lazy[p]);
		tree[rig(p)]=max((r-mid),1LL)*(lazy[p]);
		lazy[p]=-1LL;
	
}

void build(ll p,ll tl,ll tr){
	if(tl==tr){
		// cout<<tl<<" "<<a[tl]<<"\n";
		tree[p]=a[tl];
	}
	else{
		ll mid=(tl+tr)/2;
		build(lef(p),tl,mid);
		build(rig(p),mid+1,tr);

		tree[p]=tree[lef(p)]+tree[rig(p)];
		// cout<<tl<<" "<<tr<<" "<<tree[p]<<"\n";
	}
}


void update(ll p,ll l,ll r,ll x,ll tl,ll tr){
	if(l>r)
		return;
	if(l==tl && r==tr){
		lazy[p]=x;
		tree[p]=(tr-tl+1LL)*(x);
	}else{
		push(p,tl,tr);
		ll mid=(tl+tr)/2;
		update(lef(p),l,min(r,mid),x,tl,mid);
		update(rig(p),max(l,mid+1LL),r,x,mid+1LL,tr);
		tree[p]=tree[lef(p)]+tree[rig(p)];
	}
}

ll query(ll p,ll l,ll r,ll tl,ll tr){
	if(l>r)
		return 0LL;
	if(l<=tl && r>=tr){
		// cout<<tl<<" "<<tr<<" "<<tree[p]<<"\n";
		return tree[p];
	}
	push(p,tl,tr);
	ll mid=(tl+tr)/2LL;

	return query(lef(p),l,min(r,mid),tl,mid)+
		query(rig(p),max(l,mid+1LL),r,mid+1LL,tr);
}







int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	sieve();
	ll t,n,q,tipo,l,r;
	ll x;
	cin>>t;
	int k=1;
	while(t--){
		cin>>n>>q;
		cout<<"Case "<<k++<<":\n";
		for (int i = 1; i <= n; ++i)
		{
			cin>>a[i];
			// cout<<a[i]<<" "<<isp[a[i]]<<"\n";
			a[i]=isp[a[i]];
		}
		for (int i = 0; i < 4*N; ++i)
		{
			tree[i]=0LL;
			lazy[i]=-1LL;
		}
		build(1,1,n);
		while(q--){
			cin>>tipo;
			if(!tipo){
				cin>>l>>r>>x;
				
				update(1,l,r,isp[x],1,n);
			}else{
				cin>>l>>r;
				
				cout<<query(1LL,l,r,1LL,n)<<"\n";
			}
		}
	}



	return 0;
}
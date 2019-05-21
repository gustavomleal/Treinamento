#include<bits/stdc++.h>
using namespace std;
#define rig(x) ((x<<1))+1
#define lef(x) ((x<<1))
#define ll long long
const int N=100100;
ll tree[4*N];
ll lazy[4*N];

void push(ll p,ll l,ll r){
		ll mid=(r+l)/2LL;
		lazy[lef(p)]+=lazy[p];
		lazy[rig(p)]+=lazy[p];
		tree[lef(p)]+=max((mid-l+1LL),1LL)*lazy[p];
		tree[rig(p)]+=max((r-mid),1LL)*lazy[p];
		lazy[p]=0LL;
	
}




void update(ll p,ll l,ll r,ll x,ll tl,ll tr){
	if(l>r)
		return;
	if(l==tl && r==tr){
		lazy[p]+=x;
		tree[p]+=(ll)(tr-tl+1LL)*x;
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
	ll t,n,q,tipo,l,r;
	ll x;
	cin>>t;
	while(t--){
		cin>>n>>q;
		for (int i = 0; i < 4*N; ++i)
		{
			tree[i]=lazy[i]=0LL;
		}
		while(q--){
			cin>>tipo;
			if(!tipo){
				cin>>l>>r>>x;
				assert(x>0);
				assert(l<=n);
				assert(r<=n);
				update(1,l,r,x,1,n+1);
			}else{
				cin>>l>>r;
				assert(l<=n);
				assert(r<=n);
				cout<<query(1LL,l,r,1LL,n+1LL)<<"\n";
			}
		}
	}



	return 0;
}
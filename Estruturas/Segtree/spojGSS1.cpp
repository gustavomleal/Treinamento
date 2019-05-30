#include<bits/stdc++.h>
using namespace std;
#define lef(x) (x<<1)
#define rig(x) (lef(x) + 1)
#define ll long long
const int N=50010;
typedef struct dado{
	ll l,r,m,sum;
	dado(){}
	dado(ll x):l(x),r(x),m(x),sum(x){}

	// dado operator +(struct dado const &y){
	// 	dado x;
	// 	x.sum=sum+y.sum;
	// 	x.m=max({m,y.m,r+y.l});
	// 	x.r=max(y.r,sum+y.r);
	// 	x.l=max(l,l+y.sum);
	// 	return x;
	// }
}Dado;

ll a[N];

Dado tree[4*N];

dado f(dado x,dado y){
	dado re;
	re.sum=x.sum+y.sum;
	re.m=max({x.m,y.m,x.r+y.l});
	re.r=max(y.r,y.sum+x.r);
	re.l=max(x.l,x.sum+y.l);
	return re;
}


void build(int p,int l,int r){
	if(l==r){
		tree[p]=dado(a[l]);
	}else{
		int mid=(l+r)/2;
		build(lef(p),l,mid);
		build(rig(p),mid+1,r);
		tree[p]=f(tree[lef(p)],tree[rig(p)]);
	}
}

Dado query(int p,int l,int r,int tl,int tr){
	if(l>r)
		return dado(-1000000000000000LL);
	if(tl==l && tr==r){
		return tree[p];
	}
	int mid=(tl+tr)/2;

	return f(query(lef(p),l,min(r,mid),tl,mid),
		query(rig(p),max(mid+1,l),r,mid+1,tr));
}

void update(int p,int tl,int tr,int k,int x){
	if(tl==tr){
		tree[p]=dado(x);
	}else{
			
		int mid=(tl+tr)/2;
		if(mid<k)
			update(rig(p),mid+1,tr,k,x);
		else
			update(lef(p),tl,mid,k,x);

		tree[p]=f(tree[lef(p)],tree[rig(p)]);	
	}
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i+1];
	build(1,1,n);
	int q,x,y,u;
	cin>>q;
	while(q--){
		cin>>u>>x>>y;
		if(u==1)
			cout<<query(1,x,y,1,n).m<<endl;
		else
			update(1,1,n,x,y);

	}

	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lef(x) (x<<1)
#define rig(x) lef(x) + 1
const int N=1000100;

typedef struct dado{
	int q,s,qs,sq;
	dado():q(0),s(0),sq(0),qs(0){}
	dado(int x):q(x==1),s(x==0),sq(1),qs(1){}
}Dado;

Dado f(Dado x,Dado y){
		Dado r;
		r.qs=max({x.qs+y.s,x.q+y.qs,x.q+y.s});
		r.sq=max({x.s+y.sq,x.sq+y.q,x.s+y.q});
		r.q=x.q+y.q;
		r.s=x.s+y.s;
		return r;			
}
void suap(Dado &x){
		swap(x.qs,x.sq);
		swap(x.q,x.s);
}


Dado tree[4*N],a[N];
int lazy[4*N];

void push(int p,int l,int r){
	if(lazy[p]){
		int mid=(l+r)/2;
		suap(tree[lef(p)]);
		suap(tree[rig(p)]);

		if(l!=mid)lazy[lef(p)]^=1;
		mid++;
		if(mid!=r)lazy[rig(p)]^=1;
		lazy[p]=0;
	}
}



void build(int p,int tl,int tr){
	if(tl==tr)
		tree[p]=a[tl];
	else{
		int mid=(tl+tr)/2;
		build(lef(p),tl,mid);
		build(rig(p),mid+1,tr);
		tree[p]=f(tree[lef(p)],tree[rig(p)]);
		// cout<<tl<<" "<<tr<<" "<<tree[p].qs<<" "<<tree[p].sq<<" "<<tree[p].q<<" "<<tree[p].s<<"\n";
	}
}



void update(int p,int l,int r,int tl,int tr){
	if(l>r)
		return;
	push(p,tl,tr);
	if(tl==l && tr==r){
		suap(tree[p]);
		if(tl!=tr)lazy[p]=1;
	}else{
		int mid=(tl+tr)/2;
		update(lef(p),l,min(mid,r),tl,mid);
		update(rig(p),max(mid+1,l),r,mid+1,tr);
		tree[p]=f(tree[lef(p)],tree[rig(p)]);
	}
	
}

Dado query(int p,int l,int r,int tl,int tr){
	if(l>r)
		return dado();
	push(p,tl,tr);
	if(tl==l && tr==r)
		return tree[p];
	int mid=(tl+tr)/2;
	return f(query(lef(p),l,min(mid,r),tl,mid),query(rig(p),max(l,mid+1),r,mid+1,tr));
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	string s;
	cin>>n>>q;
	cin>>s;
	for (int i = 0; i < n; ++i)
	{
		a[i+1]=dado((s[i]=='4'?1:0));
		// cout<<((s[i]=='4')?1:0)<<endl;
	}
	build(1,1,n);
	// cout<<tree[1].qs<<"\n";
	while(q--){
		cin>>s;
		int l,r;
		if(s[0]=='c'){
			cout<<query(1,1,n,1,n).qs<<"\n";
		}else{
			cin>>l>>r;
			update(1,l,r,1,n);
		}
	}
	return 0;
}

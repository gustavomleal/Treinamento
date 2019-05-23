#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lef(x) (x<<1)
#define rig(x) lef(x) + 1
#define sd second
#define ft first
const int N=500100;
class Dado{
public:
	int val;

	Dado(){

	}
	Dado(int x){
		val=x;
	}
};

Dado Merg(Dado a,Dado b){
	Dado x;

	x.val=__gcd(a.val,b.val);
	return x;
}

Dado tree[4*N];
int a[N];

void build(int p,int tl,int tr){
	if(tl==tr)
		tree[p]=Dado(a[tl]);
	else{
		int mid=(tl+tr)/2;
		build(lef(p),tl,mid);
		build(rig(p),mid+1,tr);
		tree[p]=Merg(tree[lef(p)],tree[rig(p)]);
	}
}


void update(int p,int x,int tl,int tr,int pos){
	if(tl==tr){
		tree[p]=Dado(x);
		return;
	}
	int mid=(tl+tr)/2;
	if(mid>=pos)
		update(lef(p),x,tl,mid,pos);
	else
		update(rig(p),x,mid+1,tr,pos);
	tree[p]=Merg(tree[lef(p)],tree[rig(p)]);
}


Dado query(int p,int l,int r,int tl,int tr){
	if(l>r)
		return Dado(0);
	if(tl==l && tr==r)
		return tree[p];

	int mid=(tl+tr)/2;
	return Merg(query(lef(p),l,min(mid,r),tl,mid),
		query(rig(p), max(l,mid+1),r,mid+1,tr));
}

int walk(int p,int x,int l,int r,int tl,int tr){
	if(l>r)
		return 0;
	if(tl==l && tr==r){
		if(tree[p].val%x==0)
			return 0;
		else{
			if(!(tr-tl))
				return 1;
			int mid=(tl+tr)/2,ans=0;
			if(tree[lef(p)].val%x!=0 && tree[rig(p)].val%x!=0)
				return 2;
			if(tree[lef(p)].val%x!=0)
				ans+=walk(lef(p),x,l,min(mid,r),tl,mid);
			if(tree[rig(p)].val%x!=0)
				ans+= walk(rig(p),x, max(l,mid+1),r,mid+1,tr);
			return ans;
		}
	}else{
		int mid=(tl+tr)/2;
	return walk(lef(p),x,l,min(mid,r),tl,mid)+
		walk(rig(p),x, max(l,mid+1),r,mid+1,tr);
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for (int i = 1; i <= n; ++i)
	{
		cin>>a[i];
	}
	build(1,1,n);
	int q;
	cin>>q;
	Dado aux;	
		int tipo,l,r,x;
	while(q--){
		cin>>tipo;
		if(tipo==1){
			cin>>l>>r>>x;
			aux=query(1,l,r,1,n);
			// cout<<aux.val<<"\n";
			if(aux.val==x)
				cout<<"YES\n";
			else if(walk(1,x,l,r,1,n)==1)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}else{
			cin>>l>>x;
			update(1,x,1,n,l);
		}
	}

	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lef(x) (x<<1)
#define rig(x) lef(x)+1
const int N=200100;
ll tree[4*N],a[N];
void build(int p,int tl,int tr){
	if(tl==tr)
		tree[p]=a[tl];
	else{
		int mid=(tl+tr)/2;

		build(lef(p),tl,mid);
		build(rig(p),mid+1,tr);
		tree[p]=tree[lef(p)]+tree[rig(p)];
	}
}

ll query(int p,int l,int r,int tl,int tr){
	if(l>r)
		return 0;
	if(tl==l && r==tr)
		return tree[p];
	int mid=(tl+tr)/2;

	return query(lef(p),l,min(r,mid),tl,mid)+query(rig(p),max(l,mid+1),r,mid+1,tr);
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q,l,r,t;
	ll k;
	cin>>t>>k>>q;
	n=0;
	for (int i = 0; i < t; ++i)
	{
		cin>>l>>r;
		a[l]++;
		a[r+1]--;
		n=max(r,n);
	}
	for (int i = 0; i <= n; ++i)
	{
		a[i]+=a[i-1];
	}
	for (int i = 0; i <= n; ++i)
	{
		if(a[i]>=k){
			// cout<<i<<'\n';
			a[i]=1;
		}
		else
			a[i]=0;
	}
	build(1,1,n);
	while(q--){
		cin>>l>>r;
		if(l>n)
			cout<<0<<"\n";
		else{
			// cout<<l<<" "<<min(r,n)<<"\n";
			cout<<query(1,l,min(r,n),1,n)<<"\n";
		}
	}


	return 0;
}
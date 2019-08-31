#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lef(x) (x<<1)
#define rig(x) (lef(x)+1)

const int N=200100;

ll tree[4*N];
pair<ll,ll> a[N];

ll query(int p,int tl,int tr,int l,int r){
	if(l>r)
		return -1;

	if(tl==l && tr==r)
		return tree[p];

	int mid=(tl+tr)/2;
	return max(query(lef(p),tl,mid,l,min(r,mid)),query(rig(p),mid+1,tr,max(l,mid+1),r));
}


void update(int p,int tl,int tr,int k,ll x){
	if(tl==tr)
		tree[p]=x;
	else{
		int mid=(tl+tr)/2;
		if(mid>=k){
			update(lef(p),tl,mid,k,x);
		}else{

			update(rig(p),mid+1,tr,k,x);
		}
		tree[p]=max(tree[lef(p)],tree[rig(p)]);
	}
}







int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i].first;
	}

	for (int i = 0; i < n; ++i)
	{
		cin>>a[i].second;
	}
	// update(1,1,n,a[0].ft,a[0].second);
	for (int i = 0; i < n; ++i)
	{
		ll r=query(1,1,n,1,a[i].first);
		if((r+a[i].second)>query(1,1,n,a[i].first,a[i].first))
			update(1,1,n,a[i].first,r+a[i].second);
	}
	cout<<query(1,1,n,1,n)<<"\n";
}
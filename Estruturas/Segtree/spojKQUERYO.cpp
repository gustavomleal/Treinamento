#include<bits/stdc++.h>
using namespace std;
#define ft first
#define sd second 
#define lef(x) (x<<1)
#define rig(x)  (lef(x)+1)
#define ll long long
const int N=30100;

int a[N];
vector<int> tree[4*N];

void build(int p,int l,int r){
	if(l==r){
		tree[p].push_back(a[l]);
		// cout<<l<<" "<<r<<" "<<p<<"\n";
	}
	else{
		int mid=(l+r)/2;
		build(lef(p),l,mid);
		build(rig(p),mid+1,r);
		// cout<<l<<" "<<r<<"\n";
		tree[p].resize(r-l+1);
		merge(tree[lef(p)].begin(),tree[lef(p)].end(),tree[rig(p)].begin(),tree[rig(p)].end(),tree[p].begin());
	}
}

int query(int p,int l,int r,int tl,int tr,int k){
	if(l>r)
		return 0;
	if(tl==l && tr==r){
		// assert(!tree[p].empty());
		auto it=upper_bound(tree[p].begin(),tree[p].end(),k);
		// cout<<tl<<" "<<tr<<" "<<k<<" "<<p<<"\n";
		if(it!=tree[p].end()){
			// cout<<"oi\n";
			return (int)(tree[p].size()-(it-tree[p].begin()));
		}else{
			// cout<<"oi\n";
		return 0;
		}
	
	}else{
		int mid=(tl+tr)/2;
		return query(lef(p),l,min(mid,r),tl,mid,k)+
			query(rig(p),max(l,mid+1),r,mid+1,tr,k);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	cin>>q;
	int last=0;
	int x,y,k;
	while(q--){
		cin>>x>>y>>k;
		x^=last;
		y^=last;
		k^=last;
		if(x<1)
			x=1;
		if(y>n)
			y=n;
		if(x>y){
			last=0;
		}else{
		last=query(1,x,y,1,n,k);

		}
		cout<<last<<"\n";
	}

	return 0;
}
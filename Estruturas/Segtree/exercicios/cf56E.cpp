#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sd second
#define ft first
#define lef(x) (x<<1)
#define rig(x) (lef(x)+1)
const int N=100100;
pair < pair<ll,ll>,int > a[N];
ll resp[N];
int tree[4*N];
void build(int p,int tl,int tr){
	if(tl==tr)
		tree[p]=tl-1;
	else{
		int mid=(tl+tr)/2;
		build(lef(p),tl,mid);
		build(rig(p),mid+1,tr);
		tree[p]=max(tree[lef(p)],tree[rig(p)]);
	}
}


int query(int p,int l,int r,int tl,int tr){
	if(l>r)
		return 0;
	if(tl==l && tr==r)
		return tree[p];
	int mid=(tl+tr)/2;
	return max(query(lef(p),l,min(r,mid),tl,mid),query(rig(p),max(l,mid+1),r,mid+1,tr));

}

void update(int p,ll k,int x,int tl,int tr){
	if(tl==tr){
		// cout<<tl<<" alo"<<k<<"\n";
		tree[p]=k;
	}
	else{
		int mid=(tl+tr)/2;
		if(mid>=x){
			update(lef(p),k,x,tl,mid);
		}else
			update(rig(p),k,x,mid+1,tr);
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
		cin>>a[i].ft.ft>>a[i].ft.sd;
		a[i].sd=i;
	}
	sort(a,a+n);
	build(1,1,n);
	for(int i=n-1;i>=0;i--){
		int l,r,mid,rs;
		l=i,r=n-1;
		ll k=(a[i].ft.ft+a[i].ft.sd-1);
		while(l<=r){
			mid=(l+r)/2;
			if(a[mid].ft.ft<=k){
				rs=mid;
				l=mid+1;
			}
			else
				r=mid-1;
		}
		// cout<<i<<" "<<rs<<"\n";
		rs=query(1,i+1,rs+1,1,n);
		resp[a[i].sd]=(rs-i+1);
		update(1,rs,i+1,1,n);
		// cout<<a[i].ft.ft<<" "<<a[rs].ft.ft<<" "<<rs<<"\n";
	}
	for (int i = 0; i < n; ++i)
		cout<<resp[i]<<" ";
	cout<<endl;
}
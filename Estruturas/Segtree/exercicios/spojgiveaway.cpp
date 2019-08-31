#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
const int N=501000;
int a[N];


#define lef(x) (x<<1)
#define rig(x) (lef(x)+1)
#define all(v) v.begin(), v.end()
ordered_set stree[4*N];
void build(int p,int tl,int tr){
	if(tl==tr){
		// cout<<a[tl]<<"\n";
		stree[p].insert(a[tl]);
	}else{
		int mid=(tl+tr)/2;
		build(lef(p),tl,mid);
		build(rig(p),mid+1,tr);
		if(stree[lef(p)].size()>stree[rig(p)].size()){
			stree[p]=stree[lef(p)];
			for(auto c:stree[rig(p)]){
				stree[p].insert(c);
			}
		}else{
			stree[p]=stree[rig(p)];
			for(auto c:stree[lef(p)]){
				stree[p].insert(c);
			}
		}
		// merge(all(stree[lef(p)]),all(stree[rig(p)]),stree[p].begin());
	}
}


int query(int p,int l,int r,int tl,int tr,int k){
	if(l>r)
		return 0;
	if(tl==l && tr==r)
		return stree[p].order_of_key(k+1);
	int mid=(tl+tr)/2;
	return query(lef(p),l,min(r,mid),tl,mid,k)+ query(rig(p),max(l,mid+1),r,mid+1,tr,k);

}

void update(int p,int k,int last,int x,int tl,int tr){
	stree[p].erase(last);
	stree[p].insert(k);
	if(tl!=tr){
		int mid=(tl+tr)/2;
		if(mid>=x){
			update(lef(p),k,last,x,tl,mid);
		}else{
			update(rig(p),k,last,x,mid+1,tr);
		}
		
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]=-a[i];
	}
	build(1,1,n);
	scanf("%d",&q);
	int x,aa,b,c;
	while(q--){
		scanf("%d %d %d",&x,&aa,&b);
		if(x){
			update(1,-b,a[aa],aa,1,n);
			a[aa]=-b;
		}else{
			scanf("%d",&c);
			printf("%d\n",query(1,aa,b,1,n,-c));
		}

	}



	return 0;
}
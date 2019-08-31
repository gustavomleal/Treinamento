
#define lef(x) (x<<1)
#define rig(x) (lef(x)+1)
#define all(v) v.begin(), v.end()
vector<int> tree[4*N];
void build(int p,int tl,int tr){
	if(tl==tr){
		// cout<<a[tl]<<"\n";
		tree[p].push_back(a[tl]);
	}else{
		int mid=(tl+tr)/2;
		build(lef(p),tl,mid);
		build(rig(p),mid+1,tr);
		tree[p].resize(tr-tl+1);
		merge(all(tree[lef(p)]),all(tree[rig(p)]),back_inserter(tree[p]));
	}
}


int query(int p,int l,int r,int tl,int tr,int k){
	if(l>r)
		return 0;
	if(tl==l && tr==r)
		return upper_bound(all(tree[p]),k)-tree[p].begin();
	int mid=(tl+tr)/2;
	return query(lef(p),l,min(r,mid),tl,mid,k)+ query(rig(p),max(l,mid+1),r,mid+1,tr,k);

}

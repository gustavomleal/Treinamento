#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lef(x) (x<<1)
#define rig(x) lef(x) + 1
const int N=1000100;
pair<int,int> tree[4*N],a[N];
int lazy[4*N];
template <typename T,typename U>                                                   
pair<T,U> operator+(const pair<T,U> & l,const pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}

void push(int p){
	if(lazy[p]){
		swap(tree[lef(p)].ft,tree[lef(p)].sd);
		swap(tree[rig(p)].ft,tree[rig(p)].sd);
		lazy[lef(p)]=lazy[rig(p)]=1;
		lazy[p]=0;
	}
}



void build(int p,int tl,int tr){
	if(tl==tr)
		tree[p]=a[tl];
	else{
		int mid=(l+r)/2;
		build(lef(p),l,mid);
		build(rig(p),mid+1,r);
		tree[p]=tree[lef(p)]+tree[rig(p)];
	}
}


int walk(int p,int tl,int tr){
	if(tl==tr)
		return 1;
	if(!tree[lef(p)].sd && !tree[rig(p)].ft)
		return tree[lef(p)].ft+tree[rig(p)].sd;
	int mid=(tl+tr)/2;
	return max(walk(lef(p),))
}

void update(int p,int l,int r,int tl,int tr){
	if(l>r)
		return;
	push(p);
	if(tl==l && tr==r){
		swap(tree[p].ft,tree[p].sd);
		lazy[p]=1;
	}
	int mid=(tl+tr)/2;
	update(lef(p),l,min(mid,r),tl,mid);
	update(rig(p),max(mid+1,l),r,mid+1,tr);
	tree[p]=tree[lef(p)]+tree[rig(p)];
}




int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	return 0;
}
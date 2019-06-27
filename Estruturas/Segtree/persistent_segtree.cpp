#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100100;
typedef struct node{
	int l,r,at;
	int  value;
	node(){}	
	node(int a,int b,int c,int d):l(a),r(b),value(c),at(d){}


}Node;
Node NUL=Node(0,0,0,0);

Node merg(Node a,Node b,int x){
	Node rs;
	rs.l=a.at;
	rs.r=b.at;
	rs.at=x;
	rs.value=a.value+b.value;

	return rs;
}
int k=0;
void build(int p,int l,int r){
	if(l==r)
		tree[p]=Node(-1,-1,a[l],p);
	else{
		int mid=(l+r)/2;
		build(2*p,l,mid);
		build(2*p+1,mid+1,r);
		tree[p]=merg(tree[2*p],tree[2*p+1],p);
	}
	k=max(p,k);
}
int head[N];
Node tree[80*N];

void update(int olp,int p,int tl,int tr,int atp){
	if(tl==tr){
		tree[p]=tree[olp];
		tree[p].value++;
		tree[p].at=p;
		// cout<<tree[p].at<<"fim\n";
		k++;
	}else{
		int mid=(tl+tr)/2;
		if(mid>=atp){
			update(tree[olp].l,p+1,tl,mid,atp);
			tree[p]=merg(tree[p+1],tree[tree[olp].r],p);
		}else{
			update(tree[olp].r,p+1,mid+1,tr,atp);
			tree[p]=merg(tree[tree[olp].l],tree[p+1],p);
		}
		k++;
	}
}



int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(NULL),cout.tie(NULL);




	return 0;
}
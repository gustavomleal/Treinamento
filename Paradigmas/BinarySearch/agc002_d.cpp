#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define sd second
#define ft first
const int N=100100;
int pai[N],rk[N],que[N];
vector<int> lista[N];

typedef struct obj
{
	int l,r;
	vector<pair<pair<int,int>,pair<int,int>>> v;
}Obj;



void init(){
	for(int i=0;i<N;i++){
		pai[i]=i,rk[i]=1;
	}
}

int find(int x){
	if(x==pai[x])
		return x;
	return pai[x]=find(pai[x]);
}



void join(int a,int b){
	a=find(a);
	b=find(b);
	if(a!=b){
		if(rk[a]<rk[b])
			swap(a,b);
		pai[b]=a;
		rk[a]+=rk[b];
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	int q,a,b,z;
	cin>>n>>m;
	queue<Obj> f;
	Obj x;
	x.l=1,x.r=n;
	while(m--){
		cin>>a>>b;
		lista[a].pb(b);
		lista[b].pb(a);
	}

	cin>>q;
	for(int i=0;i<q;i++){
		cin>>a>>b>>z;
		x.v.pb({{a,b},{z,i}});
	}
	f.push(x);
	int at=n+1,t=0;
	while(!f.empty()){
		Obj x,lx,rx;
		// cout<<x.l<<" "<<x.r<<endl;
		x=f.front();
		f.pop();
		if(x.l>=x.r){
			int mid=x.r;
			for(int i=0;i<x.v.size();i++){
				cout<<mid<<" "<<x.v[i].ft.ft<<" "<<x.v[i].ft.sd<<" "<<x.v[i].sd.ft<<"\n";
				que[x.v[i].sd.sd]=mid;
			}
		}else{
			int mid=(x.l+x.r)/2;
			lx.l=x.l;
			lx.r=mid;
			rx.l=mid+1;
			rx.r=x.r;
			if(at>mid){
				init();
				at=0;
			}
			while(at!=mid){
				at++;
				for(int i=0;i<lista[at].size();i++){
	
						join(at,lista[at][i]);
				}
			}
			for(int i=0;i<x.v.size();i++){
				if(find(x.v[i].ft.ft)==find(x.v[i].ft.sd) && rk[find(x.v[i].ft.ft)]>=x.v[i].sd.ft){
					lx.v.pb(x.v[i]);
				}else{
					rx.v.pb(x.v[i]);
				}
			}
			f.push(rx);
			f.push(lx);
		}
	}
	for (int i = 0; i < q; ++i)
	{
		cout<<que[i]<<"\n";
	}

}
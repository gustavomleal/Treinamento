#include<bits/stdc++.h>
using namespace std;
#define sd second 
#define ft first
#define lef(x) (x<<1)
#define rig(x) (lef(x)+1)
const int N=100000;
const int K=30;
pair<int,int> v[N],k[N];
map<int,int> mp,rmp;
int st[4*N][K],lo[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin>>n;
	set<int> s;
	lo[1]=0;
	for(int i=2;i<N;i++)
		lo[i]=lo[i/2]+1;
	for(int i=0;i<n;i++){
		cin>>v[i].ft>>v[i].sd;
		s.insert(v[i].ft);
		s.insert(v[i].sd);
	}
	cin>>q;
	for(int i=0;i<q;i++){

		cin>>k[i].ft>>k[i].sd;
		s.insert(k[i].ft);
		s.insert(k[i].sd);
	}
	int x=0;
	for(auto c:s){
		mp[c]=x;
		rmp[x]=c;
		x++;
	}
	for(int i=0;i<n;i++){
		st[mp[v[i].ft]][0]++;
		st[mp[v[i].sd]+1][0]--;
	}
	for(int i=1;i<=x;i++){
		st[i][0]+=st[i-1][0];
		// cout<<i<<" "<<st[i][0]<<"\n";
	}
	for(int j=1;j<K;j++){
		for(int i=0;i+(1<<(j))<=x;i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
	for (int i = 0; i < q; ++i)
	{
		int l=mp[k[i].ft],r=mp[k[i].sd];
		int at=lo[r-l+1];
		// cout<<k[i].ft<<" "<<k[i].sd<<"\n";
		// cout<<l<<" "<<r-(1<<(at))+1<<" "<<at<<"\n";
		cout<<max(st[l][at],st[r-(1<<(at))+1][at])<<"\n";
	}


	return 0;
}
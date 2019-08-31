#include<bits/stdc++.h>
using namespace std;
const int N=200100;
int npos[N],pos[N],n;
int dp[N][3];
map<int,int> mp;
int solve(int p,int flag){
	if(p==-1)
		return 0;
	if(p==n)
		return dp[p][flag]=0;
	int &ans=dp[p][flag];
	if(ans!=-1)
		return ans;
	if(flag){
		ans=max(1+solve(pos[p],1),solve(npos[p],1));
	}else{
		ans=max(1+solve(pos[p],1),solve(p+1,0));
	}
	return ans;
}
int walk(int p,int flag){
	bool f=false;
	if(flag){
		if(pos[p]!=-1 && dp[p][flag]==(dp[pos[p]][1]+1)){
			cout<<p+1<<' ';
			walk(pos[p],1);
			f=true;
		}else if(npos[p]!=-1 && dp[p][flag]==(dp[npos[p]][1])){
			// cout<<p+1<<' ';
			walk(npos[p],1);
			f=true;
		}else{
			cout<<p+1<<' ';
		}
	}else{
		if(pos[p]!=-1 && dp[p][flag]==(dp[pos[p]][1])+1){
			cout<<p+1<<' ';
			walk(pos[p],1);
			f=true;
		}else if (dp[p][flag]==(dp[p+1][0])){
			// cout<<p+1<<"alo ";
			walk(p+1,0);
			f=true;
		}
	}

}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	memset(pos,-1,sizeof(pos));
	memset(npos,-1,sizeof(npos));
	memset(dp,-1,sizeof(dp));
	int k;
	for (int i = 0; i <n ; ++i)
	{
		cin>>k;
		if(mp.find(k-1)!=mp.end()){
			if(pos[mp[k-1]]==-1)
				pos[mp[k-1]]=i;
		}

		if(mp.find(k)!=mp.end()){
			npos[mp[k]]=i;
		}
		mp[k]=i;
	}
	cout<<solve(0,0)<<"\n";
	if(solve(0,0)==1)
		cout<<"1 ";
	walk(0,0);
	cout<<"\n";
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=1000100;
const int INF=10000000;
vector<int>lista[N];
int dp[N][5][6];
int n,m;
int s,t;

int solve(int p,int flag,int x,int k){
	printf("%d, %d, %d, %d\n", p, flag, x, k);
	fflush(stdout);
	if(k>n/2)
		return INF;
	if(p==t && flag==0)
		return 0;
	int &ans1=dp[p][flag][x],ans;
	if(ans1!=-1)
		return ans1;
	ans1=INF-1;
	ans=INF;
	if(flag==0){
		for (int i = 0; i < lista[p].size(); ++i)
		{
			int u=lista[p][i];
			ans=min({solve(u,2,1,k+1),solve(u,1,1,k+1),ans});
		}
		ans++;
	}else if(flag==1){
		if(x==2){
			for (int i = 0; i < lista[p].size(); ++i)
			{
				int u=lista[p][i];
				ans=min(solve(u,0,0,k+1),ans);
			}
		}else{
			for (int i = 0; i < lista[p].size(); ++i)
			{
				int u=lista[p][i];
				ans=min(solve(u,1,x+1,k+1),ans);
			}
		}
	}else{
		if(x==4){
			for (int i = 0; i < lista[p].size(); ++i)
			{
				int u=lista[p][i];
				ans=min(solve(u,0,0,k+1),ans);
			}
		}else{
			for (int i = 0; i < lista[p].size(); ++i)
			{
				int u=lista[p][i];
				ans=min(solve(u,1,x+1,k+1),ans);
			}
		}
	}
	ans1=ans;
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>s>>t;
	int a,b;
	memset(dp,-1,sizeof(dp));
	for (int i = 0; i < m; ++i)
	{
		cin>>a>>b;
		lista[a].push_back(b);
	}
	cout << "aqui" << endl;
	cout<<solve(s,0,0,0)<<"\n";
}
#include<bits/stdc++.h>
using namespace std;
const int N=100100;
vector<int> lista[N];
int dp[N];


int solve(int u){
	int &ans=dp[u];
	if(ans!=-1)
		return ans;
	ans=0;
	for (int i = 0; i < lista[u].size(); ++i)
	{	
		int v=lista[u][i];
		ans=max(ans,solve(v));
	}
	ans++;
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp,-1,sizeof(dp));
	int n,a,b,m;
	cin>>n>>m;
	for (int i = 0; i < m; ++i)
	{
		cin>>a>>b;
		lista[a].push_back(b);
	}
	int rs=0;
	for (int i = 1; i <= n; ++i)
	{
		rs=max(rs,solve(i));
		// cout<<i<<" "<<solve(i)<<"\n";
	}
	cout<<rs-1<<'\n';
}
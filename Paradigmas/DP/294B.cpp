#include<bits/stdc++.h>
using namespace std;
const int N=110;
pair<int,int> a[N];
int dp[N][2*N][2*N],n;
int solve(int p,int t,int w){
	if(p==n){
		if(t>=w)
			return t;
		return 300;
	}
	int &ans=dp[p][t][w];
	if(ans!=-1)
		return ans;
	ans=solve(p+1,t+a[p].first,w);
	if((w+a[p].second)<=200)
		ans=min(ans,solve(p+1,t,w+a[p].second));
	return ans;
}




int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i].first>>a[i].second;
	}
	cout<<solve(0,0,0)<<"\n";



	return 0;
}
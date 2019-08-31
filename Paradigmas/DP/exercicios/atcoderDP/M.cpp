#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=110;
const int K=100100;
const ll mod=1000000007;
ll dp[N][K];
ll pref[N][K];
int a[N];
int n;




// ll solve(int p,int k){
// 	if(p==(n-1)){
// 		if(k>a[p])
// 			return 0LL;
// 		return 1LL;
// 	}
// 	ll &ans=dp[p][k];
// 	if(ans!=-1LL)
// 		return ans;
// 	ans=0;
// 	//NK^2
// 	for (int i = 0; i <= min(a[p],k); ++i)
// 	{
// 		ans=(ans+solve(p+1,k-i))%mod;
// 	}
// 	return ans;
// }


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	// memset(dp,-1LL,sizeof(dp));
	cin>>n>>k;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	for (int i = 0; i <= a[0]; ++i)
	{
		dp[0][i]=1;
	}
	for (int i = 0; i <= k; ++i)
	{
		pref[0][i+1]=(dp[0][i]+pref[0][i])%mod;
	}

	for (int i = 1; i < n; ++i)
	{

		for (int v = 0; v <=k ; ++v)
		{
			// for (int j = 0; j <= a[i]; ++j)
			// {
			
				dp[i][v]=pref[i-1][v+1]-pref[i-1][v-min(a[i],v)];
			// }
		}
		for (int j = 0; j <= a[i]; ++j){
			cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
		}
		for (int j = 0; j <= k; ++j)
		{
			pref[i][j+1]=(dp[i][j]+pref[i][j])%mod;
		}
	}
	cout<<dp[n-1][k+1]<<"\n";


	return 0;
}
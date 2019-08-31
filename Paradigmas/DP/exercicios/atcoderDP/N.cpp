#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500;

ll dp[N][N];
ll n,a[N];
ll solve(int i,int j){
	if(i>j)
		return 0LL;

	if(i==(j-1LL)){
		return a[j]-a[i-1];
	}
	if(i==j)
		return 0LL;
	ll &ans=dp[i][j];
	if(ans!=-1LL)
		return ans;
	ans=10000000000000LL;
	for (int c = i; c <=j; ++c)
	{
		ll l=solve(i,c);
		ll r=solve(c+1,j);
		ans=min(ans,l+r+a[j]-a[i-1]);
		// cout<<ans<<"\n";
	}
	return ans;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	memset(dp,-1LL,sizeof(dp));
	for (int i = 1; i <=n; ++i)
	{
		cin>>a[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		a[i]+=a[i-1];
	}
	cout<<solve(1,n)<<"\n";
}
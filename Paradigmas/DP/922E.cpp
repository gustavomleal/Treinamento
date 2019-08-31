#include<bits/stdc++.h>
using namespace std;
const int N=1100;
#define ll long long
const ll inf=1e15;
ll dp[N][N*10];
ll t[N],c[N];
ll w,b,x;
int n;









int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	// cout<<inf<<"\n";
	ll tot=0LL;
	cin>>n>>w>>b>>x;
	for (int i = 0; i < n; ++i)
	{
		cin>>c[i];
		tot+=c[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>t[i];
	}
	for (int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N*10; ++j)
		{
			dp[i][j]=-inf;
		}
	}
	dp[0][0]=w;
	for(ll i=0;i<n;i++)
	{
		for(ll j = 0; j <= tot && dp[i][j]>=0LL; ++j)
		{
			for(ll k=0;k<=c[i] && dp[i][j] - k * t[i] >= 0LL;k++){
				dp[i+1][j+k]=max(dp[i+1][j+k],min(dp[i][j]+x-k*t[i],w+(j+k)*b));
				if(dp[i][j]<0LL)
					dp[i][j]=-inf;
			}
		}
	}
	int rs=0;
	for (int i = 0; i <= 10000; ++i)
	{
		if(dp[n][i]>=0LL){
			// cout<<i<<" "<<dp[n][i]<<"\n";
			rs=i;
		}
	}
	// cout<<solve(n-1,12)<<"\n";
	cout<<rs<<"\n";

	return 0;
}
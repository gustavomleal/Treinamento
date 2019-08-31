#include<bits/stdc++.h>
using namespace std;
const int N=3100;
#define ll long long
ll a[N];
ll dp[N][N][3];


ll solve(int l,int r,int flag){
	if(l>r)
		return 0LL;
	ll &ans=dp[l][r][flag];
	if(ans!=-1LL)
		return ans;
	if(flag){
		ans=max(a[l]+solve(l+1,r,!flag),a[r]+solve(l,r-1,!flag));
	}else{
		ans=min(-a[l]+solve(l+1,r,!flag),-a[r]+solve(l,r-1,!flag));
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp,-1LL,sizeof(dp));
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cout<<solve(0,n-1,1)<<"\n";
}
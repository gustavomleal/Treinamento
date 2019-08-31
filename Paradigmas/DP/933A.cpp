#include<bits/stdc++.h>
using namespace std;
const int N=2100;

int dp[N][5][5][5],n,a[N];




int solve(int p,int fmsk,int smsk,int flag){
	if(p==n)
		return 0;
	int &ans=dp[p][fmsk][smsk][flag];
	if(ans!=-1)
		return ans;
	if(flag==0){
		if(a[p]==2){
				ans=max({1+solve(p+1,fmsk|2,smsk,flag),1+solve(p+1,fmsk|2,smsk,1),solve(p+1,fmsk,smsk,flag),solve(p+1,fmsk,smsk,1)});
		}else{
			if(!(fmsk&(1<<1))){
				ans=max({1+solve(p+1,fmsk|1,smsk,flag),1+solve(p+1,fmsk|1,smsk,1),solve(p+1,fmsk,smsk,flag),solve(p+1,fmsk,smsk,1)});
			}else{
				ans=max(solve(p+1,fmsk,smsk,flag),solve(p+1,fmsk,smsk,1));
			}		
			
		}
	}else if(flag==1){
		if(a[p]==2){
			if(!(smsk&(1<<0)) ){
				ans=max({1+solve(p+1,fmsk,smsk|2,flag),1+solve(p+1,fmsk,smsk|2,2),solve(p+1,fmsk,smsk,flag),solve(p+1,fmsk,smsk,2)});
			}else{
				ans=max(solve(p+1,fmsk,smsk,flag),solve(p+1,fmsk,smsk,1));
			}		}else{
			if(!(fmsk&(1<<1)) ){
				ans=max({1+solve(p+1,fmsk,smsk|1,flag),1+solve(p+1,fmsk,smsk|1,2),solve(p+1,fmsk,smsk,flag),solve(p+1,fmsk,smsk,2)});
			}else{
				ans=max(solve(p+1,fmsk,smsk,flag),solve(p+1,fmsk,smsk,1));
			}
		}
	}else if(flag==2){
		if(a[p]==2){
				ans=max({1+solve(p+1,fmsk,smsk|2,flag),solve(p+1,fmsk,smsk,flag)});
		}else{
			if(!(fmsk&(1<<1)) && !(smsk&(1<<1))){
				ans=max({1+solve(p+1,fmsk,smsk|1,flag),solve(p+1,fmsk,smsk,flag)});
			}else{
				ans=solve(p+1,fmsk,smsk,flag);
			}
		}
	}

	return ans;
}




int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	cout<<max(solve(0,0,0,0),solve(0,0,0,1))<<"\n";
	return 0;
}
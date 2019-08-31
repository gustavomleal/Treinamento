#include<bits/stdc++.h>
using namespace std;
const int K=72;
int mask[K],n,dp[K][(1<<20)];
vector<int> pr;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 2; i < K; ++i)
	{
		boolean f=true;
		for (int j = 2; j < i; ++j)
		{
			if(i%j==0)
				f=false;
		}
		if(f)
			pr.push_back(i);
	}
	for (int i = 2; i < K; ++i)
	{
		int x=i;
		for(int j=0;j<pr.size();j++){
			while(x%pr[j]==0){
				x/=pr[j];
				mask[i]^=(1<<(j));
			}
		}
	}
	int n;
	cin>>n;




	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll  long long
vector<vector<ll>> T{
					{2,1,1},
					{1,1,0},
					{0,0,1}}
						;

vector<ll> f={1,0,1};
ll m=1000000007LL;
ll md(ll x){
	return (((x)%m)+m)%m;
}


void calcm(vector<vector<ll>> &A,vector<vector<ll>> B){
	int n=T.size();
	vector<vector<ll>> x(n, std::vector<ll>(n,0LL));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ll at=0LL;
			for(int k=0;k<n;k++)
			{
				at=md(at+A[i][k]*B[k][j]);
			}
			x[i][j]=md(x[i][j]+at);
			// cout<<x[i][j]<<" ";
		}
		// cout<<"\n";
	}
	A=x;
}

void fastmexpo(ll n,vector<vector<ll>> &A){
	bool v=true;
	vector<vector<ll>> x;
	while(n){
		if(n&1LL){
			// cout<<"guardei\n";
			if(v){
				v=false;
				x=A;
			}
			else
				calcm(x,A);
		}
		calcm(A,A);

		n=n>>1LL;
		// cout<<n<<"<-N\n";
	}
	A=x;
}





int main(){
	ll n,d;
	int q;
	cin>>q;
	vector<vector<ll>> A;
	while(q--){
		cin>>n;
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		A=T;
		fastmexpo(n-1,A);
		// for(int i=0;i<A.size();i++)
		// {
		// 	for(int j=0;j<A.size();j++)
		// 	{
		// 		cout<<A[i][j]<<" ";
		// 	}
		// 	cout<<"\n";
		// }
		ll ans=0LL;
		for (int i = 0; i <A.size() ; ++i)
		{
			ans=md(ans+f[i]*A[0][i]);
			// cout<<A[0][i]<<" "<<f[i]<<'\n';
		}
		cout<<md(ans-n)<<"\n";
	}
	


	return 0;
}
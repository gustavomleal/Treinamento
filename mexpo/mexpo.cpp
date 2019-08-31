#include<bits/stdc++.h>
using namespace std;
#define ll  long long
vector<vector<ll>> T;

vector<ll> f;
ll m;
ll md(ll x){
	return (x)%m;
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
	cin>>d>>n>>m;
	T.resize(d,vector<ll>(d));

	f.resize(d);
	for (int i = 0; i < d; ++i)
	{
		cin>>T[0][i];
		T[0][i]=md(T[0][i]);
		if(i!=(d-1))T[i+1][i]=1;
	}
	for (int i = d-1; i >=0; --i)
	{
		cin>>f[i];
		f[i]=md(f[i]);
	}
	vector<vector<ll>> A=T;
	for (int i = 0; i <A.size() ; ++i)
	{
		// cout<<A[0][i]<<'\n';
	}
	if(n<=d){
		cout<<f[n-1]<<"\n";
		return 0;
	}
	fastmexpo(n-A.size(),A);
	for(int i=0;i<A.size();i++)
	{
		for(int j=0;j<A.size();j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<"\n";
	}
	ll ans=0LL;
	for (int i = 0; i <A.size() ; ++i)
	{
		ans=md(ans+f[i]*A[0][i]);
		// cout<<A[0][i]<<'\n';
	}
	cout<<ans<<"\n";


	return 0;
}
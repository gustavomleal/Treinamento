#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
#define ll  long long
vector<vector<ll>> T;
ll m=1000000007LL;
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
	if(n==0)
		return;
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
	string s;
	ll n,m,k;
	cin>>n>>m>>k;
	T.resize(m,vector<ll>(m,1));
	while(k--){
		cin>>s;
		if(s[0]>='A' && s[0]<='Z')
			s[0]=s[0]-'A'+26;
		else
			s[0]=s[0]-'a';
		if(s[1]>='A' && s[1]<='Z')
			s[1]=s[1]-'A'+26;
		else
			s[1]=s[1]-'a';
		T[s[0]][s[1]]=0;
	}
	// for (int i = 0; i < m; ++i)
	// {
	// 	T[i][i]=0;
	// }
	for (int i = 0; i < m; ++i)
	{
		for(int j=0 ; j<m;j++)
		{
			// cout<<T[i][j]<<" ";
		}
		// cout<<"\n";
	}
	if(n==1){
		cout<<m<<"\n";
		return 0;
	}
	fastmexpo(n-1,T);
	ll sum=0LL;
	for (int i = 0; i < m; ++i)
	{
		for(int j=0 ; j<m;j++)
		{
			sum=md(sum+T[i][j]);
			// cout<<T[i][j]<<" ";
		}
		// cout<<"\n";
	}
	cout<<sum<<"\n";


	return 0;
}
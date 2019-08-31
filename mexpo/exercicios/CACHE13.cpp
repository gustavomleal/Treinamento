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

vector<vector<ll>>make{
					{1,2,3},
					{1,3,2},
					{2,1,3},
					{2,3,1},
					{3,1,2},
					{3,2,1},
					{1,2,1},
					{1,3,1},
					{2,1,2},
					{2,3,2},
					{3,1,3},
					{3,2,3}
};



int main(){
	string s;
	ll n,m,k;
	cin>>n;
	T.resize(12,vector<ll>(12,1));
	
	if(n==1){
		cout<<12<<"\n";
		return 0;
	}
	for (int i = 0; i < 12; ++i)
	{
		for(int j=0 ; j<12;j++)
		{
			bool v=false;
			for (int c = 0; c < 3; ++c)
			{
				if(make[i][c]==make[j][c])
					v=true;
			}
			if(v)
				T[i][j]=0;
		}
		// cout<<"\n";
	}
	fastmexpo(n-1,T);
	ll sum=0LL;
	for (int i = 0; i < 12; ++i)
	{
		for(int j=0 ; j<12;j++)
		{
			sum=md(sum+T[i][j]);
			// cout<<T[i][j]<<" ";
		}
		// cout<<"\n";
	}
	cout<<sum<<"\n";


	return 0;
}
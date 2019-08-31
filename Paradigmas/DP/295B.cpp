#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 510;
ll dist[N][N];
int n;
ll a[N],r[N];


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for (int i = 1; i <=n ; ++i)
	{
		for(int j=1; j <= n; j++)
			cin>>dist[i][j];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	for(int i= n-1; i >= 0; i--){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dist[j][k]=min(dist[j][k],dist[j][a[i]]+dist[a[i]][k]);
			}
		}
		// cout<<a[i]<<"oi\n";
		for(int j=n-1;j>=i;j--){
			for(int k=n-1;k>=i;k--){
				// cout<<a[j]<<" "<<a[k]<<" "<<dist[a[j]][a[k]]<<"\n";
				r[i]+=dist[a[j]][a[k]];
			}
		}
		// r[i]/=2LL;
	}
	for (int i = 0; i < n; ++i)
	{
		cout<<r[i]<<" ";
	}
	cout<<"\n";


	return 0;
}
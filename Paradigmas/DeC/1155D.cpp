#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100100; 
ll pref[N];
ll x;
	int n;

ll solve(ll l,ll r){
	if(l>=r)
		return 0LL;
	cout<<l<<" "<<r<<" "<</*(pref[r]-pref[l])*x*/ + pref[l]+pref[n]-pref[r]<<"\n";
	return max({(pref[r]-pref[l])*x + pref[l]+pref[n]-pref[r],solve(l+1,r),solve(l,r-1),0LL});
}


int main(){
	cin>>n>>x;
	for(int i=1; i<=n;i++)
	{
		cin>>pref[i];
		pref[i]+=pref[i-1];

	}
	cout<<solve(0,n)<<"\n";
	return 0;
}
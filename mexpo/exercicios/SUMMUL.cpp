#include<bits/stdc++.h>
using namespace std;


int f(int x){
	if(x==1)
		return 1;

	int ans=0;
	ans+=x;
	for (int i = 1; i <x ; ++i)
	{
		ans+=i*f(x-i);
	}
	return ans;
}



int main(){

	for (int i = 1; i <=10 ; ++i)
	{
		cout<<i<<" "<<f(i)-i<<"\n";
	}
}
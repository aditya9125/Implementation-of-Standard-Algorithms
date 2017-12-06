	///status : AC
#include <bits/stdc++.h>
using namespace std;


vector<int> dp,v;


int main(void)
{


		ifstream cin("/home/aditya/Documents/ip");
	int n;

	cin>>n;

	dp= vector<int>(n,1);
	v= vector<int> (n);


	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(v[j]<v[i])
				dp[i]= max(dp[i], 1+dp[j]);
		}
	}


	int ans=1;
	for(int i=0;i<n;i++)
	{
		ans = max(ans, dp[i]);
	}

	cout<<ans<<"\n";

	return 0;
}

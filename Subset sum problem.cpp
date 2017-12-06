#include<bits/stdc++.h>

using namespace std;

bool No_such_subset=true;

void print(vector<int> & v)
{
	No_such_subset=false;

	for(auto item:v) cout<<item<<" ";

	cout<<"\n";
}

void subsetSum(vector<int> &v,int i,int x, vector<int> subset)
{
	if(x==0)
	{
		print(subset);
		return ;
	}

	if(x<v[i]) return ;

	subset.push_back(v[i]);
	subsetSum(v,i+1,x-v[i],subset);		///These three lines are equivalent to subsetSum(v,i+1,x-v[i],subset+"v[i]")
	subset.pop_back();


	subsetSum(v,i+1,x,subset);

}

int main()
{
	int n;
	cout<<"Enter the size \n";
	cin>>n;

	vector<int> v(n);

	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	sort(v.begin(),v.end());

	cout<<"Enter the required sum \n";

	int reqSum;
	cin>>reqSum;

	vector<int> emptyvec;

	subsetSum(v,0,reqSum,emptyvec);

	if(No_such_subset) cout<<"No such subset found\n";





}

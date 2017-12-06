#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int binary_Search(int l,int r,int item)
{

    if(l>r) return -1;

    int mid=(l+r)>>2;

    if(v[mid]==item) return mid;

    if(item>v[mid]) return binary_Search(mid+1,r,item);

	return binary_Search(l,mid-1,item);
}

int main()
{

	int n,item;
	cout<<"Enter no of elements\n";
	cin>>n;

	v=vector<int>(n);

	for(int i=0;i<n;i++)
	{
			cin>>v[i];
	}


	sort(v.begin(),v.end());


	cout<<"Enter the item\n";

	cin>>item;

	int res= binary_Search(0,n-1,item);

	if(res==-1) cout<<item<<" Does'nt exist !";
	else cout<<item<<" item found as "<<res<<"\n";


}

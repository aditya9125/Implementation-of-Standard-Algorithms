#include<bits/stdc++.h>

using namespace std;


vector<int> v;

vector<int> output;

void Sort_counting(int len,vector<int> &v)
{
	vector<int> cnt(len+1);

	for(int i=0;i<v.size();i++) cnt[v[i]]++;

	for(int i=1;i<cnt.size();i++)
	cnt[i]= cnt[i] + cnt[i-1];

	for(int i=0;i<v.size();i++)
	{
        int pos = cnt[v[i]];

        output[pos] =v[i];
	}
}

int main()
{

	int n;

	cin>>n;

	v= vector<int>(n);

	output= vector<int>(n+1);

	int len_cnt= INT_MIN;
	for(int i=0;i<n;i++){
		cin>>v[i];

		len_cnt= max(len_cnt,v[i]);
	}

    Sort_counting(len_cnt,v);



klllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll;    for(int i=0)

}

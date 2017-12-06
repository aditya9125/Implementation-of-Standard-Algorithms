typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

#include<bits/stdc++.h>
#include<cmath>
#include<cstdlib> //for qsort
#include<cstdio>

#define rep(x,a,b) for(x=a;x<b;x++)
#define reptill(x,a,b) for(x=a;x<=b;x++)

#define scani(x) scanf("%d",&x)
#define scan2i(x,y) scanf("%d %d",&x,&y)
#define scan3i(x,y,z) scanf("%d %d %d",&x,&y,&z)

#define scanfl(x) scanf("%f",&x)
#define scanc(x) scanf("%c",&x)
#define scand(x) scanf("%lf",&x)

#define scanll(x) scanf("%lli",&x)
#define scan2ll(x,y) scanf("%lli %lli",&x,&y)
#define scan3ll(x,y) scanf("%lli %lli %lli",&x,&y,&z);

#define scanl(x) scanf("%ld",&x)
#define scans(x) scanf("%s",x)
#define printi(x) printf("%d\n",x)
#define printl(x) printf("%ld\n",x)
#define printll(x) printf("%lli\n",x)
#define printd(x) printf("%lf\n",x)
#define printfl(x) printf("%f\n",x)
#define printc(x) printf("%c\n",x)
#define prints(x) printf("%s\n",x);
#define sloop(x) loop(i,0,strlen(x)-1)
#define whole(x) x.begin(),x.end()
#define pb push_back
#define newl cout<<"\n"
#define F first
#define S second
#define FILL(A,value) memset(A,value,sizeof(A))

inline bool inc_range(int x,int y,int z) { return ((x>=y)&&(x<=z)); }
inline bool ex_range(int x,int y,int z) { return ((x>y)&&(x<z)); }
inline bool is_either(int x,int y,int z) { return ((x==y)||(x==z)); }

//maths
#define PI acos(-1)

#define INTmax numeric_limits<int>::max()
#define LLmax numeric_limits<ll>::max()
#define ULLmax numeric_limits<ull>::max()

#define INTmin numeric_limits<int>::min()


using namespace std;

template<typename type>
void get_arr(type a[],type n) {for(type i=0;i<n;i++) cin>>a[i];}

template<typename type>
void show_arr(type a[],type n=1) {for(type i=0;i<n;i++) cout<<a[i]<<" ";}

template<typename type>
inline type max3(type a,type b,type c){	 return max(max(a,b),c);}

template<typename type>
inline type min3(type a,type b,type c){	 return min(a,min(b,c));}

template<typename type>
inline type min4(type a,type b,type c,type d){	 return min(a,min3(b,c,d));}


template<typename type>
type fastpow(type a, type b, type c) { type ans=1;  while(b != 0){ if(b%2 == 1) ans=(ans*a)%c;  a=(a*a)%c; b /= 2; } return ans; }

template<typename type>
type phi(type n){ type result = n;  for (type p=2; p*p<=n; ++p) { if (n % p == 0){ while (n % p == 0)   n /= p; result -= result / p; } }
if (n > 1) result -= result / n; return result;
}



inline void FAST_IO(){ios_base::sync_with_stdio(false);}

#define SIZE int(1e3)+1
#define MOD
#define debug
#define MAX 100
#define left 2*i
#define rit 2*i+1
//#define Online_judge


int tree[4*MAX],Node[MAX];




void max_heapify(int i,int N)
{

	if(i>N)
	 return ;

	int maxIndx=i;

	if(left<=N and tree[left]>tree[maxIndx])
	{
		maxIndx=left;

	}
	if(rit<=N and tree[rit]>tree[maxIndx])
	{
		maxIndx=rit;
	}
	if(maxIndx!=i)
	{
		swap(tree[i],tree[maxIndx]);
		max_heapify(maxIndx,N);
	}

}

void build_max_heap(int nodes)
{
	for(int i=nodes/2;i>=1;i--)
	{
		max_heapify(i,nodes);
		}

}


int extract_prior(int N)
{
	if(N<1)
		return -1;


	int prior=tree[1];

	tree[1]=tree[N];

	max_heapify(1,N-1);

	return prior;
}

void increase_key(int i,int key,int N)
{
	if(i>N)
	 return ;

	tree[i]=key;

	while(i>1 and tree[i]>tree[i/2])
	 swap(tree[i],tree[i/2]),i/=2;
}

void insert_key(int item,int N)
{
	increase_key(N+1,item,N+1);
}

int main()
{

	int N,i;
	cout<<"Enter the no of Nodes\n";
	cin>>N;

	reptill(i,1,N)
	{

		cin>>Node[i];
		tree[i]=Node[i];

	}

		reptill(i,1,N/2)
		{
			cout<<tree[i]<<" - "<<"("<<tree[left]<<","<<tree[rit]<<")\n";

		}
		newl;

	 	 cout<<"Max heap is now\n\n";

		build_max_heap(N);



		reptill(i,1,N/2)
		{
			cout<<tree[i]<<" - "<<"("<<tree[left]<<","<<tree[rit]<<")\n";

		}
/*
		for(i=1;i<=15;i++)
		{
			cout<<extract_prior(N--)<<" ";

		}
*/

	   //cout<<"Heap size is now "<<N;
		newl;newl;


		insert_key(0,N++);
	    cout<<"After insertion \n\n";

		reptill(i,1,N/2)
		{
			cout<<tree[i]<<" ";
			cout<<tree[left]<<" ";
			if(rit<=N)
			 cout<<tree[rit]<<" ";

			newl;
		}
 }



















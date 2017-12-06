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
#define scan3ll(x,y,z) scanf("%lli %lli %lli",&x,&y,&z);

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
#define newl cout<<"\n"
#define FILL(A,value) memset(A,value,sizeof(A))


#define whole(x) x.begin(),x.end()
#define pb push_back
#define in insert
#define mp make_pair
#define get(tp_name,x) (get<x>(tp_name))   ///to access tuple(i)
#define umap unordered_map



using namespace std;


#define F first
#define S second



///Optional

///vector< vector<int> > costs(N, vector<int>(M, 0));   //NxM 2d preinitialized(0) vector

 ///comparator class for ordering on the basis of 'Second'
/*
class CompareDist
{
	public:				///pairType doesn't name a type ,its just to show type of pair object passed in operatorfunction

    bool operator()( pairType p1, pairType p2) {
        return p1.S>p2.S;
    }
};
*/

typedef pair<int,int> II;
typedef vector<II> VII;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector< VI > VVI;
typedef vector< VL > VVL;
typedef vector<string> VS;

inline bool inc_range(int x,int y,int z) { return ((x>=y)&&(x<=z)); }
inline bool ex_range(int x,int y,int z) { return ((x>y)&&(x<z)); }
inline bool is_either(int x,int y,int z) { return ((x==y)||(x==z)); }

//maths
#define PI acos(-1)

#define INTmax numeric_limits<int>::max()
#define LLmax numeric_limits<ll>::max()
#define ULLmax numeric_limits<ull>::max()

#define INTmin numeric_limits<int>::min()


typedef priority_queue<II,vector<II>, greater<II> > P_Queue;             ///priority queue contianing II (having vector<II> as underlying container) with greater as functor
																		///		heapify on the basis of comparisons of  II.first  values

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
type modpowIter(type a, type b, type c) { type ans=1;  while(b != 0){ if(b%2 == 1) ans=(ans*a)%c;  a=(a*a)%c; b /= 2; } return ans; }

template<typename type>
type phi(type n){ type result = n;  for (type p=2; p*p<=n; ++p) { if (n % p == 0){ while (n % p == 0)   n /= p; result -= result / p; } }
if (n > 1) result -= result / n; return result;
}

template<class type>
type ncr(type n,type r)
{  	assert(n>=r);
	type ans=1,i;
	if(n==r) return 1; if(r==1) return n; if(r>(n-r)) r=n-r;
	reptill(i,0,r-1) ans=ans*(n-i)/(i+1);
	return ans;
}
template<typename type>  unsigned long long fact(type x){ ull ans=1; for(type i=1;i<=x;i++){ ans*=i;        /*ans%=MOD;   /Optional*/ } return ans; }

inline void FAST_IO(){ios_base::sync_with_stdio(false);}



#define SIZE (int(1e6)+1)
#define MOD
#define debug
#define MAX1
#define MAX2

//#define Online_judge


class Node
{
	public:

	ll rangeSum;
	ll dues;

	Node(ll rs=0,ll d=0)
	{
		rangeSum=rs;
		dues=d;
	}
};
//Node tree[4*SIZE];
vector<Node> tree;



/*
void build(int l,int r,int v)
{
	if(l==r)
	{
		tree[v].rangeSum=arr[l];
		return ;
	}
	int mid=(l+r)>>1;

	build(l,mid,2*v);
	build(mid+1,r,2*v+1);

	tree[v].rangeSum= tree[2*v].rangeSum +tree[2*v+1].rangeSum;

	tree[v].len=r-l+1;
}

*/

ll query(int ql,int qr,int l,int r,int v)
{
	if(tree[v].dues)		///Update the current node if any dues are remaining
	{
		tree[v].rangeSum+= tree[v].dues*(r-l+1);
		tree[2*v].dues+=tree[v].dues;
		tree[2*v+1].dues+=tree[v].dues;		///propagating lazily
		tree[v].dues=0;
	}

	if(ql>r or qr<l)		///No overlap
		return 0;

	if(ql<=l and qr>=r)	///total overalp
	{
		return tree[v].rangeSum;
	}

	int mid=(l+r)>>1;

	ll leftsum=query(ql,qr,l,mid,2*v);
	ll ritsum= query(ql,qr,mid+1,r,2*v+1);

	tree[v].rangeSum = tree[2*v].rangeSum+tree[2*v+1].rangeSum;
	return leftsum+ritsum;
}

ll Update(int ql,int qr,int l,int r,int v,ll by)
{
	//cout<<"Called for "<<l<<" "<<r<<"\n";
	if(tree[v].dues)		///Update the current node if any dues are remaining
	{
		tree[v].rangeSum+= tree[v].dues*(r-l+1);

		tree[2*v].dues+= tree[v].dues;
		tree[2*v+1].dues+=tree[v].dues;		///propagating lazily

		tree[v].dues=0;
	}

	if(ql>r or qr<l)		///No overlap
	{
		return tree[v].rangeSum;
	}

	if(ql<=l and qr>=r)	///complete overlap
	{
		tree[v].rangeSum += by * (r-l+1);

		tree[2*v].dues+=by;
		tree[2*v+1].dues+=by;

		return tree[v].rangeSum;
	}

	int mid= (l+r)>>1;

	ll leftsum= Update(ql,qr,l,mid,2*v,by);
	ll ritsum=  Update(ql,qr,mid+1,r,2*v+1,by);

	return tree[v].rangeSum = leftsum+ritsum;

}


int main()
{

FAST_IO();
ifstream cin("/home/aditya/Documents/ip");

	int t;

	cin>>t;

while(t--)
{

	tree=vector<Node>(4*SIZE,Node(0,0));

//	ofstream cout("/home/aditya/Documents/op");


	int n,q;
	cin>>n>>q;
	//build(1,n,1);
/*

	//ll tmp=ceil(log2(n))+1;
	//ll leaf=pow(2,tmp)-1;

	for(ll i=1;i<=leaf;i++)
	{
		tree[i].dues=0;
		tree[i].rangeSum=0;

	}
*/

#ifdef debug1

	ll leaf=ceil(log2(n))+1;
	ll p=pow(2,leaf)-1;

	for(int i=1;i<=p;i++)	cout<<"tree["<<i<<"]= "<<tree[i].rangeSum<<" "<<tree[i].dues<<"\n";
#endif

	ll by;
	int l,r;

	while(q--)
	{

		int qtype;



		cin>>qtype>>l>>r;

		if(qtype)
		{
			cout<<query(l,r,1,n,1)<<"\n";
		}
		else
		{
			cin>>by;
			Update(l,r,1,n,1,by);
		}

		//cout<<"For "<<l<<" "<<r<<" "<<by<<"\n"; for(int i=1;i<=leaf;i++)	cout<<"tree["<<i<<"]= "<<tree[i].dues<<" "<<tree[i].rangeSum<<"\n"; newl;
	}

	//cout<<"For "<<l<<" "<<r<<" "<<by<<"\n"; for(int i=1;i<=leaf;i++)	cout<<"tree["<<i<<"]= "<<tree[i].dues<<" "<<tree[i].rangeSum<<"\n"; newl;
}


}


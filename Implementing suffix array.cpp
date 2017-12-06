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
	#define newl cout<<"\n"
	#define FILL(A,value) memset(A,value,sizeof(A))


	#define whole(x) x.begin(),x.end()
	#define pb push_back
	#define get(tp_name,x) (get<x>(tp_name))   ///to access tuple(i)


	using namespace std;


	#define F first
	#define S second



	///learning corner

	///vector< vector<int> > costs(N, vector<int>(M, 0));   //NxM 2d preinitialized(0) vector



	typedef pair<int,int> ii;
	typedef vector<ii> vii;



	inline bool inc_range(int x,int y,int z) { return ((x>=y)&&(x<=z)); }
	inline bool ex_range(int x,int y,int z) { return ((x>y)&&(x<z)); }
	inline bool is_either(int x,int y,int z) { return ((x==y)||(x==z)); }

	//maths
	#define PI acos(-1)

	#define INTmax numeric_limits<int>::max()
	#define LLmax numeric_limits<ll>::max()
	#define ULLmax numeric_limits<ull>::max()

	#define INTmin numeric_limits<int>::min()


	typedef priority_queue<ii,vector<ii>, greater<ii> > P_Queue;             ///priority queue contianing ii (having vector<ii> as underlying container) with greater as functor
																			///		heapify on the basis of comparisons of  ii.first  values

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

	template<class type>
	type ncr(type n,type r)
	{  	assert(n>=r);
		type ans=1,i;
		if(n==r) return 1; if(r==1) return n; if(r>(n-r)) r=n-r;
		reptill(i,0,r-1) ans=ans*(n-i)/(i+1);
		return ans;
	}

	inline void FAST_IO(){ios_base::sync_with_stdio(false);}



	#define SIZE 1200+1
	#define MOD
	#define debug
	#define MAX1
	#define MAX2

	//#define Online_judge
	int SA[SIZE];

	int Rank[11][SIZE];

	ll power[11];

	struct Tuple
	{

		int indx;
		int fr;
		int nr;

		Tuple()
		{
			indx=-1;
			fr=-1;
			nr=-1;

		}

	}arr[SIZE];

	bool _comp(Tuple a,Tuple b)
	{
		return (a.fr==b.fr)?(a.nr<b.nr):(a.fr<b.fr);
	}

	void build_suffarr(int len)
	{
		int i,j;

		for(i=1;power[i-1]<len;i++)
		{

			for(int j=1;j<=len;j++)
			{
				arr[j].indx=j;

				arr[j].fr=Rank[i-1][j];

				arr[j].nr=(j+power[i-1]>len)? -1 : Rank[i-1][j+power[i-1]];

			}

			sort(arr,arr+len+1,_comp);

			for(int j=1;j<=len;j++)
			{
				int k=arr[j].indx;   ///in this loop we are gonna decide the ranks of the suffixes when sorted by 2^(i) chars

				Rank[i][k]=((j>1 and arr[j].fr==arr[j-1].fr and arr[j].nr==arr[j-1].nr ) ? Rank[i][arr[j-1].indx]:j);
				//cout<<"Rank "<<k<<" - "<<Rank[i][k]<<"\n";
			}
		}

		for(int j=1;j<=len;j++)
		{
			SA[Rank[i-1][j]]=j;
		}



	}


	int _lcp(int i,int j,int n)
	{

		if(i==j)
		 return n-i+1;

		int ans=0,len=n-min(i,j)+1;

		for(int x=log2(len); x>=0 ; x--)
		{
			if(Rank[x][i]==Rank[x][j])  //Rank[x][i]-> when sorted by 2^(x) chars
			{

				ans+=power[x];

				i+=power[x];
				j+=power[x];

			}
		}

		return ans;
	}

	int main()
	{
		FAST_IO();

		#ifndef ONLINE_JUDGE
			ifstream cin("/home/aditya/Documents/ip");
		#endif

		int t;
		cin>>t;


		int i;
		reptill(i,0,log2(1200)+1)
		 power[i]=(1<<i);

		while(t--)
		{

		string s;
		cin>>s;
		int len=s.size(),i,j;

		ll tot=len*(len+1)/2;



		reptill(i,1,len)
		{
			Rank[0][i]=s[i-1]-((s[i-1]>=97 and s[i-1]<=122)?'a':'A')+1;
		}

		build_suffarr(len);

		int lcp;

		reptill(i,2,len)
		{
			lcp=_lcp(SA[i],SA[i-1],len);
			//cout<<"lcp of "<<s.substr(SA[i]-1)<<" , "<<s.substr(SA[i-1]-1)<<"= "<<lcp<<"\n";
			tot-=lcp;
		}

		cout<<tot<<"\n";

		}

	}


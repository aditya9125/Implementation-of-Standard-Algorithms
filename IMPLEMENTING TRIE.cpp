///Another good version is implemented in the solution SP-ADA AND INDEXING

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


using namespace std;


#define F first
#define S second

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



#define SIZE int(2e3)+1
#define MOD
#define debug


//#define Online_judge

inline int f(char ch)
{
	return ch-'a';
}



struct Trie_node{

	int pref;
	bool is_end;

	Trie_node* childs[27];

	Trie_node() 		///constructor
	{

		pref=0;

		is_end=false;

		for(int i=0;i<27;i++)
		  childs[i]=nullptr;
	}


}*root;



int RemoveWord(string word)  ///does'nt remove the nodes, instead just change the flag of the word to "is_not_end",which removes the word hypothetically
{
	char ch;

	Trie_node* curr=root;

	for(int i=0;i<word.size();i++)
	{
		ch=word[i];

		if(curr->childs[f(ch)])
		{
			curr=curr->childs[f(ch)];

			if(i+1==word.size())
			{
				curr->is_end=false;
			}

		}
		else return -1;
	}

}



bool iswholeword(string targ) //To change this function to prefixsearch initialize iswhole=true ,loop over the string untill all the characters arepresent
{														///if any one is missing return false else return iswhole and remove if(i+1==s.size)..{}
	bool iswhole=false;
	char ch;int i;


	Trie_node* curr=root;

	rep(i,0,targ.size())
	{

		ch=targ[i];

		if(curr->childs[f(ch)])
		{

			curr=curr->childs[f(ch)];

			if(i+1==targ.size())        ///Remove this for prefix based search
			{
				return (curr->is_end);
			}
		}
		else return false;
	}
}


int countPrefixes(Trie_node* head,string const& targ)
{

	Trie_node* curr=head;

	char ch;
	int i;

	rep(i,0,targ.size())
	{

		ch=targ[i];

		if(curr->childs[f(ch)])
		{
			curr=curr->childs[f(ch)];
		}
		else return 0;
	}

	return curr->pref;

}

int main()
{
	FAST_IO();

	ifstream cin("ip");

	root = new Trie_node();

	//cout<<(root->prefcnt)<<" "<<root->is_end<<endl;


	int n,k,i,j;
	cin>>n;

	Trie_node* curr=nullptr;


	while(n--)
	{


		string s;
		cin>>s;
		char ch;

		curr=root;

		rep(i,0,s.size())   ///Add word
		{
			ch=s[i];

			if(!curr->childs[f(ch)])
			{
				curr->childs[f(ch)]=new Trie_node();
			}

			curr->pref+=1;

			curr=curr->childs[f(ch)];

			if(i==(s.size()-1))
				curr->is_end=true,curr->pref+=1;
		}

    }

	//if(isword("ha")) cout<<"YES Is a whole word\n";
	//else cout<<"NOT a whole word\n";
	//cout<<countPrefixes(root,"man");

		if(RemoveWord("hacken")!=-1)
			cout<<"Word removed\n";
		else cout<<"Word doesn't exist\n";



}


#include<bits/stdc++.h>
using namespace std;


#define ll         long long
#define lll        __int128_t
#define imax        __INT_MAX__
#define imin        __WINT_MIN__
#define fast_code       ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb         push_back
#define vi         vector<int>
#define r(a)      ll a; cin>>a;
#define rr(a,b)    ll a,b; cin>>a>>b;
#define rrr(a,b,c)     ll a,b,c; cin>>a>>b>>c;
#define vll(v,n)   vector<ll> v(n); f(i,0,n) cin>>v[i];
#define aa(arr,n)  ll arr[n]; f(i,0,n) cin>>arr[i];
#define str(s)      string(s); cin >> (s);
#define vvll       vector<vector<ll>>
#define sz(s)      s.size()
#define M        1000000007
#define ff         first
#define ss         second
#define inf        10e15
#define all(x)         (x).begin(), (x).end()
#define pii        pair<int, int>
#define mii        map<int,int>
#define fill(a,x) 	for (auto &it : a) it=x;
#define mkp 		make_pair
#define ins 		insert
#define setbits 	__builtin_popcountll
#define gtr 		greater <ll>()
#define ub 		upper_bound
#define lb 		lower_bound
#define fs(x,y)    fixed<<setprecision(y)<<x
#define lcm(a,b)   (a/__gcd(a,b))*b
#define prnt(a)    for(auto e:a)cout<<e<<" ";
const          int N = 1e5 + 5;

int dx[]={0,1,0,-1};    //{0,1,1,1,0,-1,-1,-1};
int dy[]={1,0,-1,0};    //{1,1,0,-1,-1,-1,0,1};

ll gcdll(ll a, ll b, ll &x, ll &y) 	{ if (b==0) { x=1; y=0; return a; } ll x1,y1; ll g=gcdll(b,a%b,x1,y1); x=y1; y=x1-y1*(a/b); return g; }
ll powll(ll a, ll b, ll m=M) 		{ a = a % m; ll res = 1; while (b) { if (b&1) { res=(res * a) % m; } a=(a * a) % m; b>>=1; } return res; }
ll sqrtll(ll n) 			{ ll lo=0,hi=1e9+7; while (hi-lo>1) { ll m=(hi+lo)/2; if (m*m<=n) { lo=m; } else { hi=m-1; }} if (hi*hi<=n) { return hi; } return lo; }


template<typename T> 	istream& operator >>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in;}		// cin>>v; => Works
template<typename T> 	ostream& operator <<(ostream &out, const vector<T> &v) { for (auto &x : v) out << x << ' '; return out;}		// cout<<v; => Works



#define rep(i,a,b) for(int i=a;i<b;i++)

ll power(ll a,ll b){ll ans=1;while(b>0){if(b&1){ans*=a;ans%=M;}a*=a;a%=M;b>>=1;}return ans;}
ll inv(ll x){return power(x,M-2);}
ll mult(ll a,ll b){return ((a%M)*(b%M))%M;}
ll divide(ll a,ll b){return mult(a,inv(b));}
// int fact[N];
// void fact_precal(){fact[0]=1;rep(i,1,N){fact[i]=mult(fact[i-1],i);}}
// ll nCr(ll n,ll r){return divide(fact[n],mult(fact[n-r],fact[r]));}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    int floor=INT_MIN,ceil=INT_MAX;
    for(int i=0;i<n;i++){

        if(arr[i]==x){
            floor=x;
            ceil=x;
            break;
        }

        if(arr[i]<=x && arr[i]>=floor){
            floor=arr[i];
            
        }
        else if(arr[i]>=x && arr[i]<=ceil){
            ceil=arr[i];
        }
    }
    pair<int,int>ans;
    if(floor==INT_MIN){
        ans={-1,ceil};
    }
    else if(ceil==INT_MAX){
        ans={floor,-1};
    }
    
    else{
        ans={floor,ceil};
    }
    
    return ans;
}

void solve(){

    int arr[]={42,48};
    int n=2,k=42;
    pair<int,int>ans=getFloorAndCeil(arr,n,k);
    cout<<ans.first<<" "<<ans.second<<"\n";
    
}

int32_t main(){

    fast_code

//    #ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//    #endif

    int t;
         t=1;
    cin>>t;
    while(t--){
         solve();
    }
     
return 0;
}
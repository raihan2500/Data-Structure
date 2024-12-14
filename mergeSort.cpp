#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using u64 = uint64_t;
using u128 = __uint128_t;

#define int                long long

#define yes                cout<<"YES\n"
#define no                 cout<<"NO\n"
#define nl                 cout<<"\n"
#define endl               "\n"

#define lin(n)             int n;cin>>n;
#define vin                vector<int>
#define pr                 pair<int, int>
#define pb(n)              push_back(n)
#define pp                 pop_back()
#define ppfr(v)            v.erase(v.begin());
#define all(x)             x.begin(),x.end()

#define fi                 first
#define se                 second

#define forn(i,e)          for(int i=0;i<e;i++)
#define Forn(i,e)          for(int i=1;i<=e;i++)
#define rforn(i,s)         for(int i=s-1;i>=0;i--)
#define print(arr)         for(auto x: arr)cout<<x<<" ";nl;
#define mprint(mp)         for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
template <typename T>      using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const long long INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 100;

int dpcnt;

vin mrgSrt(vin v){
    int n = v.size();
    dpcnt += 2 * n;
    int mid = n / 2;
    vin rht, lft;
    rht.assign(v.begin(), v.begin() + mid);
    lft.assign(v.begin() + mid, v.end());

    int i = 0, j = 0, m;
    n = rht.size();
    m = lft.size();
    if(n > 1)rht = mrgSrt(rht);
    if(m > 1)lft = mrgSrt(lft);

    v.clear();
    for(; i < n and j < m;){
        if(rht[i] <= lft[j]){
            v.push_back(rht[i++]);
        }else{
            v.push_back(lft[j++]);
        }
    }
    for(; i < n; i++)v.push_back(rht[i]);
    for(; j < m; j++)v.push_back(lft[j]);
    
    return v;
}


int32_t main(){
    fast_in_out;
    lin(n);
    vin v(n);
    forn(i,n)cin >> v[i];
    // mrgSrt(v);
    // mergeSort(v, 0, n - 1);
    print(mrgSrt(v));
    cout << dpcnt << endl;   

    // for(int i = 100; i >= 0; i--)cout << i <<" ";
}
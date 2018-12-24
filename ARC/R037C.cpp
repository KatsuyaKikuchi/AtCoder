#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> pll;

#define FOR(i,n,m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i,n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N,K;
ll a[30005],b[30005];

//! n以下の計算結果が幾つ存在するか
ll num(ll n)
{
    ll sum=0;
    REP(i,N)
    {
        //! a[i]*b[ok]がn以下となる最大のokを求める
        ll ok =-1,ng=N;
        while(abs(ng-ok)>1)
        {
            ll mid = (ok+ng)/2;
            if(a[i]*b[mid]<=n)
            {
                ok=mid;
            }
            else
            {
                ng=mid;
            }
        }
        sum+=ok+1;
    }
    return sum;
}

int main()
{
    cin>>N>>K;
    REP(i,N)
    {
        cin>>a[i];
    }
    REP(i,N)
    {
        cin>>b[i];
    }
    sort(a,a+N);
    sort(b,b+N);

    ll ok = a[0]*b[0]-1,ng = a[N-1]*b[N-1]+1;
    while(abs(ng-ok)>1)
    {
        ll mid =(ok+ng)/2;
        ll n =num(mid);
        if(n<K)
        {
            ok=mid;
        }
        else
        {
            ng=mid;
        }
    }
    cout<<ok+1<<endl;
    return 0;
}
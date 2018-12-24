#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> pll;

#define FOR(i,n,m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i,n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N,M;
ll P[1005];
ll S[1002005];

//! M点以下最大得点
ll getMax()
{
    //! M以下の最大得点
    ll max=0;
    REP(i,N+1)
    {
        if(P[i]>M)break;
        ll k =P[i];
        REP(j,N+1)
        {
            if(P[j]+k>M)break;
            ll p =k+P[j];

            int ok =0,ng=(N+1)*(N+1);
            while(abs(ng-ok)>1)
            {
                int mid =(ok+ng)/2;
                if(p+S[mid]<=M)
                {
                    ok=mid;
                }
                else
                {
                    ng=mid;
                }
            }
            max =std::max(max,p+S[ok]);
        }
    }
    return max;
}

int main()
{
    cin>>N>>M;
    REP(i,N)
    {
        cin>>P[i];
    }
    P[N]=0;
    REP(i,N+1)
    {
        REP(j,N+1)
        {
            S[i*(N+1)+j]=P[i]+P[j];
        }
    }
    sort(P,P+N+1);
    sort(S,S+(N+1)*(N+1));
    cout<<getMax()<<endl;
    return 0;
}
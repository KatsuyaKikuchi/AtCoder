#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int H, W;
int A[50][50];

ll sum(int th, int tw)
{
    ll s = 0;
    REP(h, H)
    {
        REP(w, W)
        {
            s += std::min(abs(h - th), abs(w - tw)) * A[h][w];
        }
    }
    return s;
}
int main()
{

    cin >> H >> W;
    REP(h, H)
    {
        REP(w, W)
        {
            cin >> A[h][w];
        }
    }

    ll min = INF;
    REP(h, H)
    {
        REP(w, W)
        {
            //! h,wを幹線道路をとして選ぶ
            min = std::min(min, sum(h, w));
        }
    }
    cout << min << endl;
    return 0;
}
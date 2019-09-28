#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[105];

int main()
{
    ll N, C;
    cin >> N >> C;
    REP(i, N)
    {
        cin >> A[i];
        A[i]--;
    }

    ll min = INF;
    REP(i, 10)
    {
        REP(j, 10)
        {
            if (i == j)
                continue;
            //! 偶数枚目をiで、奇数枚目をjで塗る
            ll m = 0;
            REP(a, N)
            {
                if (a % 2 == 0 && A[a] != i)
                    m++;
                else if (a % 2 == 1 && A[a] != j)
                    m++;
            }
            min = std::min(min, m);
        }
    }
    cout << min * C << endl;
    return 0;
}
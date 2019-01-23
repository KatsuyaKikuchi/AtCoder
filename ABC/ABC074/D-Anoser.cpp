#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[305][305];

//! D問題別解
int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        REP(j, N)
        {
            cin >> A[i][j];
        }
    }

    ll sum = 0;
    REP(i, N)
    {
        FOR(j, N, i + 1)
        {
            //! i->jにいくのに近い道があるか
            bool e = false;
            REP(k, N)
            {
                if (k == i || k == j)
                    continue;
                if (A[i][j] > A[i][k] + A[j][k])
                {
                    cout << -1 << endl;
                    return 0;
                }

                if (A[i][j] == A[i][k] + A[j][k])
                {
                    e = true;
                    break;
                }
            }
            if (!e)
                sum += A[i][j];
        }
    }
    cout << sum << endl;
    return 0;
}
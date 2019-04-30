#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e18;

ll A[100005];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }

    ll min = INF;
    {
        //! 奇数番目をマイナス
        ll sum = 0;
        ll m = 0;
        REP(i, N)
        {
            sum += A[i];
            if (i % 2 == 0)
            {
                if (sum >= 0)
                {
                    m += sum + 1;
                    sum = -1;
                }
            }
            else
            {
                if (sum <= 0)
                {
                    m += abs(sum) + 1;
                    sum = 1;
                }
            }
        }
        min = std::min(m, min);
    }
    {
        //! 奇数番目をpurasu
        ll sum = 0;
        ll m = 0;
        REP(i, N)
        {
            sum += A[i];
            if (i % 2 == 0)
            {
                if (sum <= 0)
                {
                    m += abs(sum) + 1;
                    sum = 1;
                }
            }
            else
            {
                if (sum >= 0)
                {
                    m += abs(sum) + 1;
                    sum = -1;
                }
            }
        }
        min = std::min(m, min);
    }
    cout << min << endl;
    return 0;
}
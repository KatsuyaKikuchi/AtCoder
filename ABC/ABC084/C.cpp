#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll C[100005], S[100005], F[100005];
int main()
{
    int N;
    cin >> N;
    REP(i, N - 1)
    {
        cin >> C[i] >> S[i] >> F[i];
    }

    REP(i, N)
    {
        ll t = 0;
        FOR(j, N - 1, i)
        {
            //! 待つ時間
            if (S[j] - t >= 0)
            {
                t += (S[j] - t);
            }
            else
            {
                t += (F[j] - abs(S[j] - t) % F[j]) % F[j];
            }
            t += C[j];
        }
        cout << t << endl;
    }
    return 0;
}
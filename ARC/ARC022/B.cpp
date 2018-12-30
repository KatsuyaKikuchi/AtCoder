#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int A[100005];
bool U[100005];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }

    ll max = 0;
    int pi = 0;
    REP(i, N)
    {
        if (U[A[i]])
        {
            FOR(j, i, pi)
            {
                U[A[j]] = false;
                if (A[j] == A[i])
                {
                    pi = j + 1;
                    break;
                }
            }
        }
        U[A[i]] = true;
        max = std::max(i - pi + 1, max);
    }
    cout << max << endl;
    return 0;
}
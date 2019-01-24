#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[100005];
ll B[100005];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    REP(i, N)
    {
        cin >> B[i];
    }

    sort(A, A + N);
    sort(B, B + N);
    A[N] = INF;
    B[N] = INF;
    ll sum = 1;

    int pi = 0, wi = 0;
    int np = 0, nw = 0;
    while (pi < N || wi < N)
    {
        if (A[pi] < B[wi])
        {
            pi++;
            if (nw > np)
            {
                sum *= nw;
                nw--;
            }
            else
            {
                np++;
            }
        }
        else
        {
            wi++;
            if (np > nw)
            {
                sum *= np;
                np--;
            }
            else
            {
                nw++;
            }
        }
        sum %= MOD;
    }

    cout << sum << endl;
    return 0;
}
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
int B[100005];
int C[100005];

int main()
{
    ll N, K;
    cin >> N >> K;
    bool w = false;
    REP(i, K)
    {
        cin >> A[i];
        if (A[i] == 0)
            w = true;
        else
            B[A[i]] = C[A[i]] = 1;
    }

    FOR(i, N + 1, 1)
    {
        if (B[i] != 0)
            B[i] += B[i - 1];
        if (C[N - i] != 0)
            C[N - i] += C[N + 1 - i];
    }

    ll max = 0;
    REP(i, N + 1)
    {
        ll t = 0;
        if (w)
        {
            if (i > 0)
                t += B[i - 1];
            if (t < N)
                t += C[i + 1];
            t++;
        }
        else
            t = B[i];
        max = std::max(max, t);
    }
    cout << max << endl;
    return 0;
}
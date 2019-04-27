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

ll gcd(ll a, ll b)
{
    if (b > a)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    sort(A, A + N);
    int mi = 0;
    REP(i, N)
    {
        if (gcd(A[0], A[mi]) > gcd(A[0], A[i]))
            mi = i;
    }
    if (mi == 0)
        mi = 1;

    ll max = 0;
    {
        ll m = A[1];
        FOR(i, N, 1)
        {
            m = gcd(A[i], m);
        }
        max = std::max(max, m);
    }
    {
        ll m = A[0];
        REP(i, N)
        {
            if (i == mi)
                continue;
            m = gcd(A[i], m);
        }
        max = std::max(max, m);
    }
    cout << max << endl;

    return 0;
}
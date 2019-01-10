#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[200005];
ll B[200005];

int main()
{
    ll K, N;
    cin >> N >> K;
    int n = 0;
    REP(i, N)
    {
        cin >> A[i];
        A[i]--;
        if (B[A[i]]++ == 0)
            n++;
    }
    sort(B, B + N);
    ll sum = 0;
    for (int i = 0; n > K; ++i)
    {
        sum += B[i];
        if (B[i] > 0)
            n--;
    }
    cout << sum << endl;
    return 0;
}
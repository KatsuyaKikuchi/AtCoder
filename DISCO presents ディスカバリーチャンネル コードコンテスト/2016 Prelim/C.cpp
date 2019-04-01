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
map<ll, ll> M, B;
set<ll> S, T;

ll gcd(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

int main()
{
    ll N, K;
    cin >> N >> K;
    REP(i, N)
    {
        cin >> A[i];
        A[i] = gcd(K, A[i]);
        B[A[i]]++;
        T.insert(A[i]);
        S.insert(K / A[i]);
    }
    for (auto t : T)
    {
        for (auto s : S)
        {
            if (t % s == 0)
                M[s] += B[t];
            if (s > t)
                break;
        }
    }

    ll ans = 0;
    REP(i, N)
    {
        ll d = K / A[i];
        ans += M[d];
        if (A[i] % d == 0)
            ans--;
    }
    cout << ans / 2 << endl;
    return 0;
}
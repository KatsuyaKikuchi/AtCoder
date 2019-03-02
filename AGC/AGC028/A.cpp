#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

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
    ll N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;

    ll L = N * M / gcd(N, M);
    bool e = false;
    REP(i, std::min(N, M))
    {
        if (N >= M)
        {
            if ((i * L / M) % (L / N) != 0)
                continue;
            int j = (i * L / M) / (L / N);
            if (S[j] == T[i])
                continue;
        }
        else
        {
            if ((i * L / N) % (L / M) != 0)
                continue;
            int j = (i * L / N) / (L / M);
            if (S[i] == T[j])
                continue;
        }
        e = true;
        break;
    }

    if (e)
        cout << -1 << endl;
    else
        cout << L << endl;
    return 0;
}
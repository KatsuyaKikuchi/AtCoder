#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    ll s = 0;
    ll z = 0, o = 0;
    ll n = 0;
    REP(i, N - 1)
    {
        if (S[i] == S[i + 1])
            s++;
        else
        {
            n++;
            if (S[i] == 'R')
                z++;
            if (S[i] == 'L')
                o++;
        }
    }

    n = (n + 1) / 2;

    if (n <= K)
    {
        s = N - 1;
    }
    else
    {
        s += 2 * K;
    }
    cout << s << endl;
    return 0;
}
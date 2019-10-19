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
    string S;
    ll K;
    cin >> S >> K;
    string T = S + S;
    ll odd = 0, even = 0;
    int t = 0;
    for (int i = S.length() - 1; i >= 0; --i)
    {
        t++;
        if (i > 0 && S[i] != S[i - 1])
            break;
    }
    int s = 0;
    for (int i = 0; i < S.length(); ++i)
    {
        s++;
        if (i < S.length() - 1 && S[i] != S[i + 1])
            break;
    }

    FOR(i, T.length(), 1)
    {
        if (T[i - 1] == T[i])
        {
            if (i < S.length())
            {
                odd++;
            }
            else
            {
                even++;
            }
            T[i] = '#';
        }
    }

    ll ans = (K / 2LL) * even + ((K / 2LL) + (K % 2LL)) * odd;
    if (S.length() != t && t % 2 == 1 && s % 2 == 1)
    {
        K--;
        ans = odd + K * even;
    }
    cout << ans << endl;
    return 0;
}
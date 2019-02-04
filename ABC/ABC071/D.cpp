#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string S[2];

int main()
{
    int N;
    cin >> N;
    REP(i, 2)
    {
        cin >> S[i];
    }

    ll a = 3;
    bool c = true; //! 前回が縦
    if (S[0][0] != S[1][0])
    {
        a = 6;
        c = false;
    }
    FOR(i, N, 1)
    {
        if (S[0][i] == S[0][i - 1])
            continue;

        if (S[0][i] == S[1][i])
        {
            //! 縦
            if (c)
                a *= 2;
            c = true;
        }
        else
        {
            if (c)
                a *= 2;
            else
                a *= 3;
            c = false;
        }
        a %= MOD;
    }
    cout << a << endl;
    return 0;
}
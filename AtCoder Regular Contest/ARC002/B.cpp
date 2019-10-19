#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool solve(ll y)
{
    if (y % 400 == 0)
        return true;
    if (y % 100 == 0)
        return false;
    if (y % 4 == 0)
        return true;
    return false;
}

ll num(char c)
{
    return c - '0';
}

ll D[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    string S;
    cin >> S;
    ll y = num(S[0]) * 1000 + num(S[1]) * 100 + num(S[2]) * 10 + num(S[3]);
    ll m = num(S[5]) * 10 + num(S[6]);
    ll d = num(S[8]) * 10 + num(S[9]);

    if (solve(y))
        D[1]++;
    FOR(i, 3001, y)
    {
        FOR(j, 13, 1)
        {
            if (i == y && j < m)
                continue;
            FOR(k, D[j - 1] + 1, 1)
            {
                if (j == m && k < d)
                    continue;

                if (i % (j * k) == 0)
                {
                    cout << setfill('0') << right << setw(4) << i;
                    cout << "/";
                    cout << setfill('0') << right << setw(2) << j;
                    cout << "/";
                    cout << setfill('0') << right << setw(2) << k;
                    cout << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
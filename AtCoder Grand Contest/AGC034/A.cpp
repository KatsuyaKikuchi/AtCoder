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
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    A--;
    B--;
    C--;
    D--;
    string S;
    cin >> S;

    bool f = true;
    if (C > D)
    {
        bool e = false;
        //! すれ違う必要あり
        FOR(i, D + 1, B)
        {
            if (S[i] == '.' && S[i + 1] == '.' && S[i - 1] == '.')
                e = true;
        }
        f = e;
    }
    //! AがCに行ける？
    FOR(i, C, A)
    {
        if (S[i] == '#' && S[i + 1] == '#')
            f = false;
    }
    FOR(i, D, B)
    {
        if (S[i] == '#' && S[i + 1] == '#')
            f = false;
    }

    if (f)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
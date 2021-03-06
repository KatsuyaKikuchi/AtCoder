#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int N;
string S;

//! sが書かれている看板からSの看板を作れるか
bool solve(string s)
{
    REP(i, s.length())
    {
        if (s[i] != S[0])
            continue;

        //! j文字飛びで看板が作れるか調べる
        FOR(j, s.length(), 1)
        {
            if (i + (S.length() - 1) * j >= s.length())
                break;
            bool f = true;
            REP(k, S.length())
            {
                if (s[i + k * j] != S[k])
                {
                    f = false;
                    break;
                }
            }
            if (f)
                return true;
        }
    }
    return false;
}

int main()
{
    cin >> N >> S;
    int n = 0;
    REP(i, N)
    {
        string s;
        cin >> s;
        if (solve(s))
            n++;
    }
    cout << n << endl;
    return 0;
}
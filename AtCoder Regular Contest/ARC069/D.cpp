#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N;
string S;
//! 1番目がa,2番目がbとなるような並べ方が存在するかどうか
bool solve(int a, int b)
{
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    FOR(i, N - 1, 1)
    {
        if (v[i] == 0)
        {
            //! 狼
            if (S[i] == 'o')
                v.push_back((v[i - 1] + 1) % 2);
            else
                v.push_back(v[i - 1]);
        }
        else
        {
            //! 羊
            if (S[i] == 'o')
                v.push_back(v[i - 1]);
            else
                v.push_back((v[i - 1] + 1) % 2);
        }
    }

    //! 0とN-1の生合成が取れているか?
    if (S[0] == 'o')
    {
        if (v[0] == 0)
        {
            if (v[1] == v[N - 1])
                return false;
        }
        else if (v[1] != v[N - 1])
            return false;
    }
    else
    {
        if (v[0] == 0)
        {
            if (v[1] != v[N - 1])
                return false;
        }
        else if (v[1] == v[N - 1])
            return false;
    }

    if (S[N - 1] == 'o')
    {
        if (v[N - 1] == 0)
        {
            if (v[0] == v[N - 2])
                return false;
        }
        else if (v[0] != v[N - 2])
            return false;
    }
    else
    {
        if (v[N - 1] == 0)
        {
            if (v[0] != v[N - 2])
                return false;
        }
        else if (v[0] == v[N - 2])
            return false;
    }

    REP(i, N)
    {
        if (v[i] == 0)
            cout << 'W';
        else
            cout << 'S';
    }
    cout << endl;
    return true;
}

int main()
{
    cin >> N;
    cin >> S;
    REP(i, 2)
    {
        REP(j, 2)
        {
            if (solve(i, j))
                return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string A[1000];
ll B[15];

//! a<=b?
bool check(string a, string b)
{
    if (a.length() > b.length())
        return false;
    else if (a.length() < b.length())
        return true;

    REP(i, a.length())
    {
        ll n = B[a[i] - '0'];
        ll m = B[b[i] - '0'];
        if (n == m)
            continue;
        if (n < m)
            return true;
        else
            return false;
    }
    return true;
}

int main()
{
    REP(i, 10)
    {
        ll b;
        cin >> b;
        B[b] = i;
    }

    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = N - 1; j > i; --j)
        {
            if (!check(A[j - 1], A[j]))
                swap(A[j - 1], A[j]);
        }
    }

    REP(i, N)
    {
        cout << A[i] << endl;
    }
    return 0;
}
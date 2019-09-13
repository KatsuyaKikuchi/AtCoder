#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string S[105];
bool check(string a, string b)
{
    ll n = a.length(), m = b.length();
    REP(i, std::min(n, m))
    {
        if (a[n - 1 - i] > b[m - 1 - i])
            return true;
        if (a[n - 1 - i] < b[m - 1 - i])
            return false;
    }
    return a.length() > b.length();
}

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> S[i];
    }

    REP(i, N)
    {
        for (int j = 0; j < N - i - 1; ++j)
        {
            if (check(S[j], S[j + 1]))
                swap(S[j], S[j + 1]);
        }
    }

    REP(i, N)
    {
        cout << S[i] << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<char, char> pcc;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pcc C[200005];
string S;
ll N, Q;

bool checkL(ll n)
{
    REP(i, Q)
    {
        if (C[i].first == S[n])
        {
            if (C[i].second == 'L')
                n--;
            else
                n = std::min(n + 1, N - 1);
            if (n < 0)
                return true;
        }
    }
    return false;
}
bool checkR(ll n)
{
    REP(i, Q)
    {
        if (C[i].first == S[n])
        {
            if (C[i].second == 'L')
                n = std::max(0LL, n - 1);
            else
                n++;
            if (n > N - 1)
                return true;
        }
    }
    return false;
}

int main()
{
    cin >> N >> Q;
    cin >> S;
    REP(i, Q)
    {
        cin >> C[i].first >> C[i].second;
    }

    ll left = 0;
    {
        //! 左に落ちる最大値
        ll ok = 0, ng = N;
        while (abs(ok - ng) > 1)
        {
            ll mid = (ok + ng) / 2;
            if (checkL(mid))
                ok = mid;
            else
                ng = mid;
        }
        if (ok == 0 && !checkL(0))
            ok = -1;
        left = ok + 1;
    }
    ll right = 0;
    {
        //! 左に落ちる最大値
        ll ok = N - 1, ng = -1;
        while (abs(ok - ng) > 1)
        {
            ll mid = (ok + ng) / 2;
            if (checkR(mid))
                ok = mid;
            else
                ng = mid;
        }
        if (ok == N - 1 && !checkR(N - 1))
            ok = N;
        right = N - ok;
    }
    cout << N - std::min(N, left + right) << endl;
    return 0;
}
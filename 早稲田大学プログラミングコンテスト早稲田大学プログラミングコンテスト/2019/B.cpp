#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int H, W;
int A[105][105];

int get(int n)
{
    if (n == 9)
        return 3;
    if (n == 8)
        return 2;
    if (n == 7 || n == 6)
        return 1;
    return 0;
}

string sets(ll n)
{
    string s = "Yes ";
    s.push_back((char)(n + '0'));
    return s;
}

string solve()
{
    bool can = false;
    int max = 0;
    REP(i, H)
    {
        REP(j, W)
        {
            if (A[i][j] == 5)
                can = true;
            max = std::max(max, A[i][j]);
        }
    }
    if (max == 0)
    {
        return sets(0);
    }
    if (!can)
    {
        return "No";
    }
    if (H > 1 && W > 1)
    {
        return sets(get(max) + 1);
    }

    ll min = INF;
    if (H == 1)
    {
        ll m = INF;
        REP(i, W)
        {
            if (A[0][i] == 5)
            {
                int lm = 0;
                int rm = 0;
                for (int j = 0; j < i; ++j)
                    lm = std::max(lm, A[0][j]);
                for (int j = i + 1; j < W; ++j)
                    rm = std::max(rm, A[0][j]);

                ll sum = get(lm) + get(rm) + 1;
                m = std::min(m, sum);
            }
        }
        min = std::min(min, m);
    }
    else
    {
        ll m = INF;
        REP(i, H)
        {
            if (A[i][0] == 5)
            {
                int lm = 0;
                int rm = 0;
                for (int j = 0; j < i; ++j)
                    lm = std::max(lm, A[j][0]);
                for (int j = i + 1; j < H; ++j)
                    rm = std::max(rm, A[j][0]);

                ll sum = get(lm) + get(rm) + 1;
                m = std::min(m, sum);
            }
        }
        min = std::min(min, m);
    }
    return sets(min);
}

int main()
{
    cin >> H >> W;

    REP(i, H)
    {
        REP(j, W)
        {
            cin >> A[i][j];
        }
    }

    cout << solve() << endl;
    return 0;
}
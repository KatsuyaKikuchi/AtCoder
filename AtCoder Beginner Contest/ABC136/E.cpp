#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct PrimeList
{
    PrimeList(ll n)
    {
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= n; ++i)
        {
            if (!isPrime[i])
                continue;
            mPrimeList.push_back(i);
            for (int j = i * 2; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    //! i番目の素数を取得
    int get(int i)
    {
        return mPrimeList[i];
    }

    vector<int> mPrimeList;
};

ll A[505];
vector<ll> D;

void dfs(vector<pll> p, ll n = 1, int index = 0)
{
    if (p.size() == index)
    {
        D.push_back(n);
        return;
    }

    REP(i, p[index].second + 1)
    {
        dfs(p, n, index + 1);
        n *= p[index].first;
    }
}

int main()
{
    ll N, K;
    cin >> N >> K;
    ll sum = 0;
    REP(i, N)
    {
        cin >> A[i];
        sum += A[i];
    }

    vector<pll> p;
    PrimeList pl(100000);
    REP(i, pl.mPrimeList.size())
    {
        if (sum % pl.get(i) != 0)
            continue;
        ll n = 0;
        while (sum % pl.get(i) == 0)
        {
            sum /= pl.get(i);
            n++;
        }
        p.push_back(pll(pl.get(i), n));
    }
    if (sum > 1)
        p.push_back(pll(sum, 1));

    D.clear();
    dfs(p);

    sort(D.begin(), D.end(), [](ll a, ll b) { return a > b; });
    REP(i, D.size())
    {
        vector<ll> B;
        ll d = D[i];
        REP(j, N)
        {
            B.push_back(A[j] % d);
        }
        sort(B.begin(), B.end());
        int l = 0, r = N - 1;
        ll k = 0;
        while (l < r)
        {
            if (B[l] == 0)
            {
                l++;
                continue;
            }
            if (B[r] == 0)
            {
                r--;
                continue;
            }

            ll m = std::min(B[l], d - B[r]);
            k += m;
            B[l] -= m;
            B[r] = (B[r] + m) % d;
        }
        if (k <= K)
        {
            cout << d << endl;
            break;
        }
    }
    return 0;
}
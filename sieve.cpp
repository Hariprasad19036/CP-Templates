template <int N>
struct sieve {
    array < int, N + 1 > lp;
    vector<int> primes;

    constexpr sieve() {
        lp.fill(0);
        lp[0] = -1;
        for (int i = 2; i * i <= N; i++)
            if (!lp[i])
                for (int j = i * i; j <= N; j += i)
                    if (!lp[j])
                        lp[j] = i;

        for (int i = 2; i <= N; i++)
            if (!lp[i])
                lp[i] = i;

        for (int i = 2; i <= N; i++)
            if (lp[i] == i)
                primes.push_back(i);
    }

    bool isprime(int n) {
        return lp[n] == n;
    }

    vector<pair<int, int>> prime_factors(int n) {
        vector<pair<int, int>> pf;
        while (n > 1) {
            if (pf.empty() || pf.back().first != lp[n])
                pf.push_back({lp[n], 0});

            pf.back().second++;
            n /= lp[n];
        }

        return pf;
    }

    vector<int> divisors(int n) {
        if (n == 1)
            return {1};

        int cnt = 0, temp = n;
        while (lp[temp] == lp[n])
            temp /= lp[n], cnt++;

        vector<int> others = divisors(temp), ans((cnt + 1) * others.size());
        for (int i = 0, j = 0, f = 1; i <= cnt; i++, f *= lp[n])
            for (auto div : others)
                ans[j++] = f * div;

        return ans;
    }

    vector<int> prime_divisors(int n) {
        if (n == 1)
            return {};

        vector<int> pd;
        int temp = n;
        if (lp[n] = lp[temp])
            pd.push_back(lp[n]);

        while (lp[n] == lp[temp])
            temp /= lp[n];

        for (auto i : prime_divisors(temp))
            pd.push_back(i);

        return pd;
    }
};

sieve<10 * 1000 * 1000> s;
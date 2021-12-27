template<int n>
struct modular {
    vector<int> fact, inv, invfact;

    constexpr modular() {
        fact.push_back(1);
        for (int i = 1; i <= n; i++)
            fact.push_back((fact[i - 1]*i) % modn);

        inv.push_back(1); inv.push_back(1);
        for (int i = 2; i <= n; i++)
            inv.push_back((inv[modn % i] * (modn - modn / i)) % modn);

        invfact.push_back(1); invfact.push_back(1);
        for (int i = 2; i <= n; i++)
            invfact.push_back((inv[i]*invfact[i - 1]) % modn);
    }

    int ncr(int x, int r) {
        return ((fact[x] * invfact[r]) % modn * invfact[x - r]) % modn;
    }
};

modular<1000 * 1000> mod;
long long power(int N, int R)
{
    if (R == 0)return 1;
    if (R % 2 == 0) {
        long long k = power(N, R / 2);
        return (k * k) % mod;
    }
    else {
        return (N * power(N, R - 1)) % mod;
    }
}
// Smallest Prime Factor (SPF)
// TC - O(n log log n), SC - O(n)
vector<int> Spf(int n) {
  vector<int> spf(n + 1);
  for (int i = 0; i <= n; i++) spf[i] = i;
  for (int i = 2; int64_t(i) * i <= n; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j <= n; j += i) {
        if (spf[j] == j) spf[j] = i;
      }
    }
  }
  return spf;
}

// TC - O(log b), SC - O(1)
template <typename T>
T power(T a, T b) {
  T ans = 1;
  while (b) {
    if (b & 1) {
      ans *= a;
    }
    a *= a;
    b >>= 1;
  }
  return ans;
}

// TC - O(log n), SC - O(1)
int count_divisors(int n, const vector<int>& spf) {
  int ans = 1;
  while (n > 1) {
    int p = spf[n];
    int cnt = 0;
    while (n % p == 0) {
      cnt++;
      n /= p;
    }
    ans *= (cnt + 1);
  }
  return ans;
}

// TC - O(log n), SC - O(1)
int64_t sum_divisors(int n, const vector<int>& spf) {
  int64_t sum = 1;
  while (n > 1) {
    int p = spf[n];
    int cnt = 0;
    while (n % p == 0) {
      cnt++;
      n /= p;
    }
    if (cnt == 1) {
      sum *= (1 + p);
      continue;
    }
    sum *= (power<int64_t>(p, cnt + 1) - 1) / (p - 1);
  }
  return sum;
}

// TC - O(log n), SC - O(1)
int64_t prod_divisors(int n, const vector<int>& spf) {
  if (n <= 1) {
    return n;
  }
  int cnt = count_divisors(n, spf);
  if (cnt & 1) {
    int64_t root = round(sqrt(n));
    return power<int64_t>(root, cnt);
  }
  return power<int64_t>(n, cnt / 2);
}
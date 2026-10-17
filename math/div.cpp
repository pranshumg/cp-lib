// TC - O(sqrt(n)), SC - O(d(n))
template <typename T>
vector<T> divisors(T n) {
  vector<T> d;
  for (T i = 1; int64_t(i) * i <= n; i++) {
    if (n % i == 0) {
      d.push_back(i);
      if (i != n / i) {
        d.push_back(n / i);
      }
    }
  }
  // sort(d.begin(), d.end());
  return d;
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

// TC - O(sqrt(n)), SC - O(1)
int count_divisors(int64_t n) {
  int ans = 1;
  for (int i = 2; int64_t(i) * i <= n; i++) {
    int cnt = 0;
    while (n % i == 0) {
      n /= i;
      cnt++;
    }
    ans *= (cnt + 1);
  }
  if (n > 1) ans *= 2;
  return ans;
}

// TC - O(sqrt(n)), SC - O(1)
int64_t sum_divisors(int64_t n) {
  int64_t sum = 1;
  for (int i = 2; int64_t(i) * i <= n; i++) {
    if (n % i == 0) {
      int cnt = 0;
      while (n % i == 0) {
        n /= i;
        cnt++;
      }
      if (cnt == 1) {
        sum *= (1 + i);
        continue;
      }
      sum *= (power<int64_t>(i, cnt + 1) - 1) / (i - 1);
    }
  }
  if (n > 1) sum *= (1 + n);
  return sum;
}

// TC - O(sqrt(n)), SC - O(1)
int64_t prod_divisors(int64_t n) {
  if (n <= 1) {
    return n;
  }
  int cnt = count_divisors(n);
  if (cnt & 1) {
    int64_t root = round(sqrt(n));
    return power<int64_t>(root, cnt);
  }
  return power<int64_t>(n, cnt / 2);
}
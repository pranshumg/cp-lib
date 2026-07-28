#ifndef DEBUG_H
#define DEBUG_H

#include <bits/stdc++.h>

using namespace std;

// ---------- primitive types ----------
void __print(int x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(int64_t x) { cerr << x; }
void __print(uint64_t x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '"' << x << '"'; }
void __print(const string &x) { cerr << '"' << x << '"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

// ---------- pair ----------
template<typename A, typename B>
void __print(const pair<A,B> &p) {
    cerr << '{';
    __print(p.first);
    cerr << ',';
    __print(p.second);
    cerr << '}';
}

// ---------- tuple ----------
template<typename T, size_t... I>
void __print_tuple(const T &t, index_sequence<I...>) {
    cerr << '(';
    (( __print(get<I>(t)), cerr << (I+1==sizeof...(I) ? "" : ",")), ...);
    cerr << ')';
}

template<typename... A>
void __print(const tuple<A...> &t) {
    __print_tuple(t, index_sequence_for<A...>{});
}

// ---------- generic containers ----------
template<typename T>
auto __is_container(int) -> decltype(
    begin(declval<T>()) != end(declval<T>()), void(), true_type{});

template<typename T>
false_type __is_container(...);

// enabled only for iterable containers (NOT stack/queue)
template<typename T>
typename enable_if<
    decltype(__is_container<T>(0))::value &&
    !is_same<T,string>::value
>::type
__print(const T &v) {
    cerr << '{';
    bool f = 0;
    for (auto &x : v) {
        cerr << (f ? "," : "");
        __print(x);
        f = 1;
    }
    cerr << '}';
}

// ---------- bitset ----------
template<size_t N>
void __print(const bitset<N> &b) {
    cerr << b.to_string();
}

// ---------- base ----------
void _print() { cerr << "]\n"; }

template<typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}

// ---------- macro ----------
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "] = [", _print(__VA_ARGS__)

#endif
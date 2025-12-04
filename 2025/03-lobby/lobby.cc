#include <iostream>
#include <vector>
#include <array>
#include <cctype>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <optional>

unsigned int max_2digits_num(const std::string& digits) {
    const auto m = std::max_element(digits.begin(), digits.end()-1);
    const auto k = std::max_element(m+1, digits.end());
    return 10 * (*m - '0')  + (*k - '0');
}

unsigned long long max_kdigits_num(const std::string& digits, size_t k) {
    unsigned long long res = 0;
    auto start = digits.begin();
    auto end = digits.end()-k+1;
    while(k--) {
        const auto m = std::max_element(start, end);
        res *= 10;
        res += *m - '0';
        start = m+1;
        end++;
    }
    return res;
}

unsigned long long max_kdigits_num_linear(const std::string& digits, size_t k) {
    const size_t n = digits.size();
    std::array<std::vector<size_t>, 10> digits_idxs;
    for (size_t i = n; i > 0; i--) {
        digits_idxs.at(digits[i-1] - '0').push_back(i-1);
    }
    unsigned long long num = 0;
    std::optional<size_t> last_d_idx = std::nullopt;
    while(k--) {
        bool found = false;
        for (int d = 9; !found && d >= 0; d--) {
            auto& d_idxs = digits_idxs.at(d);
            while(!d_idxs.empty() && last_d_idx.has_value() &&
                    d_idxs.back() <= last_d_idx.value()) {
                d_idxs.pop_back();
            }
            if(!d_idxs.empty() && d_idxs.back() <= n - k - 1) {
                last_d_idx = d_idxs.back();
                d_idxs.pop_back();
                num *= 10;
                num += d;
                found = true;
            }
        }
        assert(found);
    }
    return num;
}

const int N = 12;

int main() {
    unsigned long long sum = 0;
    for (std::string digits; std::getline(std::cin, digits); ) {
        if (digits.size() < N) {
            std::cerr << std::format("{} digits expected but {} found\n",
                    N, digits.size());
            return 1;
        }
        unsigned long long max = max_kdigits_num_linear(digits, N);
        sum += max;
    }
    std::cout << "Max digits sum: " << sum << '\n';
    return 0;
}

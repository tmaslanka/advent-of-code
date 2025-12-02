#include <cassert>
#include <iostream>
#include <string>

bool is_invalid(const std::string& num) {
    if (num.size() % 2 != 0) return false;
    for (size_t i = 0, j = num.size() / 2; j < num.size();) {
        if (num[i] != num[j]) {
            return false;
        }
        i++;
        j++;
    }
    return true;
}

bool is_invalid2(const std::string& num) {
    for (int k = 1; k <= num.size()/2; k++) {
        if (num.size() % k != 0) continue;
        bool invalid = true;
        for (int i = k; i < num.size(); i++) {
            int refI = (k == 1) ? 0 : i % k;
            if (num[refI] != num[i]) {
                invalid = false;
                break;
            }
        }
        if (invalid) return true;
    }
    return false;
}

unsigned long long invalid_ids_sum(const unsigned long long s_num, const unsigned long long e_num) {
    unsigned long long sum = 0;
    for (unsigned long long i = s_num; i <= e_num; i++) {
        if (is_invalid2(std::to_string(i))) {
            sum += i;
            // std::cout << "invalid: " << i << '\n';
        }
    }
    return sum;
}

int main() {
    std::string line;
    std::getline(std::cin, line);

    unsigned long long acc = 0;

    unsigned long long start = 0;
    unsigned long long end = 0;
    unsigned long long num = 0;
    for (const char& c: line) {
        if ('0' <= c && c <= '9') {
            num *= 10;
            num += c - '0';
        } else if (c == '-') {
            start = num;
            num = 0;
        } else {
            end = num;
            num = 0;
            // std::cout << "invalid_ids_sum(" << start << ", " << end << ")\n";
            unsigned long long p_acc = acc;
            acc += invalid_ids_sum(start, end);
            assert(acc >= p_acc);
        }
    }
    // std::cout << "invalid_ids_sum(" << start << ", " << end << ")\n";
    unsigned long long p_acc = acc;
    acc += invalid_ids_sum(start, num);
    assert(acc >= p_acc);
    std::cout << "Invalid IDs sum: " << acc << '\n';

    return 0;
}

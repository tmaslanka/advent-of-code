#include <iostream>

int first() {
    int pos = 50;
    const int mod = 100;
    unsigned int password = 0;
    std::string move;
    while(std::cin >> move) {
        if (move.empty()) {
            std::cout << "Error empty move\n";
            return 1;
        }
        int steps = stoi(move.substr(1, move.size()));
        if(move[0] == 'R') {
        } else {
            steps = -steps;
        }
        // std::cout << "steps: " << steps << '\n';
        int target = (pos + steps) % mod;
        // std::cout << "target: " << target << '\n';
        if (target < 0) {
            target = mod + target;
        }
        pos = target;
        // std::cout << "pos: " << pos << '\n';
        if (pos == 0) {
            password++;
            // std::cout << "pos: " << pos << '\n';
        }
    }
    std::cout << "pos: " << pos <<
        " password: " << password <<
        "\n";
    return 0;
}

int second() {
    int pos = 50;
    const int mod = 100;
    unsigned int password = 0;
    std::string move;
    while(std::cin >> move) {
        if (move.empty()) {
            std::cout << "Error empty move\n";
            return 1;
        }
        int steps = stoi(move.substr(1, move.size()));
        if(move[0] == 'R') {
        } else {
            steps = -steps;
        }
        // std::cout << "steps: " << steps << '\n';
        int target = (pos + steps) % mod;
        int mul = abs(steps / mod);
        // std::cout << "mul: " << mul << '\n';
        // std::cout << "target: " << target << '\n';
        if (target < 0) {
            target = mod + target;
        }
        // std::cout << "pos: " << pos << '\n';
        password += mul;
        if (pos != 0)
        if ((steps < 0 && pos < target) ||
                (steps > 0 && pos > target) ||
                (target == 0)
                ) {
            password++;
        }
        pos = target;
        // std::cout << "pos: " << pos << '\n';
    }
    std::cout << "pos: " << pos <<
        " password: " << password <<
        "\n";
    return 0;
}

int main() {
    return second();
}

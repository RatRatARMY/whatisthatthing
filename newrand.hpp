//
// Created by ratratarmy on 01/02/2026.
//

#ifndef WHATISTHATTHING_NEWRAND_HPP
#define WHATISTHATTHING_NEWRAND_HPP
#include <random>
inline int randint(int a, int b) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dis(a, b);
    return dis(gen);
}
#endif //WHATISTHATTHING_NEWRAND_HPP
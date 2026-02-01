//
// Created by ratratarmy on 01/02/2026.
//

#ifndef WHATISTHATTHING_NEWRAND_HPP
#define WHATISTHATTHING_NEWRAND_HPP
#include <random>
inline int randint(int a, int b) {
    return std::rand() % (b - a + 1) + a;
}
#endif //WHATISTHATTHING_NEWRAND_HPP
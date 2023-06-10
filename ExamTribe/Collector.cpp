#include <iostream>
#include "Collector.h"

Collector::Collector() : Human() {}

Collector::Collector(int strength, int agility, int intelligence) : Human(strength, agility, intelligence) {}

void Collector::getInjured() {
    std::cout << std::endl << "I`m injured! : -" << 45 / strength << "hp" << std::endl << std::endl;
    hp -= 45 / strength;
}

void Collector::work() {
    if (isDead()) {
        return;
    }
    else {
        std::cout << std::endl << "I`m collecting" << std::endl;
        srand(time(NULL));

        if (rand() % agility <= 1) getInjured();
        earned_food = rand() % intelligence + 1;
        remaining_food += earned_food;

        checkHealth();
        hunger -= 40;
        fatigue -= 50;
        statsRoundUp();
        upgrade_points++;

        std::cout << "+" << earned_food << " points of food" << std::endl;
        std::cout << "+ 1 attribute points" << std::endl;
    }
}

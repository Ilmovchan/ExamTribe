#include <iostream>
#include "Fisher.h"

Fisher::Fisher() : Human() {}

Fisher::Fisher(int strength, int agility, int intelligence) : Human(strength, agility, intelligence) {}

void Fisher::getInjured() {
    std::cout << std::endl << "I`m injured! : -" << 30 / strength << "hp" << std::endl << std::endl;
    hp -= 30 / strength;
}

void Fisher::work() {
    if (isDead()) {
        return;
    }
    else {
        std::cout << std::endl << "I`m hunting" << std::endl;
        srand(time(NULL));

        if (rand() % agility <= 1) getInjured();
        earned_food = rand() % intelligence;
        remaining_food += earned_food;

        checkHealth();
        hunger -= 50;
        fatigue -= 40;
        statsRoundUp();
        upgrade_points++;

        std::cout << "+" << earned_food << " points of food" << std::endl;
        std::cout << "+ 1 attribute points" << std::endl;
    }
}
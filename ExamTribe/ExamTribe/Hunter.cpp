#include <iostream>
#include "Hunter.h"

Hunter::Hunter() : Human() {}

Hunter::Hunter(int strength, int agility, int intelligence) : Human(strength, agility, intelligence) {}

void Hunter::getInjured() {
    std::cout << std::endl << "I`m injured! : -" << 80 / strength << "hp" << std::endl << std::endl;
    hp -= 80 / strength;
}

void Hunter::work() {
    if (isDead()) {
        return;
    }
    else {
        std::cout << std::endl << "I`m hunting" << std::endl;
        srand(time(NULL));

        if (rand() % agility <= 2) getInjured();
        earned_food = rand() % intelligence;
        remaining_food += earned_food;

        checkHealth();
        hunger -= 70;
        fatigue -= 80;
        statsRoundUp();
        upgrade_points++;

        std::cout << "+" << earned_food << " points of food" << std::endl;
        std::cout << "+ 1 attribute points" << std::endl;
    }
}

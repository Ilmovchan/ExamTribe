#include <iostream>
#include <ctime>
#include "Human.h"


Human::Human() {}
Human::Human(int strength, int agility, int intelligence) : strength(strength), agility(agility), intelligence(intelligence) {
    if (strength < 0) strength = 1;
    else if (strength > 10) strength = 10;

    if (agility < 0) agility = 1;
    else if (agility > 10) agility = 10;

    if (intelligence < 0) intelligence = 1;
    else if (intelligence > 10) intelligence = 10;
}

//INFO METHODS

void Human::printAttributes() const {
    std::cout << std::endl << "BASIC ATTRIBUTES" << std::endl;
    std::cout << "Strength : " << strength << std::endl;
    std::cout << "Agility : " << agility << std::endl;
    std::cout << "Intelligence : " << intelligence << std::endl;
    if (upgrade_points > 0) std::cout << std::endl << "You can upgrade " << upgrade_points << " attributes!" << std::endl;

}
void Human::printHealthInfo() const {
    std::cout << std::endl << "HEALTH" << std::endl;
    std::cout << "Hunger : " << hunger << std::endl;
    std::cout << "Fatigue : " << fatigue << std::endl;
    std::cout << "Health points : " << hp << std::endl;
    std::cout << "Remaining food : " << remaining_food << std::endl << std::endl;

}

//GETTERS (OPTIONAL)

int Human::getStrength() const {
    return strength;
}
int Human::getAgility() const {
    return agility;
}
int Human::getIntelligence() const {
    return intelligence;
}

int Human::getHp() const {
    return hp;
}
int Human::getFood() const {
    return remaining_food;
}

int Human::getHunger() const {
    return hunger;
}
int Human::getFatigue() const {
    return fatigue;
}
int Human::getUpgradePoints() const {
    return upgrade_points;
}

//METHODS

void Human::work() {
    if (isDead()) {
        return;
    }
    else {
        std::cout << std::endl << "I don`t have any job" << std::endl << std::endl;
    }
}
void Human::sleep() {
    if (isDead()) {
        return;
    }
    else {
        std::cout << std::endl << "I`m sleeping" << std::endl << std::endl;
        hp += 10;
        fatigue += 70;
        checkHealth();
        hunger -= 20;
        statsRoundUp();
    }
}
void Human::eat() {
    if (isDead()) {
        return;
    }
    else if (remaining_food > 0) {
        std::cout << std::endl << "I`m eating" << std::endl << std::endl;
        hp += 10;
        hunger += 40;
        remaining_food--;
        statsRoundUp();
    }
    else {
        std::cout << std::endl << "I don`t have any food" << std::endl << std::endl;
        return;
    }
}

void Human::upgradeStrength() {
    if (upgrade_points > 0) {
        strength++;
        upgrade_points--;
    }
    else std::cout << "You dont have attribute points!" << std::endl;

}
void Human::upgradeAgility() {
    if (upgrade_points > 0) {
        agility++;
        upgrade_points--;
    }
    else std::cout << "You dont have attribute points!" << std::endl;
}
void Human::upgradeIntelligence() {
    if (upgrade_points > 0) {
        intelligence++;
        upgrade_points--;
    }
    else std::cout << "You dont have attribute points!" << std::endl;
}

//CHECKERS

bool Human::isDead() const {
    if (hp <= 0) {
        std::cout << "Survivor is dead" << std::endl;
        return true;
    }

    else return false;
}
void Human::checkHealth() {
    if (hunger <= 0) {
        hp -= 25;
        std::cout << std::endl << "I`m hungry! -25hp" << std::endl;
    }

    if (fatigue <= 0) {
        hp -= 15;
        std::cout << std::endl << "I want to sleep! -15hp" << std::endl;
    }
}

void Human::statsRoundUp() {
    if (hunger < 0) hunger = 0;
    else if (hunger > 100) hunger = 100;

    if (fatigue < 0) fatigue = 0;
    else if (fatigue > 100) fatigue = 100;

    if (hp < 0) hp = 0;
    else if (hp > 100) hp = 100;

    if (remaining_food < 0) remaining_food = 0;
    else if (remaining_food > 100) remaining_food = 100;
}
void Human::getInjured() {
    \
        std::cout << "I`m injured!" << std::endl;
}
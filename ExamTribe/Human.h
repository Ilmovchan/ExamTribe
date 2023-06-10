#pragma once

class Human {

public:

    //CONSTRUCTORS

    Human();
    Human(int strength, int agility, int intelligence);

    //INFO METHODS

    void printAttributes() const;
    void printHealthInfo() const;

    //GETTERS (OPTIONAL)

    int getStrength() const;
    int getAgility() const;
    int getIntelligence() const;

    int getHp() const;
    int getFood() const;

    int getHunger() const;
    int getFatigue() const;
    int getUpgradePoints() const;

    //METHODS

    virtual void work();
    void sleep();
    void eat();

    void upgradeStrength();
    void upgradeAgility();
    void upgradeIntelligence();

protected:

    int strength = 1, agility = 1, intelligence = 1;
    int remaining_food = 2, earned_food = 0;
    int hp = 100, hunger = 100, fatigue = 100;
    int upgrade_points = 0;

    //CHECKERS

    bool isDead() const;
    void checkHealth();

    void statsRoundUp();
    virtual void getInjured();
};

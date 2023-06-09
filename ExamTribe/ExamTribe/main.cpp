#include <iostream>
#include <string>
#include <map>
#include "Hunter.h"
#include "Collector.h"
#include "Fisher.h"

void help() {
    std::cout << std::endl << "COMMAND MENU" << std::endl;
    std::cout << "'attributes (-a)' - shows attributes" << std::endl;
    std::cout << "'health (-h)'- shows hunger, fatigue, hp and food" << std::endl;
    std::cout << "'work (-w)' - starts working" << std::endl;
    std::cout << "'eat (-e)' - starts eating" << std::endl;
    std::cout << "'sleep (-s)' - starts sleeping" << std::endl << std::endl;
}


int main() {

    std::string attribute_name;
    int attribute_points = 5, attribute_tmp;
    int strength = 1, agility = 1, intelligence = 1;

    enum command_id {
        WRONG_COMMAND,
        ATTRIBUTES,
        HEALTH,
        WORK,
        EAT,
        SLEEP,
        UPGRADE,
        HELP,
    };                    // ���������� ����������, ������� ����� ����� ���������� �������
    std::map<std::string, int> command_map;
    std::string command_name;

    std::string job;

    command_map["attributes"] = ATTRIBUTES, command_map["-a"] = ATTRIBUTES;
    command_map["health"] = HEALTH, command_map["-h"] = HEALTH;
    command_map["work"] = WORK, command_map["-w"] = WORK;
    command_map["eat"] = EAT, command_map["-e"] = EAT;
    command_map["sleep"] = SLEEP, command_map["-s"] = SLEEP;
    command_map["upgrade"] = UPGRADE, command_map["-u"] = UPGRADE;
    command_map["help"] = HELP, command_map["-hl"] = HELP;

    //START OF THE INTERFACE

    std::cout << "Choose character (hunter - h, collector - c, fisher - f)" << std::endl;
    while (true) {
        std::cin >> job;
        std::cout << std::endl;
        if (job == "h" || job == "c" || job == "f") break;
        else std::cout << "Wrong job!" << std::endl;
    }

    std::cout << std::endl << "You have 5 attribute points. Choose what attributes you want to upgrade!" << std::endl;
    std::cout << "PS: Strong people have more health, agile people can better avoid injuries and intelligent people work more effective" << std::endl << std::endl;

    while (true) {
        std::cout << std::endl << attribute_points << " points remaining" << std::endl << std::endl;
        std::cout << "Choose attribute (strength - s, agility - a, intelligence - i) : " << std::endl;
        std::cin >> attribute_name;
        if (attribute_name == "s" || attribute_name == "a" || attribute_name == "i") {
            std::cout << "How many points : " << std::endl;
            std::cin >> attribute_tmp;
            if (attribute_tmp <= attribute_points && attribute_tmp > 0) {
                if (attribute_name == "s") strength += attribute_tmp;
                else if (attribute_name == "a") agility += attribute_tmp;
                else if (attribute_name == "i")intelligence += attribute_tmp;
                attribute_points -= attribute_tmp;
            }
            else continue;
        }
        else continue;
        std::cout << std::endl;
        std::cout << "Strength : " << strength << std::endl;
        std::cout << "Agility : " << agility << std::endl;
        std::cout << "Intelligence : " << intelligence << std::endl;
        if (attribute_points <= 0) break;
    }


    if (job == "h") {
        Hunter hunter(strength, agility, intelligence);
        std::cout << std::endl << std::endl << std::endl << "You have created your character! Your job is hunter - dangerous job with big rewards! Now this is your stats : " << std::endl;
        hunter.printAttributes();
        std::cout << std::endl << "This is your health status: " << std::endl;
        hunter.printHealthInfo();
        std::cout << "To see all actions you can type 'help' or '-hl'. Try to survive, good luck!" << std::endl;
        while (true) {
            std::cin >> command_name;
            switch (command_map[command_name]) {
            case ATTRIBUTES: hunter.printAttributes(); break;
            case HEALTH: hunter.printHealthInfo(); break;
            case WORK: hunter.work(); break;
            case EAT: hunter.eat(); break;
            case SLEEP: hunter.sleep(); break;
            case UPGRADE:
                std::cout << "Choose attribute (strength - s, agility - a, intelligence - i) : " << std::endl;
                std::cin >> attribute_name;
                if (attribute_name == "s") hunter.upgradeStrength();
                else if (attribute_name == "a") hunter.upgradeAgility();
                else if (attribute_name == "i") hunter.upgradeIntelligence();
                else std::cout << "Wrong attribute" << std::endl;
                break;
            case HELP: help(); break;
            default: std::cout << "Wrong command" << std::endl << std::endl; break;
            }
        }
    }
    if (job == "c") {
        Collector collector(strength, agility, intelligence);
        std::cout << std::endl << std::endl << std::endl << "You have created your character! Your job is collector - job for calm players. Now this is your stats : " << std::endl;
        collector.printAttributes();
        std::cout << std::endl << "This is your health status: " << std::endl;
        collector.printHealthInfo();
        std::cout << "To see all actions you can type 'help' or '-hl'. Try to survive, good luck!" << std::endl;
        while (true) {
            std::cin >> command_name;
            switch (command_map[command_name]) {
            case ATTRIBUTES: collector.printAttributes(); break;
            case HEALTH: collector.printHealthInfo(); break;
            case WORK: collector.work(); break;
            case EAT: collector.eat(); break;
            case SLEEP: collector.sleep(); break;
            case UPGRADE:
                std::cout << "Choose attribute (strength - s, agility - a, intelligence - i) : " << std::endl;
                std::cin >> attribute_name;
                if (attribute_name == "s") collector.upgradeStrength();
                else if (attribute_name == "a") collector.upgradeAgility();
                else if (attribute_name == "i") collector.upgradeIntelligence();
                else std::cout << "Wrong attribute" << std::endl;
                break;
            case HELP: help(); break;
            default: std::cout << "Wrong command" << std::endl << std::endl; break;
            }
        }
    }
    if (job == "f") {
        Fisher fisher(strength, agility, intelligence);
        std::cout << std::endl << std::endl << std::endl << "You have created your character! Your job is fisher - job for extra calm and soft players. Now this is your stats : " << std::endl;
        fisher.printAttributes();
        std::cout << std::endl << "This is your health status: " << std::endl;
        fisher.printHealthInfo();
        std::cout << "To see all actions you can type 'help' or '-hl'. Try to survive, good luck!" << std::endl;
        while (true) {
            std::cin >> command_name;
            switch (command_map[command_name]) {
            case ATTRIBUTES: fisher.printAttributes(); break;
            case HEALTH: fisher.printHealthInfo(); break;
            case WORK: fisher.work(); break;
            case EAT: fisher.eat(); break;
            case SLEEP: fisher.sleep(); break;
            case UPGRADE:
                std::cout << "Choose attribute (strength - s, agility - a, intelligence - i) : " << std::endl;
                std::cin >> attribute_name;
                if (attribute_name == "s") fisher.upgradeStrength();
                else if (attribute_name == "a") fisher.upgradeAgility();
                else if (attribute_name == "i") fisher.upgradeIntelligence();
                else std::cout << "Wrong attribute" << std::endl;
                break;
            case HELP: help(); break;
            default: std::cout << "Wrong command" << std::endl << std::endl; break;
            }
        }
    }
    else std::cout << "WRONG JOB";


    return 0;
}
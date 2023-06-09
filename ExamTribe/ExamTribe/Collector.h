#pragma once
#include "Human.h"
class Collector : public Human {
public:
	Collector();
	Collector(int strength, int agility, int intelligence);

	void work() override;
private:
	void getInjured() override;
};


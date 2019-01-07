#pragma once
#include "gameObject.h"
#include <string>

class door :
	public gameObject
{
public:

	std::string whereDoorLeads;

	door();
	~door();
};


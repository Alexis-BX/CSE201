#ifndef COLLECTIBLES_H
#define COLLECTIBLES_H
#include "dead.h"
#pragma once

class Collectibles: public Dead
{
public:

	char state;

	Collectibles(std::pair<int,int> position, std::pair<int,int> size, char st);
};
#ifndef COLLECTIBLES_H
#define COLLECTIBLES_H
#include "dead.h"
#pragma once

class Collectibles: public Dead
{
public:

	char state;

	Collectibles(pr position, pr size, char st);
};
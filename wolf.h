#pragma once
#ifndef WOLF_H
#define WOLF_H

#include <Arduino.h>
#include "wolfPins.h"
#include "wolfDebug.h"


// Arduino Library Copy


class wolf
{
public:
	wolf();
	void taskManager();
	wolfPins get_pinOut();
	wolfDebug get_debugger();
	~wolf();
private:
	wolfPins pinOut;
	wolfDebug debugger;
};
#endif // !WOLF_H



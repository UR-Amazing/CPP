#pragma once
#include"PrintQueue.h"
class PrintApp
{
	PrintQueue* PrintQ = PrintQueue::getInstance();
	void menu();
	bool runAction(int action);

public:
	void start();
};


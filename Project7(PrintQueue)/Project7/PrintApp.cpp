#include "PrintApp.h"

void PrintApp::menu()
{
	std::cout << "[1] Exit\n";
	std::cout << "[2] Add new task\n";
	std::cout << "[3] Show current tasks\n";
	std::cout << "[4] Print\n";
	std::cout << "[5] Clear printing queue\n";
	std::cout << "[6] Show statistics\n";
}

bool PrintApp::runAction(int action)
{
	int item;
	int priority;
	switch (action) {
	case 1:
		return false;
		break;
	case 2:
		item = rand() % 99 + 1;
		priority = rand() % 5 + 1;
		PrintQ->add(item, priority);
		break;
	case 3:
		PrintQ->show();
		break;
	case 4:
		PrintQ->Printing();
		break;
	case 5:
		PrintQ->clear();
		std::cout << "Done\n";
		break;
	case 6:
		PrintQ->ShowStatistics();
		break;
	}
	return true;
}

void PrintApp::start()
{
	int action;

	while (true) {
		system("cls");

		menu();
		std::cin >> action;
		if (!runAction(action))
		{
			break;
		}
		system("pause");
	}
}
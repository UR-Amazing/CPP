#include "Bandit.h"

void Bandit::menu()
{
	std::cout << "[1] Exit\n";
	std::cout << "[2] Play\n";
}

bool Bandit::runAction(int action)
{
    switch (action) {
    case 1:
        return false;
        break;
    case 2:
        Game();
        Sleep(2000);
        break;
    }

    return true;
}

void Bandit::start()
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
        Sleep(2000);
    }
}

void Bandit::Game()
{
	srand(time(0));
	int points = 0;
	Drum d1, d2, d3;
	int r1, r2, r3;
	d1.SetAvNum(9);
	d2.SetAvNum(9);
	d3.SetAvNum(9);
	int z;
	do
	{
		r1 = rand() % 13;
		r2 = rand() % 39;
		r3 = rand() % 73;

		d1.SetFace(r1 + 1);
		d2.SetFace(r2 + 1);
		d3.SetFace(r3 + 1);
		d1.ShowDrum();
		d2.ShowDrum();
		d3.ShowDrum();
		if (d1.GetFace() == d2.GetFace() && d1.GetFace() == d3.GetFace())
		{
			std::cout << "\nYou win\n";
			points += 80;
		}
		else
		{
			std::cout << "\nYou lose\n";
			points -= 5;
		}
		std::cout << "Your score: " << points << "\n";
		std::cout << "Try again: Press any key\nQuit: Press Escape\n\n";
		z = _getch();
	} while (z != 27);
}

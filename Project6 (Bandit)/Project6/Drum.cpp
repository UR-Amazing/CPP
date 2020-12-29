#include "Drum.h"

void Drum::SetFace(int num)
{
	face =rand()%num % availablenum;
}

void Drum::SetAvNum(int num)
{
	availablenum = num;
}

int Drum::GetFace()
{
	return face;
}

void Drum::ShowDrum()
{
	if (face > 0 && face < 7)
		std::cout << char(face);
	else
	{
		switch (face)
		{
		case 0:
			std::cout << char(36);
			break;
		case 7:
			std::cout << char(14);
			break;
		case 8:
			std::cout << char(15);
			break;

		}
	}
	std::cout << " ";
}

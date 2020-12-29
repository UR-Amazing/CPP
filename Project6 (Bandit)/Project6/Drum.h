#pragma once
#include <iostream>
class Drum
{
	int name;
	int face;
	int availablenum;
public:
	void SetFace(int);
	void SetAvNum(int);
	int GetFace();
	void ShowDrum();
};


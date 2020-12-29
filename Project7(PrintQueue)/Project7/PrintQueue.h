#pragma once
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <ctime>
#include<time.h>

class PrintQueue
{
	int* pages;
	int* priorities;
	int* statistics;
	int* statprior;
	
	int count;
	int capacity;
	time_t* timeofprint;
	
	static PrintQueue* instance;
	PrintQueue (/*int capacity*/);
public:
	static int printed;
	
	~PrintQueue();

	void add(int item, int priority);
	int extract(int &);
	void clear();
	bool isEmpty();
	bool isFull();
	int getCount();
	void show();
	void Printing();
	void ShowStatistics();

	

	static PrintQueue* getInstance() {
		if (instance == nullptr) {
			instance = new PrintQueue();
		}
		return instance;
	}
};


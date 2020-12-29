#define _CRT_SECURE_NO_WARNINGS
#include "PrintQueue.h"

PrintQueue::PrintQueue(/*int capacity*/)
{
	int capacity = 10;
	this->capacity = capacity;
	count = 0;
	pages = new int[capacity];
	priorities = new int[capacity];
	statistics = new int[capacity]; 
	statprior = new int[capacity];
	timeofprint = new time_t[capacity];
}

PrintQueue::~PrintQueue()
{
	delete[] pages;
	delete[] priorities;
	delete[] statistics;
	delete[] timeofprint;
	delete[] statprior;
}

void PrintQueue::add(int item, int priority)
{
	if (!isFull()) {
		pages[count] = item;
		priorities[count] = priority;
		count++;
	}
	else
	{
		std::cout << "Printing queue is full. Unable to add the item right now.\n";
	}
}


int PrintQueue::extract(int &p)
{
	if (!isEmpty()) {
		int minPriority = priorities[0];
		int minPriorityidx = 0;
		int t = 0;
		for (int i = 1; i < count; i++)
		{
			if (minPriority> priorities[i]) {
				minPriority = priorities[i];
				minPriorityidx = i;
			}
		}

		int minElmt = pages[minPriorityidx];
		p = minPriority;
		for (int i = minPriorityidx; i < count - 1; i++)
		{
			pages[i] = pages[i + 1];
			priorities[i] = priorities[i + 1];
		}
		count--;
		return minElmt;

	}
	return 0;
}

void PrintQueue::clear()
{
	count = 0;
}

bool PrintQueue::isEmpty()
{
	return count == 0;
}

bool PrintQueue::isFull()
{
	return count == capacity;
}

int PrintQueue::getCount()
{
	return count;
}

void PrintQueue::show()
{
	if (!isEmpty())
	{
		std::cout << "-= Clients =-\t-= Priorities =-\t-=Pages=-\n";
		for (int i = 0; i < count; i++)
		{
			if (priorities[i] == 1)
			{
				std::cout << "Admin \t\t";
			}
			else
			{
				std::cout << "User" << priorities[i] - 1 << "\t\t";
			}

			std::cout <<"\t" << priorities[i] << "\t\t" << pages[i] << "\n";
		}
	}
	else
	{
		std::cout << "No current tasks\n";
	}

}

void PrintQueue::Printing()
{
	if (!isEmpty())
	{
		std::cout << "\t-= Printing =-" << std::endl;
		std::cout << "-= Clients =-\t-= Priorities =-\t-=Pages=-\n";
		while (!isEmpty()) {

			int p;
			int tmp = extract(p);
			if (p == 1)
			{
				std::cout << "Admin \t\t\t";
			}
			else
			{
				std::cout << "User"<<p-1<<" \t\t\t";
			}
			
			std::cout << p << "\t\t\t" << tmp << "\n";
			time_t raw = time(&raw);;

			Sleep(1000);

			if (printed < capacity)
			{
				statistics[printed] = tmp;
				timeofprint[printed] = raw;
				statprior[printed] = p;
			}
			else
			{
				memcpy(statistics, statistics + 1, sizeof(int) * (capacity - 1));
				statistics[capacity - 1] = tmp;

				memcpy(timeofprint, timeofprint + 1, sizeof(time_t) * (capacity - 1));
				timeofprint[capacity - 1] = raw;

				memcpy(statprior, statprior + 1, sizeof(int) * (capacity - 1));
				statprior[capacity - 1] = p;
			}
			printed++;
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "No current tasks\n";
	}
}

void PrintQueue::ShowStatistics()
{
	if (printed != 0)
	{
		std::cout << "\t\t    -= Statistics =-" << std::endl;
		std::cout << "-= Clients =-\t-= Priorities =-    -=Pages=-\t-=Date&Time=-\n";
		for (int i = 0; i < (printed < capacity ? printed : capacity); i++)
		{
			if (statprior[i] == 1)
			{
				std::cout << "Admin \t\t\t";
			}
			else
			{
				std::cout << "User" << statprior[i] - 1 << "  \t\t\t";
			}
			std::cout << statprior[i] << "\t\t" << statistics[i] << "\t";

			time_t rawtime = timeofprint[i];
			struct tm* timeinfo;
			char buffer[80];

			timeinfo = localtime(&rawtime);

			strftime(buffer, 80, "%d-%m-%Y %I:%M:%S", timeinfo);
			std::string str(buffer);
			std::cout << str << "\n";
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "No information\n";
	}
}

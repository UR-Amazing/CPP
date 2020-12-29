#include"PrintApp.h"
int PrintQueue::printed = 0;
PrintQueue* PrintQueue::instance = nullptr;
int main()
{
	PrintApp App;
	App.start();
	return 0;
}
// Assignment 1-OO with Polymorphism.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include "Character.h"

//Gets every color combination for text color and highlight color
void Colors()
{
	for (int i = 0; i < 256; ++i)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		printf("Text Color in use = %d\n", i);
	}
}

int MenuScrolling()
{
	int position = 0;
	bool isDown = false;
	vector<string> Options = {"Character", "Pedestrian", "Zombie"};
	//{
	//	"Character", 
	//	"Pedestrian", 
	//	"Zombie"//, 
	//	"Menu Position 4", 
	//	"Menu Position 5", 
	//	"Menu Position 6", 
	//	"Menu Position 7", 
	//	"Menu Position 8", 
	//	"Menu Position 9", 
	//	"Menu Position 10",
	//	"Menu Position 11",
	//	"Menu Position 12",
	//	"Menu Position 13",
	//	"Menu Position 14",
	//};
	int arraySize = Options.size();

	while (true)
	{
		system("cls");


		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "Main Menu " << (position + 1) << "/" << arraySize << "\n\n";


		//cout << keyState << endl;

		//Print the options and scroll bar
		for (int i = 0; i < arraySize; ++i)
		{

			if (i == position)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 121);
			}
			cout << Options[i] << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}

		cout << "\n ---------------Controls-----------------\n";
		cout << "|Arrow UP/DOWN to Scroll. Enter to Select|\n";
		cout << " ----------------------------------------\n"; 

		while (true) 
		{
			//Prevents the cases in the switch statement from looping a bunch
			//Due to GetAsyncKeyState returning true while the loop is running 
			int keyState = GetAsyncKeyState(VK_RETURN);

			//SHORT KeyState = GetAsyncKeyState(VK_RETURN);

			//Press up
			if (GetAsyncKeyState(VK_UP) != 0) 
			{
				position--;
				if (position < 0) { position = arraySize - 1; }
				break;
			}
			//Press Down
			else if (GetAsyncKeyState(VK_DOWN) != 0) 
			{
				position++;
				if (position == arraySize) { position = 0; }
				//position = (position + 1) % arraySize;
				break;
			}

			//Press Enter
			else if (GetAsyncKeyState(VK_RETURN))
			{
				if (keyState != GetAsyncKeyState(VK_RETURN))
				{
					//Option functions
					switch (position)
					{
						case 0:
						{
							Character Character1; 
							Character1.PrintInfo();
							Character Character2 = Character("Roger the Character", 1.2, 100, 2.3);
							Character2.PrintInfo();
						
						} break;

						case 1:
						{
							Pedestrian Ped1 = Pedestrian("James the Pedestrian", 2.4, 120, 3.2, 1.3, 300);
							Ped1.PrintInfo();

							//Deugging 
							//cout << keyState << endl;
							//cout << GetAsyncKeyState(VK_RETURN) << endl;
						} break; 

						case 2:
						{ 
							Zombie Zombie1 = Zombie("Nathan the Zombie", 4.2, 150, 4.1, 150, 170);
							Zombie1.PrintInfo(false);
						} break;

					}

				}
						
			}
		}
		//Scroll Speed
		Sleep(150);
	}

	return 0;
}


int main()
{
	MenuScrolling();
	system("pause");
    return 0;
}


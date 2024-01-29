//////////////////////////////////WAR SHIP////////////////////////////////
#include <iostream>
#include <stdlib.h>//Для rand()
#include <time.h>//Для rand()
#include <conio.h>//Для _getch()
#include <windows.h>//Для Sleep()
#include <mmsystem.h> // Для PlaySound()

#include "Header.h"
#pragma comment (lib,"winmm.lib")
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	bool gameInProgress = true;
	FILE* myFile = nullptr;
	const int numShipTypes = 4;

	int countBot = 0;
	const int colums = 10;
	const int wire = 10;
	char playerArrea[colums][wire];
	char botArrea[colums][wire];
	char simpleArrea[colums][wire];
	int pointsPlayer = 0;
	const int nameSize = 20;
	char name[nameSize];

	for (int i = 0; i < colums; i++)
	{
		for (int j = 0; j < wire; j++)
		{
			playerArrea[i][j] = '-';
			botArrea[i][j] = '-';
			simpleArrea[i][j] = '-';
		}
	}


	cout << "\n\n\n\n\n" << R"(
                                                                                              
                                                                      ,--,        ,-.----.    
           .---.   ,---,       ,-.----.             .--.--.         ,--.'|   ,---,\    /  \   
          /. ./|  '  .' \      \    /  \           /  /    '.    ,--,  | :,`--.' ||   :    \  
      .--'.  ' ; /  ;    '.    ;   :    \         |  :  /`. / ,---.'|  : '|   :  :|   |  .\ : 
     /__./ \ : |:  :       \   |   | .\ :         ;  |  |--`  |   | : _' |:   |  '.   :  |: | 
 .--'.  '   \' .:  |   /\   \  .   : |: |         |  :  ;_    :   : |.'  ||   :  ||   |   \ : 
/___/ \ |    ' '|  :  ' ;.   : |   |  \ :          \  \    `. |   ' '  ; :'   '  ;|   : .   / 
;   \  \;      :|  |  ;/  \   \|   : .  /           `----.   \'   |  .'. ||   |  |;   | |`-'  
 \   ;  `      |'  :  | \  \ ,';   | |  \           __ \  \  ||   | :  | ''   :  ;|   | ;     
  .   \    .\  ;|  |  ' ;'--'  |   | ;\  \         /  /`--'  /'   : |  : ;|   |  ':   ' |     
   \   \   ' \ ||  :  :        :   ' | \.'        '--'.     / |   | '  ,/ '   :  |:   : :     
    :   '  |--" |  | ,'        :   : :-'            `--'---'  ;   : ;--'  ;   |.' |   | :     
     \   \ ;    `--''          |   |.'                        |   ,/      '---'   `---'.|     
      '---"                    `---'                          '---'                 `---`     
)";

	PlaySound(TEXT("PIRATI.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);


	Sleep(2000);
	system("cls");
	while (true)
	{
		
		cout << "\n\n\n\n\n\t\t\t-------------- Hello ,welcome to the game <<  WARSHIP  >> ----------------" << endl;
		cout << "\n\n\n\n\n\n\t\t\t\t\t\t\tPlease select\n\n\t\t\t\t\t\t\t[1].Registration \n\n\t\t\t\t\t\t\t[2].LAST GAMES" << endl;
		cout << "\n\n\n\n\n\t\t\t------------------------------------------------------------------------------" << endl;
		char sel = _getch();
		system("cls");
		if (sel == '1')
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t\t-------------- Hello ,welcome to the game <<  WARSHIP  >> ----------------" << endl;
			cout << "\n\n\n\n\n\t\t\t\t\t\tENTER YOUR NICKNAME -> ";
			cin.getline(name, nameSize);
			cout << "\n\n\n\n\n\t\t\t------------------------------------------------------------------------------" << endl;
			Sleep(2000);
			system("cls");
			break;

		}
		else if (sel == '2')
		{
			while (true)
			{
				char endLiders;
				system("cls");
				cout << "\n\n\n\n\n\t\t\t-------------- Hello ,welcome to the game <<  WARSHIP  >> ----------------" << endl;
				readDataFromFile(myFile);
				cout << "\n\n\n\n\n\t\t\t[0].EXIT" << endl;

				cout << "\n\n\n\n\n\t\t\t------------------------------------------------------------------------------" << endl;
				endLiders = _getch();
				if (endLiders == '0')
				{
					system("cls");
					break;
				}
				else
				{
					system("cls");

					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tEnter 0 if you want to exit" << endl;
					Sleep(2000);
				}
				system("cls");
			}
		}
	}
	while (gameInProgress)
	{
		cout << "\n\n\n\n\n\t\t\t-------------- Hello ,welcome to the game <<  WARSHIP  >> ----------------" << endl;
		cout << "\n\n\n\n\n\n\t\t\t\t\t\t\tDO YOU WANT TO SEE ENEMY WHIPS?\n\n\t\t\t\t\t\t\t[Y].YES \n\n\t\t\t\t\t\t\t[N].NO" << endl;
		cout << "\n\n\n\n\n\t\t\t------------------------------------------------------------------------------" << endl;
		char seeEnemy = _getch();
		system("CLS");
		Sleep(200);
		if (seeEnemy == 89 || seeEnemy == 121)
		{



			cout << "\n\n\n\n\n\t\t\t-------------- Hello ,welcome to the game <<  WARSHIP  >> ----------------" << endl;
			cout << "\n\n\n\n\n\n\t\t\t\t\t\t\tPlease select\n\n\t\t\t\t\t\t\t[ENTER].Play game \n\n\t\t\t\t\t\t\t[ESC].Exit" << endl;
			cout << "\n\n\n\n\n\t\t\t------------------------------------------------------------------------------" << endl;
			char select = _getch();
			if (select == 27)
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t\t------------------------------------------------------------------------------" << endl;
				cout << "\n\n\n\n\n\t\t\t\t\tSee you soon, I hope you enjoyed everything" << endl;
				cout << "\n\n\n\n\n\t\t\t------------------------------------------------------------------------------" << endl;
				break;
			}
			else if (select == 13)
			{
				system("cls");
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tYou're already in the game" << endl;
				Sleep(2000);
				system("cls");
				char playerSelect;
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPlease select a bot difficulty \n\t\t\t\t\t\t[TAB]-EASY\n\t\t\t\t\t\t[SPACE] - HARD" << endl;
				playerSelect = _getch();
				system("cls");
				if (playerSelect == 9)
				{
					////////////////////////////////////////////////////////////////////////STUPID BOTTTTTT//////////////////////////////////////////////////////////////
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tYou select STUPID BOT" << endl;
					Sleep(2000);
					system("cls");
					Sleep(2000);
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tShips are being deployed...." << endl;
					Sleep(2000);
					system("cls");
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tThe ships are positioned" << endl;
					Sleep(2000);
					system("cls");
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tHIT = 50 points\n\t\t\t\t\t\tMISS = -10 points" << endl;
					Sleep(2000);
					system("cls");

					for (int i = 1; i <= 4; i++)
					{
						establishShipsPlayer(playerArrea, i);
						establishShipsBOT(botArrea, i);

					}
					establishShipsRandomlyOnBot(botArrea);
					establishShipsRandomlyOnPlayer(playerArrea);
					printArea(playerArrea, simpleArrea, colums, wire);
					printSimpleArre(botArrea);
					printCountShips();
					Sleep(2000);
					bool choiseBP;
					choiseBP = rand() % 2;
					int countPlayer = 0;
					////////////////////////////////////////////////////////////////////////STUPID BOTTTTTT//////////////////////////////////////////////////////////////
					while ( true )
					{
						if (choiseBP)
						{
							cout << "\n\n\t\t\t\t\t\tYour move" << endl;
							Sleep(2000);
							system("cls");
							int x2, y2;
							printArea(playerArrea, simpleArrea, colums, wire);
							printSimpleArre(botArrea);
							printCountShips();
							while (true)
							{
								cout << "Enter coordinates for enemy attack (X and Y)" << endl << endl << endl;
								cout << "Enter X:";
								cin >> x2;
								cout << endl;
								cout << "Enter Y:";
								cin >> y2;
								if (x2 <= 9 && y2 <= 9)
								{
									break;
								}
							}
							while (true)
							{
								if (botArrea[x2][y2] == 'S' && simpleArrea[x2][y2] != 'X' && simpleArrea[x2][y2] != '*') {
									PlaySound(TEXT("SHOTING.wav"), NULL, SND_FILENAME | SND_ASYNC);
									cout << "---------HIT---------" << endl;
									simpleArrea[x2][y2] = 'X';

									pointsPlayer += 50;
									cout << "POINTS : " << pointsPlayer << endl;
									countPlayer++;

									if (countPlayer == 20) {
										Sleep(1000);
										system("cls");
										cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tYOU WIN!!!" << endl;
										Sleep(2000);
										system("cls");
										cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tYOUR POINTS:" << pointsPlayer << endl;
										addDataToFile(myFile, *&name, pointsPlayer);
										Sleep(2000);
										system("cls");
										gameInProgress = false;
										break;
										
									}

									break;
								}
								else if (botArrea[x2][y2] != 'S' && simpleArrea[x2][y2] != 'X' && simpleArrea[x2][y2] != 'O' && simpleArrea[x2][y2] != '*')
								{
									simpleArrea[x2][y2] = 'O';
									PlaySound(TEXT("SHOTING.wav"), NULL, SND_FILENAME | SND_SYNC);
									PlaySound(TEXT("SEA.wav"), NULL, SND_FILENAME | SND_ASYNC);
									cout << "---------YOU MISSED---------" << endl;
									cout << "POINTS : " << pointsPlayer << endl;
									pointsPlayer -= 10;
									choiseBP = !choiseBP;
									break;
								}
								else
								{
									while (true)
									{
										cout << "Enter coordinates for enemy attack (X and Y)" << endl;
										cout << "Enter X:";
										cin >> x2;
										cout << endl;
										cout << "Enter Y:";
										cin >> y2;
										if (x2 <= 9 && y2 <= 9)
										{
											break;
										}
									}
								}
							}
						}
						////////////////////////////////////////////////////////////////////////STUPID BOTTTTTT//////////////////////////////////////////////////////////////
						else
						{
							cout << "\n\n\t\t\t\t\t\tBOT MOVE" << endl;
							Sleep(2000);
							system("cls");
							int x1, y1;
							printArea(playerArrea, simpleArrea, colums, wire);
							printSimpleArre(botArrea);
							printCountShips();
							x1 = rand() % 10;
							y1 = rand() % 10;
							while (true)
							{
								if (playerArrea[x1][y1] == 'S' && playerArrea[x1][y1] != 'X')
								{
									PlaySound(TEXT("SHOTING.wav"), NULL, SND_FILENAME | SND_SYNC);
									cout << "---------BOT HIT---------" << endl;
									playerArrea[x1][y1] = 'X';
									countBot++;
									break;
									if (countBot == 20)
									{
										Sleep(1000);
										system("cls");
										cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tBOT WIN!!!" << endl;
										Sleep(2000);
										system("cls");
										gameInProgress = false;
										break;
									}

								}
								else if (playerArrea[x1][y1] != 'S' && playerArrea[x1][y1] != 'X' && playerArrea[x1][y1] != 'O')
								{
									playerArrea[x1][y1] = 'O';
									PlaySound(TEXT("SHOTING.wav"), NULL, SND_FILENAME | SND_SYNC);
									PlaySound(TEXT("SEA.wav"), NULL, SND_FILENAME | SND_ASYNC);
									cout << "---------BOT MISSED---------" << endl;
									choiseBP = !choiseBP;
									break;
								}
								else
								{
									x1 = rand() % 10;
									y1 = rand() % 10;
								}
							}
						}
					}
				}
				////////////////////////////////////////////////////////////////////////SMART BOT//////////////////////////////////////////////////////////////
				else if (playerSelect == 32)
				{
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tYou select SMART BOT" << endl;
					Sleep(2000);
					system("cls");
					Sleep(2000);
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tShips are being deployed...." << endl;
					Sleep(2000);
					system("cls");
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tThe ships are positioned" << endl;
					Sleep(2000);
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tHIT = 50 points\n\t\t\t\t\t\tMISS = -10 points" << endl;
					Sleep(2000);
					system("cls");
					for (int i = 1; i < 5; i++)
					{
						establishShipsPlayer(playerArrea, i);
						establishShipsBOT(botArrea, i);

					}
					establishShipsRandomlyOnBot(botArrea);
					establishShipsRandomlyOnPlayer(playerArrea);
					printArea(playerArrea, simpleArrea, colums, wire);
					printSimpleArre(botArrea);
					printCountShips();
					Sleep(2000);
					bool choiseBP;
					choiseBP = rand() % 2;
					int countBot = 0;
					int countPlayer = 0;
					////////////////////////////////////////////////////////////////////////SMART BOT//////////////////////////////////////////////////////////////
					while (true)
					{

						if (choiseBP)
						{
							cout << "\n\n\t\t\t\t\t\tYour move" << endl;
							Sleep(2000);
							system("cls");
							int x2, y2;
							printArea(playerArrea, simpleArrea, colums, wire);
							printSimpleArre(botArrea);
							printCountShips();
							while (true)
							{
								cout << "Enter coordinates for enemy attack (X and Y)" << endl << endl << endl;
								cout << "Enter X:";
								cin >> x2;
								cout << endl;
								cout << "Enter Y:";
								cin >> y2;
								if (x2 <= 9 && y2 <= 9)
								{
									break;
								}

							}
							while (true)
							{
								if (botArrea[x2][y2] == 'S' && simpleArrea[x2][y2] != 'X')
								{
									PlaySound(TEXT("SHOTING.wav"), NULL, SND_FILENAME | SND_SYNC);

									cout << "---------HIT---------" << endl;

									simpleArrea[x2][y2] = 'X';
									countPlayer++;
									break;
									if (countPlayer == 20)
									{
										Sleep(1000);
										system("cls");
										cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tYOU WIN!!!" << endl;
										Sleep(2000);
										system("cls");
										gameInProgress = false;
										break;
									}
								}
								else if (botArrea[x2][y2] != 'S' && simpleArrea[x2][y2] != 'X' && simpleArrea[x2][y2] != 'O')
								{
									simpleArrea[x2][y2] = 'O';
									PlaySound(TEXT("SHOTING.wav"), NULL, SND_FILENAME | SND_SYNC);
									PlaySound(TEXT("SEA.wav"), NULL, SND_FILENAME | SND_ASYNC);
									cout << "---------YOU MISSED---------" << endl;
									choiseBP = !choiseBP;
									break;
								}
								else {
									while (true)
									{
										cout << "Enter coordinates for enemy attack (X and Y)" << endl;
										cout << "Enter X:";
										cin >> x2;
										cout << endl;
										cout << "Enter Y:";
										cin >> y2;
										if (x2 <= 9 && y2 <= 9)
										{
											break;
										}
									}
								}
							}
						}
						////////////////////////////////////////////////////////////////////////SMART BOTTTTTT//////////////////////////////////////////////////////////////
						else
						{
							cout << "\n\n\t\t\t\t\t\tBOT MOVE" << endl;
							Sleep(2000);
							system("cls");
							printArea(playerArrea, simpleArrea, colums, wire);
							printSimpleArre(botArrea);
							printCountShips();
							int x1, y1;
							srand(time(NULL));

							int consecutiveHits = 0;
							x1 = rand() % 10;
							y1 = rand() % 10;
							if (playerArrea[x1][y1] == 'S') {
								PlaySound(TEXT("SHOTING.wav"), NULL, SND_FILENAME | SND_SYNC);
								cout << "BOT HIT\n";
								playerArrea[x1][y1] = 'X';
								countBot++;
								consecutiveHits++;


								while (consecutiveHits > 0)
								{
									int direction = rand() % 4;
									int nearTargets[4][2] = { {x1 - 1, y1}, {x1 + 1, y1}, {x1, y1 - 1}, {x1, y1 + 1} };
									x1 = nearTargets[direction][0];
									y1 = nearTargets[direction][1];

									if (x1 < 0 || x1 >= 10 || y1 < 0 || y1 >= 10 || playerArrea[x1][y1] == 'X')
									{
										consecutiveHits = 0;
										break;
									}

									if (playerArrea[x1][y1] == 'S')
									{
										PlaySound(TEXT("SHOTING.wav"), NULL, SND_FILENAME | SND_SYNC);
										cout << "BOT HIT\n";
										playerArrea[x1][y1] = 'X';
										countBot++;
										consecutiveHits++;
										if (countBot == 20)
										{
											Sleep(1000);
											system("cls");
											cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tBOT WIN!!!" << endl;
											Sleep(2000);
											system("cls");
											gameInProgress = false;
											break;
										}
									}
									else
									{
										PlaySound(TEXT("SHOTING.wav"), NULL, SND_FILENAME | SND_SYNC);
										PlaySound(TEXT("SEA.wav"), NULL, SND_FILENAME | SND_ASYNC);
										cout << "BOT MISSED\n";
										playerArrea[x1][y1] = 'O';
										consecutiveHits = 0;
										break;
									}
								}
							}
							else if (playerArrea[x1][y1] == 'X')
							{
								continue;
							}
							else
							{
								playerArrea[x1][y1] = '-';
								PlaySound(TEXT("SHOTING.wav"), NULL, SND_FILENAME | SND_SYNC);
								PlaySound(TEXT("SEA.wav"), NULL, SND_FILENAME | SND_ASYNC);
								cout << "BOT MISSED\n";
								playerArrea[x1][y1] = 'O';
								choiseBP = !choiseBP;
							}
						}
					}

				}
			}
			else
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t\t-----------------Hello ,welcome to the game called sea battle-----------------" << endl;
				cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tPlease press Enter of Escape" << endl;
				cout << "\n\n\n\n\n\n\n\n\t\t\t------------------------------------------------------------------------------" << endl;
				Sleep(100);
				system("cls");
			}
		}
		if (seeEnemy == 78 || seeEnemy == 110)
		{



			cout << "\n\n\n\n\n\t\t\t-------------- Hello ,welcome to the game <<  WARSHIP  >> ----------------" << endl;
			cout << "\n\n\n\n\n\n\t\t\t\t\t\t\tPlease select\n\n\t\t\t\t\t\t\t[ENTER].Play game \n\n\t\t\t\t\t\t\t[ESC].Exit" << endl;
			cout << "\n\n\n\n\n\t\t\t------------------------------------------------------------------------------" << endl;
			char select = _getch();
			if (select == 27)
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t\t------------------------------------------------------------------------------" << endl;
				cout << "\n\n\n\n\n\t\t\t\t\tSee you soon, I hope you enjoyed everything" << endl;
				cout << "\n\n\n\n\n\t\t\t------------------------------------------------------------------------------" << endl;
				break;
			}
			else if (select == 13)
			{
				system("cls");
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tYou're already in the game" << endl;
				Sleep(2000);
				system("cls");
				char playerSelect;
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPlease select a bot difficulty \n\t\t\t\t\t\t[TAB]-EASY\n\t\t\t\t\t\t[SPACE] - HARD" << endl;
				playerSelect = _getch();
				system("cls");
				if (playerSelect == 9)
				{
					////////////////////////////////////////////////////////////////////////STUPID BOTTTTTT//////////////////////////////////////////////////////////////
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tYou select STUPID BOT" << endl;
					Sleep(2000);
					system("cls");
					Sleep(2000);
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tShips are being deployed...." << endl;
					Sleep(2000);
					system("cls");
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tThe ships are positioned" << endl;
					Sleep(2000);
					system("cls");
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tHIT = 50 points\n\t\t\t\t\t\tMISS = -10 points" << endl;
					Sleep(2000);
					system("cls");

					for (int i = 1; i <= 4; i++)
					{
						establishShipsPlayer(playerArrea, i);
						establishShipsBOT(botArrea, i);

					}

					establishShipsRandomlyOnBot(botArrea);
					establishShipsRandomlyOnPlayer(playerArrea);
					printArea(playerArrea, simpleArrea, colums, wire);

					printCountShips();
					Sleep(2000);
					bool choiseBP;
					choiseBP = rand() % 2;
					int countPlayer = 0;
					////////////////////////////////////////////////////////////////////////STUPID BOTTTTTT//////////////////////////////////////////////////////////////
					while (true)
					{

						if (choiseBP)
						{
							cout << "\n\n\t\t\t\t\t\tYour move" << endl;
							Sleep(2000);
							system("cls");
							int x2, y2;
							printArea(playerArrea, simpleArrea, colums, wire);
							printCountShips();
							while (true)
							{
								cout << "Enter coordinates for enemy attack (X and Y)" << endl << endl << endl;
								cout << "Enter X:";
								cin >> x2;
								cout << endl;
								cout << "Enter Y:";
								cin >> y2;
								if (x2 <= 9 && y2 <= 9)
								{
									break;
								}
							}
							while (true)
							{
								if (botArrea[x2][y2] == 'S' && simpleArrea[x2][y2] != 'X' && simpleArrea[x2][y2] != '*') {
									PlaySound(TEXT("SHOTING.wav"), NULL, SND_FILENAME | SND_ASYNC);
									cout << "---------HIT---------" << endl;
									pointsPlayer += 50;
									cout << "POINTS : " << pointsPlayer << endl;
									simpleArrea[x2][y2] = 'X';


									countPlayer++;
									//checkAndMarkSunkShip(botArrea, simpleArrea, x2, y2);

									if (countPlayer == 20)
									{
										Sleep(1000);
										system("cls");
										cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tYOU WIN!!!" << endl;
										Sleep(2000);
										system("cls");
										cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tYOUR POINTS:" << pointsPlayer << endl;
										addDataToFile(myFile, *&name, pointsPlayer);
										Sleep(2000);
										system("cls");
										gameInProgress = false;
										break;
									}
									break;
								}
								else if (botArrea[x2][y2] != 'S' && simpleArrea[x2][y2] != 'X' && simpleArrea[x2][y2] != 'O' && simpleArrea[x2][y2] != '*')
								{
									simpleArrea[x2][y2] = 'O';
									PlaySound(TEXT("SHOTING.wav"), NULL, SND_FILENAME | SND_SYNC);
									PlaySound(TEXT("SEA.wav"), NULL, SND_FILENAME | SND_ASYNC);
									cout << "---------YOU MISSED---------" << endl;
									cout << "POINTS : " << pointsPlayer << endl;
									pointsPlayer -= 10;
									choiseBP = !choiseBP;
									break;
								}
								else {
									while (true)
									{
										cout << "Enter coordinates for enemy attack (X and Y)" << endl;
										cout << "Enter X:";
										cin >> x2;
										cout << endl;
										cout << "Enter Y:";
										cin >> y2;
										if (x2 <= 9 && y2 <= 9)
										{
											break;
										}
									}
								}
							}
						}
						////////////////////////////////////////////////////////////////////////STUPID BOTTTTTT//////////////////////////////////////////////////////////////
						else
						{
							cout << "\n\n\t\t\t\t\t\tBOT MOVE" << endl;
							Sleep(2000);
							system("cls");
							int x1, y1;
							printArea(playerArrea, simpleArrea, colums, wire);
							printCountShips();
							x1 = rand() % 10;
							y1 = rand() % 10;
							while (true)
							{
								if (playerArrea[x1][y1] == 'S' && playerArrea[x1][y1] != 'X')
								{
									PlaySound(TEXT("SHOTING.wav"), NULL, SND_FILENAME | SND_SYNC);
									cout << "---------BOT HIT---------" << endl;
									playerArrea[x1][y1] = 'X';
									countBot++;
									break;
									if (countBot == 20)
									{
										Sleep(1000);
										system("cls");
										cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tBOT WIN!!!" << endl;
										Sleep(2000);
										system("cls");
										gameInProgress = false;
										break;
									}

								}
								else if (playerArrea[x1][y1] != 'S' && playerArrea[x1][y1] != 'X' && playerArrea[x1][y1] != 'O')
								{
									playerArrea[x1][y1] = 'O';
									PlaySound(TEXT("SHOTING.wav"), NULL, SND_FILENAME | SND_SYNC);
									PlaySound(TEXT("SEA.wav"), NULL, SND_FILENAME | SND_ASYNC);
									cout << "---------BOT MISSED---------" << endl;
									choiseBP = !choiseBP;
									break;
								}
								else
								{
									x1 = rand() % 10;
									y1 = rand() % 10;
								}
							}
						}
					}
				}
				////////////////////////////////////////////////////////////////////////SMART BOT//////////////////////////////////////////////////////////////
				else if (playerSelect == 32)
				{
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tYou select SMART BOT" << endl;
					Sleep(2000);
					system("cls");
					Sleep(2000);
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tShips are being deployed...." << endl;
					Sleep(2000);
					system("cls");
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tThe ships are positioned" << endl;
					Sleep(2000);
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tHIT = 50 points\n\t\t\t\t\t\tMISS = -10 points" << endl;
					Sleep(2000);
					system("cls");
					for (int i = 1; i < 5; i++)
					{
						establishShipsPlayer(playerArrea, i);
						establishShipsBOT(botArrea, i);

					}
					establishShipsRandomlyOnBot(botArrea);
					establishShipsRandomlyOnPlayer(playerArrea);
					printArea(playerArrea, simpleArrea, colums, wire);
					printCountShips();
					Sleep(2000);
					bool choiseBP;
					choiseBP = rand() % 2;
					int countBot = 0;
					int countPlayer = 0;
					////////////////////////////////////////////////////////////////////////SMART BOT//////////////////////////////////////////////////////////////
					while (true)
					{

						if (choiseBP)
						{
							cout << "\n\n\t\t\t\t\t\tYour move" << endl;
							Sleep(2000);
							system("cls");
							int x2, y2;
							printArea(playerArrea, simpleArrea, colums, wire);
							printCountShips();
							while (true)
							{
								cout << "Enter coordinates for enemy attack (X and Y)" << endl << endl << endl;
								cout << "Enter X:";
								cin >> x2;
								cout << endl;
								cout << "Enter Y:";
								cin >> y2;
								if (x2 <= 9 && y2 <= 9)
								{
									break;
								}

							}
							while (true)
							{
								if (botArrea[x2][y2] == 'S' && simpleArrea[x2][y2] != 'X')
								{
									PlaySound(TEXT("SHOTING.wav"), NULL, SND_FILENAME | SND_SYNC);
									cout << "---------HIT---------" << endl;
									simpleArrea[x2][y2] = 'X';
									countPlayer++;
									break;
									if (countPlayer == 20)
									{
										Sleep(1000);
										system("cls");
										cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tYOU WIN!!!" << endl;
										Sleep(2000);
										system("cls");
										break;
									}
								}
								else if (botArrea[x2][y2] != 'S' && simpleArrea[x2][y2] != 'X' && simpleArrea[x2][y2] != 'O')
								{
									simpleArrea[x2][y2] = 'O';
									PlaySound(TEXT("SHOTING.wav"), NULL, SND_FILENAME | SND_SYNC);
									PlaySound(TEXT("SEA.wav"), NULL, SND_FILENAME | SND_ASYNC);
									cout << "---------YOU MISSED---------" << endl;
									choiseBP = !choiseBP;
									break;
								}
								else {
									while (true)
									{
										cout << "Enter coordinates for enemy attack (X and Y)" << endl;
										cout << "Enter X:";
										cin >> x2;
										cout << endl;
										cout << "Enter Y:";
										cin >> y2;
										if (x2 <= 9 && y2 <= 9)
										{
											break;
										}
									}
								}
							}
						}
						////////////////////////////////////////////////////////////////////////SMART BOTTTTTT//////////////////////////////////////////////////////////////
						else
						{

							cout << "\n\n\t\t\t\t\t\tBOT MOVE" << endl;
							Sleep(2000);
							system("cls");
							printArea(playerArrea, simpleArrea, colums, wire);
							printCountShips();
							int x1, y1;
							srand(time(NULL));

							int consecutiveHits = 0;
							x1 = rand() % 10;
							y1 = rand() % 10;
							if (playerArrea[x1][y1] == 'S') {
								PlaySound(TEXT("SHOTING.wav"), NULL, SND_FILENAME | SND_SYNC);
								cout << "BOT HIT\n";
								playerArrea[x1][y1] = 'X';
								countBot++;
								consecutiveHits++;


								while (consecutiveHits > 0)
								{
									int direction = rand() % 4;
									int nearTargets[4][2] = { {x1 - 1, y1}, {x1 + 1, y1}, {x1, y1 - 1}, {x1, y1 + 1} };
									x1 = nearTargets[direction][0];
									y1 = nearTargets[direction][1];

									if (x1 < 0 || x1 >= 10 || y1 < 0 || y1 >= 10 || playerArrea[x1][y1] == 'X')
									{
										consecutiveHits = 0;
										break;
									}

									if (playerArrea[x1][y1] == 'S')
									{
										PlaySound(TEXT("SHOTING.wav"), NULL, SND_FILENAME | SND_SYNC);
										cout << "BOT HIT\n";
										playerArrea[x1][y1] = 'X';
										countBot++;
										consecutiveHits++;
										;
										if (countBot == 20)
										{
											Sleep(1000);
											system("cls");
											cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tBOT WIN!!!" << endl;
											Sleep(2000);
											system("cls");
											gameInProgress = false;
											break;
										}
									}
									else
									{
										PlaySound(TEXT("SHOTING.wav"), NULL, SND_FILENAME | SND_SYNC);
										PlaySound(TEXT("SEA.wav"), NULL, SND_FILENAME | SND_ASYNC);
										cout << "BOT MISSED\n";
										playerArrea[x1][y1] = 'O';
										consecutiveHits = 0;
										break;
									}
								}
							}
							else if (playerArrea[x1][y1] == 'X')
							{
								continue;
							}
							else
							{
								playerArrea[x1][y1] = '-';
								PlaySound(TEXT("SHOTING.wav"), NULL, SND_FILENAME | SND_SYNC);
								PlaySound(TEXT("SEA.wav"), NULL, SND_FILENAME | SND_ASYNC);
								cout << "BOT MISSED\n";
								playerArrea[x1][y1] = 'O';
								choiseBP = !choiseBP;
							}
						}
					}

				}
			}
			else
			{
				system("cls");
				cout << "\n\n\n\n\n\t\t\t-----------------Hello ,welcome to the game called sea battle-----------------" << endl;
				cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tPlease press Enter of Escape" << endl;
				cout << "\n\n\n\n\n\n\n\n\t\t\t------------------------------------------------------------------------------" << endl;
				Sleep(100);
				system("cls");
			}
		}
		else
		{
			system("cls");
			cout << "\n\n\n\n\n\t\t\t-----------------Hello ,welcome to the game called sea battle-----------------" << endl;
			cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tPlease press Y or N" << endl;
			cout << "\n\n\n\n\n\n\n\n\t\t\t------------------------------------------------------------------------------" << endl;
			Sleep(1000);
			system("cls");
		}
	}
}











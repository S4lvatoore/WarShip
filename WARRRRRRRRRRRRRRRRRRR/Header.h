#pragma once
#pragma once
using namespace std;
void printArea(char playerArea[][10], char botArea[][10], int colums, int wire)
{
	cout << "Your battle Arrea:\t\t\t\t\t\tBOT Arrea:" << endl;
	cout << "   0 1 2 3 4 5 6 7 8 9\t\t\t\t\t   0 1 2 3 4 5 6 7 8 9" << endl;
	for (int i = 0; i < colums; i++)
	{
		cout << i << "  ";
		for (int j = 0; j < wire; j++)
		{
			cout << playerArea[i][j] << " ";
		}
		cout << "\t\t\t\t\t";
		cout << i << "  ";
		for (int j = 0; j < wire; j++)
		{
			cout << botArea[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void printCountShips()
{
	cout << "4-S\n3-SS\n2-SSS\n1-SSSS" << endl;
}

////////////////////////////ДЛЯ ИГРОКА////////////////////////////////////////
bool canPlaceShipOnPlayer(char playerArea[][10], int x, int y, int shipSize, bool horizontal) {
	if (horizontal) {
		if (y + shipSize > 10) {
			return false;
		}
		for (int i = 0; i < shipSize; i++) {
			if (playerArea[x][y + i] == 'S') {
				return false;
			}
			else if (x > 0 && playerArea[x - 1][y + i] == 'S') {
				return false;  // ПРОВЕРКА ЛЕВОЙ ЧАСТИ
			}
			else if (x < 10 - 1 && playerArea[x + 1][y + i] == 'S') {
				return false;  // ПРОВЕРКА ПРАВОЙ ЧАСТИ
			}
			else if (y + i > 0 && playerArea[x][y + i - 1] == 'S') {
				return false;  // ПРОВЕРКА ВЕРХА
			}
			else if (y + i < 10 - 1 && playerArea[x][y + i + 1] == 'S') {
				return false;  // ПРОВЕРКА НА НИЗ
			}
			else if (x > 0 && y + i > 0 && playerArea[x - 1][y + i - 1] == 'S') {
				return false;  // ПРОВЕРКА ЛЕВОЙ ВЕРХНЕЙ ДИАГОНАЛИ
			}
			else if (x < 10 - 1 && y + i > 0 && playerArea[x + 1][y + i - 1] == 'S') {
				return false;  // ПРОВЕРКА ПРАВОЙ ВЕРХНЕЙ ДИАГОНАЛИ
			}
			else if (x > 0 && y + i < 10 - 1 && playerArea[x - 1][y + i + 1] == 'S') {
				return false;  // ПРОВЕРКА ЛЕВОЙ НИЖНЕЙ ДИАГОНАЛИ
			}
			else if (x < 10 - 1 && y + i < 10 - 1 && playerArea[x + 1][y + i + 1] == 'S') {
				return false;  // ПРОВЕРКА ПРАВОЙ НИЖНЕЙ ДИАГОНАЛИ
			}
		}
	}
	else {
		if (x + shipSize > 10) {
			return false;
		}
		for (int i = 0; i < shipSize; i++) {
			if (playerArea[x + i][y] == 'S') {
				return false;
			}
			else if (y > 0 && playerArea[x + i][y - 1] == 'S') {
				return false;  // ВЕРХНЯЯ ЧАСТЬ
			}
			else if (y < 10 - 1 && playerArea[x + i][y + 1] == 'S') {
				return false;  // НИЖНЯЯ ЧАСТЬ
			}
			else if (x + i > 0 && playerArea[x + i - 1][y] == 'S') {
				return false;  // ЛЕВАЯ ЧАСТЬ
			}
			else if (x + i < 10 - 1 && playerArea[x + i + 1][y] == 'S') {
				return false;  // ПРАВАЯ ЧАСТЬ
			}
			else if (x + i > 0 && y > 0 && playerArea[x + i - 1][y - 1] == 'S') {
				return false;  // ВЕРХНЯЯ ЛЕВАЯ ДИАГОНАЛЬ
			}
			else if (x + i > 0 && y < 10 - 1 && playerArea[x + i - 1][y + 1] == 'S') {
				return false;  // ВЕРХНЯЯ ПРАВАЯ ДИАГОНАЛЬ
			}
			else if (x + i < 10 - 1 && y > 0 && playerArea[x + i + 1][y - 1] == 'S') {
				return false;  // НИЖНЯЯ ЛЕВАЯ ДИАГОНАЛЬ
			}
			else if (x + i < 10 - 1 && y < 10 - 1 && playerArea[x + i + 1][y + 1] == 'S') {
				return false;  // НИЖНЯЯ ПРАВАЯ ДИАГОНАЛЬ
			}
		}
	}
	return true;
}

void establishShipsPlayer(char playerArea[][10], int shipSize)
{
	srand(time(NULL));
	int x, y;
	bool horizontal;
	do
	{
		x = rand() % 10;
		y = rand() % 10;
		horizontal = rand() % 2;
	} while (!canPlaceShipOnPlayer(playerArea, x, y, shipSize, horizontal));

	for (int i = 0; i < shipSize; i++)
	{
		if (horizontal)
		{
			if ((i + y) < 10)
			{
				playerArea[x][y + i] = 'S';
			}
		}
		else
		{
			if ((i + x) < 10)
			{
				playerArea[x + i][y] = 'S';
			}
		}
	}
}





//////////////////////////////////////////ДЛЯ БОТА/////////////////////////////////////
bool canPlaceShipOnBOT(char BOTarrea[][10], int x, int y, int shipSize, bool horizontal) {
	if (horizontal) {
		if (y + shipSize > 10) {
			return false;
		}
		for (int i = 0; i < shipSize; i++) {
			if (BOTarrea[x][y + i] == 'S') {
				return false;
			}
			else if (x > 0 && BOTarrea[x - 1][y + i] == 'S') {
				return false;  // ПРОВЕРКА ЛЕВОЙ ЧАСТИ
			}
			else if (x < 10 - 1 && BOTarrea[x + 1][y + i] == 'S') {
				return false;  // ПРОВЕРКА ПРАВОЙ ЧАСТИ
			}
			else if (y + i > 0 && BOTarrea[x][y + i - 1] == 'S') {
				return false;  // ПРОВЕРКА ВЕРХА
			}
			else if (y + i < 10 - 1 && BOTarrea[x][y + i + 1] == 'S') {
				return false;  // ПРОВЕРКА НА НИЗ
			}
			else if (x > 0 && y + i > 0 && BOTarrea[x - 1][y + i - 1] == 'S') {
				return false;  // ПРОВЕРКА ЛЕВОЙ ВЕРХНЕЙ ДИАГОНАЛИ
			}
			else if (x < 10 - 1 && y + i > 0 && BOTarrea[x + 1][y + i - 1] == 'S') {
				return false;  // ПРОВЕРКА ПРАВОЙ ВЕРХНЕЙ ДИАГОНАЛИ
			}
			else if (x > 0 && y + i < 10 - 1 && BOTarrea[x - 1][y + i + 1] == 'S') {
				return false;  // ПРОВЕРКА ЛЕВОЙ НИЖНЕЙ ДИАГОНАЛИ
			}
			else if (x < 10 - 1 && y + i < 10 - 1 && BOTarrea[x + 1][y + i + 1] == 'S') {
				return false;  // ПРОВЕРКА ПРАВОЙ НИЖНЕЙ ДИАГОНАЛИ
			}
		}
	}
	else {
		if (x + shipSize > 10) {
			return false;
		}
		for (int i = 0; i < shipSize; i++) {
			if (BOTarrea[x + i][y] == 'S') {
				return false;
			}
			else if (y > 0 && BOTarrea[x + i][y - 1] == 'S') {
				return false;  // ВЕРХНЯЯ ЧАСТЬ
			}
			else if (y < 10 - 1 && BOTarrea[x + i][y + 1] == 'S') {
				return false;  // НИЖНЯЯ ЧАСТЬ
			}
			else if (x + i > 0 && BOTarrea[x + i - 1][y] == 'S') {
				return false;  // ЛЕВАЯ ЧАСТЬ
			}
			else if (x + i < 10 - 1 && BOTarrea[x + i + 1][y] == 'S') {
				return false;  // ПРАВАЯ ЧАСТЬ
			}
			else if (x + i > 0 && y > 0 && BOTarrea[x + i - 1][y - 1] == 'S') {
				return false;  // ВЕРХНЯЯ ЛЕВАЯ ДИАГОНАЛЬ
			}
			else if (x + i > 0 && y < 10 - 1 && BOTarrea[x + i - 1][y + 1] == 'S') {
				return false;  // ВЕРХНЯЯ ПРАВАЯ ДИАГОНАЛЬ
			}
			else if (x + i < 10 - 1 && y > 0 && BOTarrea[x + i + 1][y - 1] == 'S') {
				return false;  // НИЖНЯЯ ЛЕВАЯ ДИАГОНАЛЬ
			}
			else if (x + i < 10 - 1 && y < 10 - 1 && BOTarrea[x + i + 1][y + 1] == 'S') {
				return false;  // НИЖНЯЯ ПРАВАЯ ДИАГОНАЛЬ
			}
		}
	}
	return true;
}


void establishShipsBOT(char botArea[][10], int shipSize)
{
	int x, y;
	bool horizontal;
	do
	{
		x = rand() % 10;
		y = rand() % 10;
		horizontal = rand() % 2;
	} while (!canPlaceShipOnBOT(botArea, x, y, shipSize, horizontal));

	for (int i = 0; i < shipSize; i++)
	{
		if (horizontal)
		{
			botArea[x][y + i] = 'S';
		}
		else
		{
			botArea[x + i][y] = 'S';
		}
	}
}
void establishShipsRandomlyOnBot(char area[][10]) {
	establishShipsBOT(area, 3);
	establishShipsBOT(area, 2);
	establishShipsBOT(area, 2);
	establishShipsBOT(area, 1);
	establishShipsBOT(area, 1);
	establishShipsBOT(area, 1);
	establishShipsBOT(area, 0);
	establishShipsBOT(area, 0);
	establishShipsBOT(area, 0);
	establishShipsBOT(area, 0);
}
void establishShipsRandomlyOnPlayer(char area[][10]) {
	establishShipsPlayer(area, 3);
	establishShipsPlayer(area, 2);
	establishShipsPlayer(area, 2);
	establishShipsPlayer(area, 1);
	establishShipsPlayer(area, 1);
	establishShipsPlayer(area, 1);
	establishShipsPlayer(area, 0);
	establishShipsPlayer(area, 0);
	establishShipsPlayer(area, 0);
	establishShipsPlayer(area, 0);
}
void printSimpleArre(char Arrea[][10])
{
	cout << endl << endl;
	cout << "BOT battle Arrea: (Y -> , X ^ )" << endl;
	cout << "   0 1 2 3 4 5 6 7 8 9" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i << "  ";
		for (int j = 0; j < 10; j++)
		{
			cout << Arrea[i][j] << " ";
		}
		cout << endl;
	}
}

void addDataToFile(FILE* file, const char* name, int points, bool isEnd = false) {
	fopen_s(&file, "PLAYERS.txt", "a");


	fprintf_s(file, "%s %i\n", name, points);


	fclose(file);
}


void readDataFromFile(FILE* file) {
	fopen_s(&file, "PLAYERS.txt", "r");
	char name[20];
	int count = 0;
	int points;

	while (fscanf_s(file, "%s %i", name, sizeof(name), &points) > 0) {
		count++;
		cout << "\n\n\n\n\n\t\t\t\tPLAYER : " << count << " -> Name: " << name << "\t POINTS: " << points << endl;
	}

	fclose(file);
}




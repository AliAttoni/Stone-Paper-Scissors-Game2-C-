#include<iostream>
#include<time.h>
#include<time.h>
using namespace std;
enum enUserChoice{ stone = 1 , paper = 2 , scissors = 3 };

bool ReadCharcter(string Message)
{
	char InputChar = 'a';
	cout << Message;
	cin >> InputChar;
	if (InputChar == 'y' || InputChar == 'Y') {
		system("Cls");
		return true;
	}
	else if (InputChar == 'n' || InputChar == 'N') {
		cout << "\n\nThe Game is Finish\n\n";
		return false;
	}
}

struct FinalInfo
{
	int WinTimes = 0 ; 
	int LoseTimes = 0;
	int DrawTimes = 0;
};

struct stInfoGame
{
	int UserChoice = 0;
	int ComputerChoice = 0;
	string StuteGame;
	FinalInfo OneGame;
};

short RandomAcces(int from, int to)
{
	short Random = rand() % (to - from + 1) + from;
	return Random;
}

int ReadNumber(string Message)
{
	int Number;
	cout << Message;
	cin >> Number;
	return Number;
}

void GameProcessing(stInfoGame &Game)
{
	Game.UserChoice = ReadNumber("User Choice 1 stone , 2 paper , 3 scissors : ");
	Game.ComputerChoice = RandomAcces(1, 3);
	if (Game.UserChoice == 1 && Game.ComputerChoice == 2) {
		Game.StuteGame = "Lose User";
		Game.OneGame.LoseTimes++;
	}
	else if (Game.UserChoice == 2 && Game.ComputerChoice == 1) {
		Game.StuteGame = "Win User";
		Game.OneGame.WinTimes++;
	}
	else if (Game.UserChoice == 1 && Game.ComputerChoice == 3) {
		Game.StuteGame = "Win User";
		Game.OneGame.WinTimes++;
	}
	else if (Game.UserChoice == 3 && Game.ComputerChoice == 1) {
		Game.StuteGame = "Lose User";
		Game.OneGame.LoseTimes++;
	}
	else if (Game.UserChoice == 3 && Game.ComputerChoice == 2) {
		Game.StuteGame = "Win User";
		Game.OneGame.WinTimes++;
	}
	else if (Game.UserChoice == 2 && Game.ComputerChoice == 3) {
		Game.StuteGame = "Lose User";
		Game.OneGame.LoseTimes++;
	}
	else if (Game.UserChoice == Game.ComputerChoice) {
		Game.StuteGame = "Draw";
		Game.OneGame.DrawTimes++;
	}
}

enUserChoice UserChoice(int Number)
{
	switch (Number)
	{
	case 1 :
		return enUserChoice::stone;
	case 2:
		return enUserChoice::paper;
	case 3 :
		return enUserChoice::scissors;
	}
}

void WinMode()
{
	system("color 2f");
}

void LoserMode()
{
	cout << "\a";
	system("color 4f");
}

void DrawMode()
{
	system("color 6f");
}

void ModeGame(stInfoGame Game)
{
	if (Game.StuteGame == "Lose User")
	{
		cout << "Computer Choice : " << Game.ComputerChoice << endl;
		cout << "User Choice : " << Game.UserChoice << endl;
		cout << "Computer Win\n";
		LoserMode();
	}
	else if (Game.StuteGame == "Win User")
	{
		cout << "Computer Choice : " << Game.ComputerChoice << endl;
		cout << "User Choice : " << Game.UserChoice << endl;
		cout << "User Win\n";
		WinMode();
	}
	else
	{
		cout << "Draw\n";
		cout << "Computer Choice : " << Game.ComputerChoice << endl;
		cout << "User Choice : " << Game.UserChoice << endl;
		DrawMode();
	}
}

void PrintFinalyResult(stInfoGame Game)
{
	cout << "\n			------------------------------------------------\n";
	cout << "\n				Game Over						\n";
	cout << "\n			------------------------------------------------\n";
	cout << "			Win Times : " << Game.OneGame.WinTimes << endl;
	cout << "			Lose Times : " << Game.OneGame.LoseTimes << endl;
	cout << "			Draw Times : " << Game.OneGame.DrawTimes << endl;
	cout << "\n			------------------------------------------------\n";
}

void Game(int Number)
{
	stInfoGame Game;
	for (int i = 1; i <= Number; i++)
	{
		cout << "Round [" << i << "] Begin : \n";

		GameProcessing(Game);

		ModeGame(Game);

		cout << "\n_________________________________________________________\n";
	}
	PrintFinalyResult(Game);
}

int main()
{
	do {
		Game(ReadNumber("Enter Number from 1 to 10 : "));
		
	} while (ReadCharcter("Do you want to play Again? Y/N : "));
}
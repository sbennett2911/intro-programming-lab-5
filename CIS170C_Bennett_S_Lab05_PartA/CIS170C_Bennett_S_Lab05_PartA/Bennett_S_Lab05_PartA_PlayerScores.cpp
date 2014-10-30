/*Developer: Steven Bennett
	Assignment: Week 5 Lab 5 Part A Video Game Player Program
	Date: April 3, 2013*/

#include <iostream>
#include <string>
using namespace std;

//function prototypes
void InputData(string [], int [], int &);
void DisplayPlayerData(string [], int [], int);
double CalculateAverageScore(int [], int);
void DisplayBelowAverage(string [], int [], double, int);
const int SIZE = 100;

int main()
{
	//declare and initialize PlayerName[] and Score[]
	string PlayerName [SIZE] = {" "};
	int Score [SIZE] = {0};

	//declare numberOfPlayers and averageScore
	int numberOfPlayers = 0;
	double averageScore = 0;

	InputData(PlayerName, Score, numberOfPlayers);
	DisplayPlayerData(PlayerName, Score, numberOfPlayers);
	averageScore = CalculateAverageScore(Score, numberOfPlayers);
	DisplayBelowAverage(PlayerName, Score, averageScore, numberOfPlayers);


	return 0;
}

void InputData(string names[], int scores[], int &num)
{
	while (num < SIZE)
	{
		cout << "Enter player name (Q to Quit): ";
		getline(cin, names[num]);
		if ((names[num] == "Q") || (names[num] == "q"))
			break;
		else
		{
			cout << "Enter score for " << names[num] << ": ";
			cin >> scores[num];
		}
		
		cin.ignore();
		num++;
	}
}

void DisplayPlayerData(string names[], int score[], int num)
{
	cout << "\n\nName" << "       " << "Score" << endl;
	for (int i = 0; i < num; i++)
		cout << names[i] << "      " << score[i] << endl;
}

double CalculateAverageScore(int score[], int num)
{
	double total = 0;
	for (int i = 0; i < num; i++)
		total += score[i];
	double avg = total/num;
	cout << "\n\nThen average score is: " << avg;
	return avg;
}

void DisplayBelowAverage(string names[], int score[], double avg, int num)
{
	cout << "\n\nPlayers who scored below average" << endl;
	cout << "Name" << "     " << "Score" << endl;
	for (int i = 0; i < num; i++)
	{
		if (score[i] < avg)
			cout << names[i] << "      " << score[i] << endl;
	}
}
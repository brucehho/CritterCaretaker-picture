// P5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Critter Class
//Simulates caring for a virtual pet

#include <iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

//class definition -- defines a new type, Critter
class Critter
{
public:
	Critter(int hunger = 0, int boredom = 0);	//constructor
	void Talk();	//displays mood
	void Eat(int food = 5);	//reduces hunger level
	void Play(int fun = 5);	//reduces boredom level
	//performs a random trick, if happy
	void PerformTrick();
private:
	//mood levels
	enum Mood { HAPPY, OKAY = 5, FRUSTRATED = 10, MAD = 15 };
	//number of tricks
	static const int NUM_TRICKS = 3;
	static const string TRICKS[NUM_TRICKS];	//tricks
	int m_Hunger;
	int m_Boredom;
	string GetMood() const;		//returns mood
	//increases hunger, boredom levels
	void PassTime(int time = 1);
};

//tricks
const string Critter::TRICKS[NUM_TRICKS] = { "roll over", "jump","do a backflip" };

//constructor
Critter::Critter(int hunger, int boredom) : m_Hunger(hunger), m_Boredom(boredom)
{
}

//returns mood
string Critter::GetMood() const
{
	string mood;
	if (m_Hunger + m_Boredom > MAD)
		mood = "mad";
	else if (m_Hunger + m_Boredom > FRUSTRATED)
		mood = "frustrated";
	else if (m_Hunger + m_Boredom > OKAY)
		mood = "okay";
	else
		mood = "happy";
	return mood;
}

//increases hunger and boredom levels
void Critter::PassTime(int time)
{
	m_Hunger += time;
	m_Boredom += time;
}

//dipalys mood
void Critter::Talk()
{
	cout << "I'm a critter and I feel " << GetMood() << "." << endl;
	PassTime();
}

//reduces hunger level
void Critter::Eat(int food)
{
	cout << "Brruppp." << endl;
	m_Hunger -= food;
	if (m_Hunger < 0)
	{
		m_Hunger = 0;
	}
	PassTime();
}

//reduces boredom level
void Critter::Play(int fun)
{
	cout << "Wheee!" << endl;
	m_Boredom -= fun;
	if (m_Boredom < 0)
	{
		m_Boredom = 0;
	}
	PassTime();
}

//perform a random trick, if happy
void Critter::PerformTrick()
{
	//if not happy, no trick
	if (GetMood() != "happy")
	{
		cout << "I dont feel like doing a trick." << endl;
	}
	//perform a trick
	else
	{
		//random index number
		int choice = (rand() % NUM_TRICKS);
		//trick to perform
		string trick = TRICKS[choice];
		cout << "I " << trick << "." << endl;
	}
	PassTime();
}

int main()
{
	srand(static_cast<unsigned int> (time(0)));
	Critter crit;
	int choice;
	do
	{
		cout << endl << "Critter Caretaker" << endl;
		cout << "---------------------" << endl << endl;
		cout << "0 - Quit" << endl;
		cout << "1 - Listen to your critter" << endl;
		cout << "2 - Feed your critter" << endl;
		cout << "3 - Play with  your critter" << endl;
		cout << "4 - Ask your critter to perform a trick." << endl;

		cout << "Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "Good-bye." << endl;
			break;
		case 1:
			crit.Talk();
			break;
		case 2:
			crit.Eat();
			break;
		case 3:
			crit.Play();
			break;
		case 4:
			crit.PerformTrick();
			break;
		default:
			cout << endl << "Sorry, but " << choice;
			cout << " isn't a valid choice." << endl;
		}
	} while (choice != 0);
	return 0;
}
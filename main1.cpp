#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>

using namespace std;
// Generate Random variables function
void GenerateRandomVariables(int tempNumDigits, vector <int>& userInput)
{
	int i=0;
	int randomNum = 0;
	bool repeat = false;
	
	while(userInput.size() < tempNumDigits - 1)
	{
		randomNum = rand() % 10;
		
		for(i = 0; i < userInput.size(); ++i)
		{
			if(randomNum == userInput.at(i))
				repeat = true;
		}
		
		if(repeat == false)
		{
			userInput.push_back(randomNum);
		}
		else
			repeat = false;		
	}

}

void printvector(vector <int> userInput)
{
	int i = 0;
	
	//Display the number to guess with dashes between it.
	cout << "Number to guess: " << userInput.at(0);
	for (i; i < userInput.size(); ++i)
      cout << "-" << userInput.at(i);
	
}
void pushBackGuess(int guess,int tempNumDigits, vector <int>& userGuess)
{
	int i = 0;
	int temp = 0;
	vector <int> guessTemp;
	
	while(guessTemp.size() < tempNumDigits)
	{
		temp = guess % 10;
		guessTemp.push_back(temp);
		guess = guess / 10;
					
	}
	for(i = guessTemp.size(); i >= 0; --i)
	{
		userGuess.push_back(guessTemp.at(i));
	}
}


// Find bull function
void findBullCows(vector <int> userInput, vector <int>& userGuess)
{
	int i = 0;
	int j = 0;
	int cows = 0;
	int bulls = 0;
	
	for(i; i < userInput.size(); ++i)
	{
		if(userInput.at(i) == userGuess.at(i))
		{
			bulls = bulls++;
		}
		
		for(j; j < userInput.size(); ++j)
		{
			if(userInput.at(i) == userGuess.at(j) && userInput.at(i) != userGuess.at(i))
			{
				cows = cows++;
			}
		}
	}
	
	cout << bulls << " bulls" << endl;
	cout << cows << " cows" << endl;	
}


int main() 
{
	// Default for random number generator
	srand(std::chrono::duration_cast<std::chrono::milliseconds>
     (std::chrono::system_clock::now().time_since_epoch()).count()%2000000000); 
    // needed to autograde some test cases in Mimir
	
	// Declare and initialize variables
	vector <int> userInput; 
	vector <int> userGuess;
	int numDigits = 0;
	int numToGuess = 0;
	
	// Get the number of digits for the guess
	cout << "Enter number of digits in code (3, 4 or 5): ";
	cin >> numDigits;
	cout << endl;
	
	// If the user enters an invalid input ask the question again
	while(numDigits != 0 && numDigits != 3 && numDigits != 4 && numDigits != 5)
	{
		cout << "Enter number of digits in code (3, 4 or 5): ";
		cin >> numDigits;
		cout << endl;
	}
	
	
	// if 0 is the input for the code then 
	if(numDigits == 0)
	{
		int tempNumDigits = 0;
		int guess = 0;
		
		// Enter the code and num of digits in the code
		cout << "Enter code: ";
		cin >> guess;
		cout << "Enter number of digits in code: ";
		cin >> tempNumDigits;
		
		while(numDigits != 3 && numDigits != 4 && numDigits != 5)
		{
			cout << "Enter number of digits in code (3, 4 or 5): ";
			cin >> numDigits;
			cout << endl;
		}
		// push back the number guessed into an array.
		pushBackGuess(guess, tempNumDigits, userGuess);
		
		
		// call the print function
		printvector(userGuess);
		cout << endl;
		
		findBullCows(userInput, userGuess);
		
	}
	else if(numDigits == 3)
	{
		int tempNumDigits = 3;
		int guess = 0;
		GenerateRandomVariables(tempNumDigits, userInput);
		
		// call the print function
		printvector(userInput);
		
		cout << endl;
		
		cout << "Enter Guess: ";
		cin >> guess;
		
		// if the guess is within the parameters of the length of the num of digits in code
		while(userGuess.size() != tempNumDigits)
		{
			cout << "You can only enter " << tempNumDigits << " digits." << endl;
			cout << "Enter Guess: ";
			cin >> guess;
		}
		// push back the number guessed into an array.
		pushBackGuess(guess, tempNumDigits, userGuess);
		
		// Display No of cows and bulls
		findBullCows(userInput, userGuess);

	}
	else if(numDigits == 4)
	{
		int tempNumDigits = 4;
		int guess = 0;
		
		GenerateRandomVariables(tempNumDigits, userInput);
		
		// call the print function
		printvector(userInput);
		
		cout << endl;
		
		cout << "Enter Guess: ";
		cin >> guess;
		// if the guess is within the parameters of the length of the num of digits in code
		while(guess != tempNumDigits)
		{
			cout << "You can only enter " << tempNumDigits << " digits." << endl;
			cout << "Enter Guess: ";
			cin >> guess;
		}
		// push back the number guessed into an array.
		pushBackGuess(guess, tempNumDigits, userGuess);
		
		// Display No of cows and bulls
		findBullCows(userInput, userGuess);
	}	
	else if(numDigits == 5)
	{
		int tempNumDigits = 5;
		int guess = 0;
		
		// Generate a random variable in the range of numbers
		GenerateRandomVariables(tempNumDigits, userInput);
		//numToGuess = tempNumDigits;
		
		// call the print function
		printvector(userInput);
		
		cout << endl;
		
		cout << "Enter Guess: ";
		cin >> guess;
		
		// push back the number guessed into an array.
		pushBackGuess(guess, tempNumDigits, userGuess);
		
		// if the guess is within the parameters of the length of the num of digits in code
		while(userGuess.size() != tempNumDigits-1)
		{
			cout << "You can only enter " << tempNumDigits << " digits." << endl;
			cout << "Enter Guess: ";
			cin >> guess;
		}
		
				
		findBullCows(userInput, userGuess);
		
		
	}
	
}



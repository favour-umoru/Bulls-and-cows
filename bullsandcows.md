#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <cmath>

using namespace std;
// Generate Random variables function
void GenerateRandomVariables(int numDigits, vector <int>& userInput)
{
	int i=0;
	int randomNum = 0;
	bool repeat = false;
	
	while(userInput.size() < numDigits)
	{
		randomNum = rand() % 10;
		
		for(i = 0; i < userInput.size(); ++i)
		{
			if(randomNum == userInput.at(i))
			{
				repeat = true;
			}
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
	int i = 1;
	
	//Display the number to guess with dashes between it.
	cout << "Number to guess: " << userInput.at(0);
	for (i; i < userInput.size(); ++i)
      cout << "-" << userInput.at(i);
	
}
void printvectorDash(vector <int> userInput)
{
	int i = 1;
	
	//Display the number to guess with dashes between it.
	cout << userInput.at(0);
	for (i; i < userInput.size(); ++i)
      cout << "-" << userInput.at(i);
	
}
void pushBackGuess(int guess,int numDigits, vector <int>& userGuess)
{
	int i = 0;
	int temp = 0;
	vector <int> guessTemp;
	
	while(guessTemp.size() < numDigits)
	{
		temp = guess % 10;
		guessTemp.push_back(temp);
		guess = guess / 10;
					
	}
	for(i = guessTemp.size()-1; i >= 0; --i)
	{
		userGuess.push_back(guessTemp.at(i));
	}
}


// Find bull function
bool findBullCows(vector <int> userInput, vector <int>& userGuess, int numDigits)
{
	int i = 0;
	int j = 0;
	int cows = 0;
	int bulls = 0;
	
	for(i = 0; i < userInput.size(); ++i)
	{
		if(userInput.at(i) == userGuess.at(i))
		{
			bulls++;
		}
		
		for(j = 0; j < userInput.size(); ++j)
		{
			if(userInput.at(i) == userGuess.at(j) && userInput.at(i) != userGuess.at(i))
			{
				cows++;
			}
		}
	}
	
	

	if(bulls == numDigits)
	{
		cout << bulls << " bulls... "; 
		printvectorDash(userInput);
	    cout << " is correct!"<< endl;
	    return false;
	}
	else
	{
		cout << bulls << " bulls" << endl;
		cout << cows << " cows" << endl;
		return true;
	}
	

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
	
	// Get the number of digits for the guess
	cout << "Enter number of digits in code (3, 4 or 5): ";
	cin >> numDigits;
	
	// If the user enters an invalid input ask the question again
	while(numDigits != 0 && numDigits != 3 && numDigits != 4 && numDigits != 5)
	{
		cout << endl;
		cout << "Enter number of digits in code (3, 4 or 5): ";
		cin >> numDigits;
		
	}
	
	
	// if 0 is the input for the code then 
	int guess = 0;
	int i = 0;
	int j = 0;
	bool repeat = false;

	if (numDigits == 0) 
	{
		// Enter the code and num of digits in the code
		cout << "Enter code: ";
		cin >> guess;
		cout << "Enter number of digits in code: ";
		cin >> numDigits;
	
		// push back the number guessed into an array.
		pushBackGuess(guess, numDigits, userInput);
	}
	else 
	{
		GenerateRandomVariables(numDigits, userInput);
	}
		
	// call the print function
	printvector(userInput);
	cout << endl;
	
	do 
	{
		repeat = false;
		userGuess.clear();
		cout << "Enter Guess: ";
		cin >> guess;

		// push back the number guessed into an array.
		pushBackGuess(guess, numDigits, userGuess);

		// if the guess is within the parameters of the length of the num of digits in code
		if((guess/pow(10,numDigits)) >= 1.0)
		{
			cout << "You can only enter " << numDigits << " digits." << endl;
			repeat=true;
		}
		else{
			for(i = 0; i < userInput.size(); ++i)
			{
				for(j=0; j < userInput.size(); ++j){
					if(userGuess.at(i) == userGuess.at(j))
					{
						if(i != j)
						{
							if (repeat == false)
								cout << "Each number must be different." << endl;
							repeat = true;
							break;
						}
						
					}
				}

			}
		}
		if(!repeat)
			repeat = findBullCows(userInput, userGuess, numDigits);
	} while(repeat == true);
	
}

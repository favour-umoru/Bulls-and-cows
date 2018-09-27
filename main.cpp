#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>

using namespace std;

int main() {
	
	// Default for random number generator
	srand(std::chrono::duration_cast<std::chrono::milliseconds>
     (std::chrono::system_clock::now().time_since_epoch()).count()%2000000000); 
    // needed to autograde some test cases in Mimir
	
	// Declare and initialize variables
	vector <int> userInput;
	int numDigits = 0;
	int code = 0;
	int numToGuess = 0;
	int tempNumDigits = 0;
	
	// Get the number of digits for the guess
	cout << "Enter number of digits in code (3, 4 or 5): ";
	cin >> numDigits << endl;
	
	// If the user enters an invalid input ask the question again
	while(numDigits != 0 || numDigits != 3 || numDigits != 4 || numDigit != 5)
	{
		cout << "Enter number of digits in code (3, 4 or 5): ";
		cin >> numDigits << endl;
	}
	
	// Push back the value of the number entered into vector userInput
	//userInput.pushback(numDigits);
	
	
	// if 0 is the input for the code then 
	if(numDigits == 0)
	{
		int tempNumDigits = 0;
		int code = 0;
		int codeLength = 0;
		// Enter the code and num of digits in the code
		cout << "Enter code: ";
		cin >> code;
		cout << "Enter number of digits in code: ";
		cin >> tempNumDigits;
		
		if(code.length < tempNumDigits)
		{
			
		}
		else if (code.length == tempNumDigits)
		{
			
			
		}
		else
		{
			
		}
		
	}
	else if(numDigits == 3)
	{
		int tempNumDigits = 3;
		int guess = 0;
		int guessLength = 0;
		GenerateRandomVariables(tempNumDigits);
		numToGuess = tempNumDigits;
		
		cout << "Enter Guess: ";
		// if the guess is within the parameters of the length of the num of digits in code
		while(guess != tempNumDigits)
		{
			cout << "You can only enter " << tempNumDigits << " digits." << endl;
			cout < "Enter Guess: ";
			cin >> guess;
		}
		
	}
	else if(numDigits == 4)
	{
		int tempNumDigits = 4;
		int guess = 0;
		int guessLength = 0;
		
		GenerateRandomVariables(tempNumDigits);
		numToGuess = tempNumDigits;
		
		cout << "Enter Guess: ";
		// if the guess is within the parameters of the length of the num of digits in code
		while(guess != tempNumDigits)
		{
			cout << "You can only enter " << tempNumDigits << " digits." << endl;
			cout < "Enter Guess: ";
			cin >> guess;
		}
		
	}	
	else if(numDigits == 5)
	{
		int tempNumDigits = 5;
		int guess = 0;
		int guessLength = 0;
		
		// Generate a random variable in the range of numbers
		GenerateRandomVariables(tempNumDigits);
		numToGuess = tempNumDigits;
		
		cout < "Enter Guess: ";
		// if the guess is within the parameters of the length of the num of digits in code
		while(guess != tempNumDigits)
		{
			cout << "You can only enter " << tempNumDigits << " digits." << endl;
			cout < "Enter Guess: ";
			cin >> guess;
		}

		
		
	}
	// cout the results
	
    
}


// Generate Random variables function
void GenerateRandomVariables(int& tempNumDigits)
{
	int i = 1;
	
	//Display the number to guess with dashes between it.
	cout << "Number to guess: " << tempNumDigits.at(0);
	for (i; i < tempNumDigits.size(); ++i)
      cout << "-" << tempNumDigits.at(i); 
}

// Find bull function
int findBull(int numToGuess, int guess)
{
	int bull;
	
	
	return bull;
}
// Find cow function
int findCow(int numToGuess, int guess)
{
	int cow;
	
	
	return cow;
}



// Do I need a find length or not?????????

















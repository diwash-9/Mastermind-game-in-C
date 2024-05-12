#include <iostream>
#include <random>
#include <ctime>
#include<string.h>
using namespace std;

bool hasRepeatingDigits(int number) {	
// This is a boolean function, taking one argument, meaning it returns either a true or a false value
// This function checks if the randomly generated 3 digit number has repeating digits
   int digitCount[10] = {0};
   while (number > 0) {
        int digit = number % 10;
        if (digitCount[digit] > 0) {
            return true; // If there are repeating digits even once, the function returns true and ends then and there
        }
        digitCount[digit]++;
        number /= 10;
    }
    return false; // If there are no repeating digits, the function returns false
}
bool containsDigit(int number, char targetDigit) { 
/*
This is also a boolean function
This function checks if the user input contains any of the digit in the password generated randomly
It takes two arguments, one, the randomly generated password and the other, one of the digits from the user input
*/
    while (number > 0) {
        int target = targetDigit - '0';
        int digit = number % 10;
        if (digit == target) {
            return true; // returns true if user input is in the password generated
        }
        number /= 10;
    }
    return false; // returns failse if user input is not in the password generated
}
void checkAvailability(int number, int guess)
// Checks if the containing digit is in the right place or the wrong one
// Takes two arguments, one, the generated password, and other the user's guess
{
    string guessString = to_string(guess); // converts the user guess into a string of characters so we can iterate over it easily
    string numberString = to_string(number); // converts the randomly generated password into a string of characters so we can iterate over it easily
    for(int i=0;i<numberString.length();i++)
    {
        
        if(containsDigit(number,guessString[i])) // calls the containsDigit() function and if true, checks if the digit is in the right place
        {
            if(guessString[i] == numberString[i])
        {
            cout<<"Green"<<endl; // If guessed digit is in the right place, it outputs green on the console
            continue; // It ends the void function
        }
        if(guessString[i] != numberString[i]){
            cout<<"Orange"<<endl; // If guessed digit is in the wrong place, it outputs orange on the console
        }
        return; // It ends the void function
        }
    }
     cout<<"Red"<<endl; // If guessed digit is not in the password, it outputs red on the console
}
int randomGenerator() 
// This creates a random combination of three digits as a password and returns an integer value
{
    mt19937 generator(std::time(nullptr)); // Seed the generator with the current time
    uniform_int_distribution<int> distribution(0, 9);

    int gameNumber = 1; // Starting from 1 because, if started with zero, it will only create a two digit integer
    for (int i = 0; i < 2; i++) {
        int randomNumber = distribution(generator);
        gameNumber = gameNumber * 10 + randomNumber;
    }
	
    return gameNumber; // Returns the randomly generated password
}

int main() {
	A: 
    int ourNumber = randomGenerator(); // Storing the password in the main function with ourNumber variable
    if(hasRepeatingDigits(ourNumber)) // Calls hasRepeatingDigiys(n) function with ourNumber as argument to check if digits are repeating
    {
    	goto A;	// If true, goto statement takes the program control to the statement in line 77 to create another password
	}
    cout << ourNumber << endl; // To be removed once the code is finalized
    
    // Computer instructions to players
	cout<<"When I say: Green, That means One digit is correct and is in the right position. "<<endl;
    cout<<"When I say: Orange, That means One digit is correct and is in the wrong position. . "<<endl;
    cout<<"When I say: Red, No digit is correct. "<<endl;
    cout<<"I have thought up a number. You have 10 guesses to get it."<<endl;
    
    int userGuess;
    int count = 10;
   
    	for(int i=0;i<10;i++)
    {
        cout<<"Enter a three digit number"<<endl;
        cin>>userGuess; // Stores the user guess in userGuess variable, and is run for 10 times until the userGuess is correct
        if(userGuess == ourNumber)
        {
            cout<<"You got it !!!! You won a chest full of gold and you may pass to the next game. Be prepared, you have a princess to save. Have a nice play!"<<endl; 
// If the user guesses the right answer
            break; // Breaks the loop and exits to winning message
        }
        
        else{
		checkAvailability(ourNumber,userGuess); // If guess is not correcet, calls checkAvailability(n,m) function to check the availability of digits in the password
    }
    count--;
    cout<<"Remaining trials "<<count<<endl;
 	 if(count==0) 
  {
  	cout<<"You didn't get the number in 10 trials, goodBye!!!"<<endl; 
	  break; 
  }
}
   


return 0;

}


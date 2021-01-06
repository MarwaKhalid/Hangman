#include <iostream>
#include <cstdlib>
#include <ctime>
#include "hangman.h"
using namespace std;

int main() {
	/* Declaring variables*/
	int counter = 0; // declaring int variable called counter and initializing to zero
	string words[] = { "hello", "banana", "game", "water", "season", "school" }; // creating an array with the words
	srand((unsigned)time(0)); // helps the computer not generate the same number
	int index = rand() % 6; // generating an number between 0 and 5 inclusively
	string wrd = words[index]; // storing the word from the array
	string* array = new string[wrd.length()]; // using pointer to make the array, because dynamic array, length of the word
	char letter; // declaring char called letter
	string answer; // declaring string called answer
	string guessedLetters; // declaring string called guessedLetters
	string word; // declaring string called word
	bool winner = false; // declaring boolean called winner
	bool letterFound; // declaring boolean called letterFound

	/* Beginning game */ 
	cout << "Welcome to Hangman\n\nHere are the rules:"
		<< "\n1. The computer will generate a word, and display each letter as \"_\""
		<< "\n2. You must guess the letters, every incorrect letter will add to the hangman figure."
		<< "\n3. You have in total 6 tries, after the 6th try the hangman dies."
		<< "\n4. If you call a letter you've already called that also adds to the hangman figure."
		<< "\n5. After having guessed a letter, you may attempt to guess the entire word, if correct the game will end."
		<< "\nElse, another limb would be added to the figure.\n\nLets begin!";
	display(counter); // calling the display method
	cout << "\nHere is the word to guess: ";

	// loop to print as many _ as the number of characters in the word
	for (int i = 0; i < wrd.length(); i++) {
		array[i] = "_"; // filling the array with _
		cout << " " << array[i]; // printing the array
	}

	do { // loop until winner becomes true
		bool addToGuessLetters = true; // declaring bool called addToGuessLetters and setting to true
		bool allLettersFound = true; // declaring bool called allLettersFound and setting to true
		letterFound = false; // letterFound becomes false

		cout << "\nGuess a letter: ";
		cin >> letter; // storing the letter

		// loop to see if the letter has already been called or not
		for (int i = 0; i < guessedLetters.length(); i++) {
			if (guessedLetters[i] == letter) { // if letter exists in the string guessedLetters
				cout << "Sorry, you've already called this letter!\n";
				addToGuessLetters = false; // addToGuessLetters becomes false
			}
		}
		if (addToGuessLetters) // if true
			guessedLetters += letter; // adding to the guessedLetters
		cout << "Here are the guessed letters: ";

		// loop to print the guess letters
		for (int i = 0; i < guessedLetters.length(); i++)
			cout << guessedLetters[i];

		cout << "\n\nHere is the word to guess: ";

		for (int i = 0; i < wrd.length(); i++) {
			if (wrd[i] == letter) { // if the letter is found in the word
				array[i] = wrd[i]; // adding the letter into the array at the same location
				cout << " " << array[i]; // printing the letter
				if (addToGuessLetters) // if the letter hasnt been previously called
					letterFound = true; // letterFound becomes true
			}
			else // if letter isnt found
				cout << " " << array[i];
		}

		for (int i = 0; i < wrd.length(); i++) {
			if (array[i] == "_") { // if the array contains underscore
				allLettersFound = false; // allLettersFound becomes false
			}
		}

		if (allLettersFound) { // if true
			cout << "\n\nYou've won!";
			break; // break out of loop
		}
		cout << "\nWould you like to guess the word? Please enter y/n: ";
		cin >> answer; // storing in string: answer

		if (answer == "y") { // if the user entered y
			cout << "\nEnter the word: ";
			cin >> word; // storing the word in string: word

			if (word == wrd) { // if same word
				cout << "\nYou guessed correct!";
				break; // break out of loop
			}
			else { // if not the same word
				cout << "\nYou guessed incorrect!";
			}
		}
		if (letterFound == false) // if letterFound is false
			counter++; // counter increases
		display(counter); // calling the display method

		if (counter == 6) // if counter is 6
			break; // break out of loop

	} while (winner != true);
	cout << "\nThank you for playing hangman!";
	return 0;
}

// method to display the hangmang
static void display(int count) {
	int i = 0; // declaring int called i and initializing to zero
	cout << "\n     ________"
		<< "\n    | 	    |";

	if (count > 0) { // if the count is bigger than 0
		if (count == 1) { // if count is 1
			cout << "\n    |	    O";
			loop(i + 1); // calling the loop method
		}
		if (count == 2) { // if count is 2
			cout << "\n    |	    O"
				<< "\n    |	    |\n    |	    |";
			loop(i + 3); // calling the loop method
		}
		if (count == 3) { // if count is 3
			cout << "\n    |	    O"
				<< "\n    |	   \\|\n    |	    |";
			loop(i + 3); // calling the loop method
		}
		if (count == 4) { // if count is 4
			cout << "\n    |	    O"
				<< "\n    |	   \\|/\n    |	    |";
			loop(i + 3); // calling the loop method
		}
		if (count == 5) { // if count is 5
			cout << "\n    |	    O"
				<< "\n    |	   \\|/\n    |	    |"
				<< "\n    |	   /";
			loop(i + 5); // calling the loop method
		}
		if (count == 6) { // if count is 6
			cout << "\n    |	    O"
				<< "\n    |	   \\|/\n    |	    |"
				<< "\n    |	   / \\";
			loop(i + 5); // calling the loop method
			cout << "\n\nYou've lost!";
		}
	}
	else // if the count is 0
		loop(i);
}

// method to print straight lines
static void loop(int i) {
	for (i; i < 4; i++)
		cout << "\n    |";
	cout << "\n___ | ___";
}
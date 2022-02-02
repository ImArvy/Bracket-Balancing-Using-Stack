/*
Ryan Vales
Date: 5/3/21
CSCI 3400
HW3
*/
#include<iostream>
#include<fstream>
#include<stack>
#include<string>

using namespace std;

// This function checks if an expression of brackets is balanced or not.
bool bracketsAreBalanced(string fileLine) { 
	stack<char> bracketStack; // Create a stack that contains data of char type.
	char currentBracket; // Create char value currentBracket primarily to be used in built-in top() function as well as in a conditional statement.
	int stackSize; // Create variable that will hold the size returned from stack() built-in function.

	for (int i = 0; i < fileLine.length(); i++) { // While in range from index 0 to the length of the line ebing read from the file.
		if (fileLine[i] == '(' || fileLine[i] == '[' || fileLine[i] == '{') { // If the character at the index is an opening bracket.
			bracketStack.push(fileLine[i]); // Push the opening bracket to the stack.
			stackSize = bracketStack.size(); // Variable stackSize intitialized to the value of the current size of the stack.
			cout << stackSize << " "; // Output the current size of the stack.
			continue; // Go to the next iteration in the loop to check if the next index contains an opening bracket.
		}
		switch (fileLine[i]) { // Switch statement is used to here to test the current index against the three cases of closing brackets.
		case ')': // If the current index contains the value of ')'
			if (bracketStack.size() != 0) { // If the stack size is not zero, I use this so as not to pop from an empty stack.
				currentBracket = bracketStack.top(); // Assign the value of the top of the stack to variable currentBracket.
				bracketStack.pop(); // Pop the value at the top of the stack.
				stackSize = bracketStack.size(); // Variable stackSize intitialized to the value of the current size of the stack.
				cout << stackSize << " "; // Output the current size of the stack.
				if (currentBracket == '{' || currentBracket == '[') { // If the top of the stack has the value of either '{' or '['.
					return false; // Return boolean value false so it is known the expression is not balanced.
				}
			} else { // If condtion (bracketStack.size() != 0) is not true.
				return false; // Return boolean value false so it is known the expression is not balanced.
			}
			break; // Terminate this case in the switch statement and move to the next case.
		case '}': // If the current index contains the value of '}'
			if (bracketStack.size() != 0) { // If the stack size is not zero.
				currentBracket = bracketStack.top(); // Assign the value of the top of the stack to variable currentBracket.
				bracketStack.pop(); // Pop the value at the top of the stack.
				stackSize = bracketStack.size(); // Variable stackSize intitialized to the value of the current size of the stack.
				cout << stackSize << " "; // Output the current size of the stack.
				if (currentBracket == '(' || currentBracket == '[') { // If the new top of the stack has the value of either '(' or '['.
					return false; // Return boolean value false so it is known the expression is not balanced.
				}
			} else { // If condtion (bracketStack.size() != 0) is not true.
				return false; // Return boolean value false so it is known the expression is not balanced.
			}
			break; // Terminate this case in the switch statement and move to the next case.
		case ']': // If the current index contains the value of ']'
			if (bracketStack.size() != 0) { // If the stack size is not zero.
				currentBracket = bracketStack.top(); // Assign the value at the top of the stack to variable currentBracket.
				bracketStack.pop(); // Pop the value at the top of the stack.
				stackSize = bracketStack.size(); // Variable stackSize intitialized to the value of the current size of the stack.
				cout << stackSize << " "; // Output the current size of the stack.
				if (currentBracket == '(' || currentBracket == '{') { // If the new top of the stack has the value of either '(' or '['.
					return false; // Return boolean value false so it is known the expression is not balanced.
				}
			} else { // If condtion (bracketStack.size() != 0) is not true.
				return false; // Return boolean value false so it is known the expression is not balanced.
			}
			break; // Terminate this case in the switch statement.
		}
	}
	return (bracketStack.empty()); // Return true if the stack is empty, AKA the expression is balanced, and false if it is not empty, or if the expression is not balanced.
}

// Main function
int main() { 
	ifstream inputFile; // Create ifstream and pass variable inputFile to it.
	string fileName; // Create a variable of string data type called fileName to hold the name of the file.
	string fileLine; // Create a variable of string data type called fileLine to hold the value of the current line in the input file.

	cout << "Enter the file name to have its expressions evaluated: "; // Ask the user to input the name of the file they wish to test with the program.
	cin >> fileName; // Enter the name of the file to be tested.
	cout << "\n";

	inputFile.open(fileName); // Open the test file.
	if (inputFile.is_open()) { // If the test file is open.
		while (getline(inputFile, fileLine)) { // While there are lines in the file for the program to read.
			cout << fileLine << endl; // Output the expression of brackets on the current line.
			if (bracketsAreBalanced(fileLine)) { // If the expression of brackets is balanced, AKA if the function returns true becuase the stack is empty after the function processes the current line.
				cout << "\nThis expression is balanced.\n" << endl; // Output to the user that the expression is balanced.
			} else { // If the expression of brackets is not balanced due to any of the conditions that return false in the function.
				cout << "\nThis expression is not balanced.\n" << endl;	// Output to the user that the expression is not balanced.
			}
		}
		inputFile.close(); // Close the file now that it is done being read and the data it contains is done being processed by the function.
	}

	return 0; // Return statment to end the program.
}
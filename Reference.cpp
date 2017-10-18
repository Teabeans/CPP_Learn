#include <iostream> // The input/output library (iostream) - A family of class templates and supporting functions in the Standard Library that implement stream-based input/output capabilities.
#include <vector> // Vectors are sequence containers representing arrays that can change in size.
#include <string> // The C++ strings library includes support for three general types of strings: std::basic_string, std::basic_string_view, and Null-terminated strings
#include <fstream> // Header providing file stream classes: basic_ifstream, basic_ofstream, basic_fstream, basic_filebuf

using namespace std;
// using : You are going to use it
// namespace : To use what? A namespace
// std: The std namespace (where features of the C++ Standard Library, such as string or vector, are declared).
// After you write this instruction, if the compiler sees string it will know that you may be referring to std::string, and if it sees vector, it will know that you may be referring to std::vector. (Provided that you have included in your compilation unit the header files where they are defined, of course.)

// 30:21 - Functions - Header for the function must appear before main(). This is the user of including the .h file.
// <return type> <name>(<arg1Type> <arg1Name>, <arg2Type> <arg2Name>) {}
// Can initialize a default value to arguments, but pre-initialized arguments just need to be listed last
int addNumbers(int firstNum, int secondNum = 0) {
	int combinedValue = firstNum + secondNum;
	return combinedValue;
}
// Overloading: Same function name with different attributes (arguments).

// 33:00 - Recursive functions
int getFactorial(int number) {
	int sum;
	if (number == 1) {
		sum = 1;
	}
	else {
		sum = (getFactorial(number - 1)) * number;
	}
	return sum;
}

// Your executable code is going to go inside main(). Note that it should return an integer.
int main() {

	// 32:11 - Function calling
	cout << "addNumber() result: " << addNumbers(1) << endl; // Expected: 1

	// 33:48 - Recursive function call
	cout << "getFactorial() result: " << getFactorial(10) << endl;




	// :: Scope Resolution Operator, follows format of <Class Scope>::<Variable Name>
	// std::cout; // Because 'using namespace std;' is included in the header, we can omit 'std::', that is the namespace we'll use by default.
	// The above line becomes:
	// cout;
	// But this doesn't do anything, so let's send 'Hello World' to cout
	cout << "Hello World" << endl;

	// VARIABLES:
	const double PI = 3.1415926535;
	// const : A variable that cannot be changed
	// name : Should be all upper case if a 'const' (FINAL) variable
	
	char myGrade = 'A';
	// char - Defined by one byte, surrounded by single quotes
	
	bool isHappy = true;
	// bool - boolean values, true or false. Naming convention is to use 'is' in front of the variable

	int myAge = 33;
	// int - Number with no decimals, from -2147483648 to 2147483647

	float favNum = 3.141592;
	// float - 

	double otherFavNum = 1.6180339887;
	// double - 

	cout << "Size of int " << sizeof(myAge) << endl;
	
	// ARITHMETIC OPERATORS:
	// +, - - Add, subtract
	// *, / - Multiply, divide
	// % - Modulus
	// ++, -- - Increment, decrement

	// Time - 6:37

	int five = 5;

	// The variable 'five' will be passed first, then incremented to 6.
	cout << five++ << endl;
	
	five += 6; // Same as five = five + 6; Pronounced "<Variable> increments by <Amount>"

	// 8:00 - Order of operations
	// * and / is performed before + and -
	// Takeaway, use braces liberally.

	// 9:00 - Casting
	cout << "Uncast: " << 4 / 5 << endl;
	cout << "Float Cast: " << (float) 4 / 5 << endl;
	cout << "Uncast float: " << 4.0 / 5 << endl; // Dividing an int by a float (or vice versa) puts the result in float form.

	// 9:30 - If-then statements
	// Comparison operators: == (equals), != (not equals), > (greater than), < (less than), >= (greater than or equal to), <= (less than or equal to)
	// Logical operators: && (and), || (or), ! (not)

	int age = 70;
	int ageAtLastExam = 16;
	bool isNotIntoxicated = true;

	if ((age >= 1) && (age < 16)) {
		cout << "You can't drive" << endl;
	}
	else if (!isNotIntoxicated) {
		cout << "You can't drive" << endl;
	}
	else {
		cout << "You can drive" << endl;
	}

	// 12:00 - Switches
	int greetingOption = 2;

	switch (greetingOption) {
		case 1: // If the switch argument == 2, then do the following:
			cout << "bonjour" << endl;
			break; // Include the break to exit the switches entirely, otherwise all subsequent cases will be checked.
		case 2: // If the switch argument == 2, then do the following:
			cout << "hola" << endl;
			break;
		default: // Default condition behavior if none of the other switches match.
			cout << "hello" << endl;
			// break; // Do not require a break for the default condition.
	}

	// 13:15 - Ternary operators
	// Follows format of '<variable to store value> = (<condition test>) ? <value if condition is true> : <value if condition is false>;'

	int largestNum = (5 > 2) ? 5 : 2;
	cout << "Largest number: " << largestNum << endl;

	// 14:00 - Arrays
	// Follows format of <datatype> <arrayName>[<numberOfSpaces>];
	int myFavNums[5]; // Generates an integer array called 'myFavNums' of size 5.
	// Can also be populated with values starting from index[0] like so:
	int badNums[5] = { 4, 13, 14, 24, 34 };
	// To print them:
	cout << badNums[0] << endl;

	// 15:00 - Multidimensional arrays
	// Array of arrays
	char EBCDTable[4][10] = { { ' ', '1', '2', '3', '4', '5', '6', '7', '8', '9' },
							  { '&', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' },
							  { '-', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R' },
							  { '0', '/', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' } };

	cout << "Zone 2, Other 0: " << EBCDTable[2][0] << endl;

	// 16:30 - For loops
	for (int i = 1 ; i <= 10 ; i++) {
		cout << i << endl;
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 10; j++) {
			cout << EBCDTable[i][j] << ' ';
		}
		cout << endl;
	}

	// 18:28 - Random numbers
	int randNum = (rand() % 100) + 1; // 'rand() % ##' generates a random number of ## range, 0 inclusive.
	// 18:35 - While loops
	while (randNum < 75) { // While 'randNum' is less than 75, do the following:
		cout << "Random: " << randNum << endl; // Print the random number
		randNum = (rand() % 100) + 1; // Re-roll the random number
	}

	// 19:55 - Strings - Stores a sequence of characters
	string userGuess;
	int userGuessAsInt = 0;

	// 20:22 - Do-While loop
	do { // <EXECUTE THIS CONTENT AT LEAST ONCE>
	} while (false); // Conditional test, replace 'false' with the condition to test. Can get stuck in a loop if condition is stuck on 'true'
	
	// For example:
	do {
		cout << "Guess a number: ";
		getline(cin, userGuess);
		// getline(source, destination) - Takes input from 'source' and assigns it to 'destination'
		// In this case, takes input from 'cin' (user console input) and assigns it to variable 'userGuess'
		userGuessAsInt = stoi(userGuess); // 'stoi' - String TO Integer - Converts a string to integer. Throws an exception if it can't be converted
		// stod - String TO Double
	} while (userGuessAsInt != 50);

	cout << "You guessed the number!" << endl;

	// 21:45 - More Strings
	char happyArray[6] = { 'H', 'a', 'p', 'p', 'y', '\0' }; // C version of String building.
	// Terminate string array with '\0', the NUL or NULL character. Used by C to determine "length" of the string by finding the position of the NUL character.

	string birthdayString = " Birthday!"; // Generates a string named 'birthdayString', storing the value of " Birthday!"

	cout << happyArray + birthdayString << endl; // Concatenation operator works on strings.

	string yourName = "Teabean";
	cout << "Hello, " << yourName << endl;

	cout << "The length of your name is: " << yourName.size() << " characters" << endl; // .size() - Returns the length of the String
	cout << "Is string empty? " << yourName.empty() << endl; // .empty() - Boolean return on if the string is empty or not
	cout << yourName.append("gobbledegook!") << endl; // .append(arg1) - String method that appends the argument to the calling string

	string otherName = "Tim Lum";
	cout << "otherName: " << otherName << endl;
	cout << endl << endl << "Comparisons: " << endl;
	cout << yourName.compare(otherName) << endl; // Greater(Less) => -1
	cout << yourName.compare(yourName) << endl; // Equal to => 0
	cout << otherName.compare(yourName) << endl; // Less(Greater) => -1

	// 25:52 - Copy of String
	string newName = yourName.assign(yourName); // .assign(arg1)
	cout << "newName: " << newName << endl;

	//Substring
	string firstName = otherName.assign(otherName, 0, 3); // someString.assign(StringToWorkWith, <start index>, <length>);

	int lastNameIndex = otherName.find("Lum", 0); // To find the index at which a particular substring starts
	// someString.find("<substring to find>", <index to start searching from>). Return -1 if substring is not found;
	
	yourName.insert(5, "thingToInsert"); // someString.insert(<index to insert at>, <content to insert>);

	yourName.erase(6, 7); // someString.erase(<index to start erasing at>, <number of indices to erase>);

	yourName.replace(6, 5, "Maximum"); // someString.replace(<index to start replacing>, <number of characters to replace>, <string to replace with>);

	cout << "--- End of Strings ---" << endl;

	// 27:54 - Vectors - Like arrays, but resizable.
	vector <int> lotteryNumVect(10); // Generate a vector of type int, named 'lotteryNumVect' of size (10).
	int lotteryNumArray[5] = { 0, 1, 2, 3, 4 };
	lotteryNumVect.insert(lotteryNumVect.begin(), lotteryNumArray, lotteryNumArray + 3); // someVector(<position to insert at>, <source of things to insert>, <number of things to insert>);
	cout << lotteryNumVect.at(2) << endl; // Accesses the contents of the vector at the argument index.
	// someVector.insert(targetVector.begin() + <position to insert at>, <value to insert> );
	// someVector.push_back(<value to append>) - Places value at end of vector.
	// someVector.back() - Returns the end value of the vector. Similar to peek() in Java stack.
	// someVector.front() - Returns the front value of the vector. Similar to peek() in a Java queue.
	// someVector.pop_back() - Returns and removes the end value of the vector. Similar to pop() in Java.
	// someVector.empty() - Returns false if not empty, 1 if empty.
	// someVector.size() - Returns the size of the vector (stored or actual? Unknown at the moment)

	// 35:20 - Working with files
	string someString = "Testy McTestface";
	ofstream someWriteStream("someName.txt"); // Makes a new file output stream called 'someWriteStream', will name the file "someName.txt"
	if (!someWriteStream) {
		cout << "Error opening file" << endl;
		return( -1 ); // Error code for problematic execution
	}
	else { // The file stream is open
		someWriteStream << someString << endl; // Send 'someString' to the file output stream
		someWriteStream.close(); // Be sure to close the file stream
	}
	// Write streams have different arguments for different behaviors you might want them to do:
	// ofstream someWriteStream("someName.txt", ios::app);  - Open a stream to append to the file
	// ofstream someWriteStream("someName.txt", ios::binary);  - Treat the file as binary
	// ofstream someWriteStream("someName.txt", ios::in); - Open a file to read input
	// ofstream someWriteStream("someName.txt", ios::trunc); - Default behavior
	// ofstream someWriteStream("someName.txt", ios::out); - Open file to write output

	// 37:45 - ifstream reader
	char letter; // To store the letters from the file input
	ifstream reader("someName.txt");
	if (!reader) {
		cout << "error!" << endl;
		return(-1);
	}
	else {
		while (!reader.eof()) {
			reader.get(letter); // someIFStream.get(target) - Assigns the char from the read stream to the target variable
			cout << letter;
		}
	}
	cout << endl;
	reader.close();

	// 38:44 - Exception handling
	// try {
	//    <The thing to try>
	// } else throw(argument)
	// catch (datatype argument) {
	//    <What to do>
	// }

   // 40:03 - Pointers
   int theAge = 33;
   char theGrade = 'A';

   cout << "Size of int: " << sizeof(theAge) << endl;
   cout << "Size of char: " << sizeof(myGrade) << endl;

   // To determine the location of information, use a reference operator:
   cout << "theAge is located at address: " << &theAge << endl; // Prints the address of "theAge" variable.
   cout << "theGrade is located at address: " << &theGrade << endl; // Prints the address of "theGrade" variable.
   
   // 41:30
   // By default, when passing variables into functions, we are passing them BY VALUE.

   // 41:54 - A pointer is able to store a memory address
   // When creating a pointer, use the same data type, followed by a star (ie. int*, char*, bool*...)

   // 42:07 - Assigning reference to a pointer
   // int* agePtr = <reference address>; // Recall that a reference address is invoked with the ampersand (&)
   int* agePtr = &theAge; // &theAge generates an int type reference, which we assign to the pointer variable "agePtr".
   
   cout << "agePtr's stored address: " << agePtr << endl;

   cout << "Data at agePtr's stored address: " << *agePtr << endl;

   // 42:40 - Array pointers
   int goodNums[5] = { 4, 13, 14, 24, 34 };

   int* numArrayPtr = goodNums;

   cout << "numArrayPtr's stored address: " << numArrayPtr << endl;
   cout << "value at numArrayPtr's store address: " << *numArrayPtr << endl;

   // Now we increment the pointer
   numArrayPtr++;
   cout << "numArrayPtr's stored address: " << numArrayPtr << endl;
   cout << "value at numArrayPtr's store address: " << *numArrayPtr << endl;

   // 43:49
   // An array variable is a pointer to the array
   cout << "Array's name (goodNums) address: " << goodNums << endl;
   cout << "Array's name (goodNums) value: " << *goodNums << endl; // Because the array name is a pointer, *array dereferences it, returning the first value of the array.


	return (0); // In C and C++ programs the main function is of type int and therefore it should return an integer value. The return value of the main function is considered the "Exit Status" of the application. On most operating systems returning 0 is a success status like saying "The program worked fine".

}

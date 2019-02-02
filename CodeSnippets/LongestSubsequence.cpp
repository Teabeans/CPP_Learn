//-----------------------------------------------------------------------------|
// Authorship
//-----------------------------------------------------------------------------|
//
// Tim Lum
// twhlum@gmail.com
// Created:  2018.09.03
// Modified: 2018.09.03
//

/*
Longest Subsequence

Given an array of unsorted, non-negative integers, perform two actions:

1) Print the length of the longest, constantly increasing subsequence
2) Print the longest, constantly increasing subsequence

1 5 3 9 2 8 5 12 10 3 1 0
1 2   3       4
1   2     3   4
1     2       3
1       2   3 4
1         2   3
1           2 3
etc.



//-----------------------------------------------------------------------------|
// PROBLEM SETUP AND ASSUMPTIONS
//-----------------------------------------------------------------------------|

The array may contain duplicates

In the event of a tie, any valid result may be output



//-----------------------------------------------------------------------------|
// OBSERVATIONS AND INFERENCES
//-----------------------------------------------------------------------------|



//-----------------------------------------------------------------------------|
// NAIVE, BRUTE FORCE, TERRIBAD APPROACH
//-----------------------------------------------------------------------------|

From the start, begin systematically exploring all possible increasing sub sequences

Note the longest result.

The search space in this case is O( 2^n ), where 'n' is the length of the array
to explore. One way to think about this is that every digit is either included
or not, and all possible combinations of inclusion/exclusion must be explored.



//-----------------------------------------------------------------------------|
// OPTIMIZATIONS
//-----------------------------------------------------------------------------|

Observing that the last digit in the sequence has precisely (1) increasing subsequence

And observing that if two values have an identical sequence length (working from
the back), the higher/later or lower/earlier is preferable

e.g. - 
VALUES:  #  #  #  #  #  #  #  5 16 < 16:3 will result in higher or equal sequences later
SQ.LEN:                       3  3

We may establish the following approach:

1) Determine the sequence length at the back of the array
2) Moving towards the front, determine the longest sequence value belonging to a
   value greater than the current. Add 1 and assign this as the sequence value
   of the current index.
   A) If no such value is found, assign 1
   B) If two values share a sequence value, discard the smaller value

VALUES: 13  2  9 12  7  4 10  1  6  8  5 11  3
SQ.LEN:                                   1  1

VALUES: 13  2  9 12  7  4 10  1  6  8  5 11  3
SQ.LEN:                                      1

VALUES: 13  2  9 12  7  4 10  1  6  8  5 11  3
SQ.LEN:                                      1

VALUES: 13  2  9 12  7  4 10  1  6  8  5 11  3
SQ.LEN:                                      1

VALUES: 13  2  9 12  7  4 10  1  6  8  5 11  3
SQ.LEN:                                      1

VALUES: 13  2  9 12  7  4 10  1  6  8  5 11  3
SQ.LEN:                                      1

VALUES: 13  2  9 12  7  4 10  1  6  8  5 11  3
SQ.LEN:                                      1

VALUES: 13  2  9 12  7  4 10  1  6  8  5 11  3
SQ.LEN:                                      1


//-----------------------------------------------------------------------------|
// TIME COMPLEXITY
//-----------------------------------------------------------------------------|

This function can complete its read in a time complexity of:

O( n )

The identification and return of the node  may be completed in a time complexity of:

O( 1 )



//-----------------------------------------------------------------------------|
// PSEUDOLOGIC
//-----------------------------------------------------------------------------|

Generate a hashtable of node addresses
Iterate across the list, populating the address table
When the end is determined, ascertain the node number to remove
Consult the address table to locate the address of that node
Remove the node



//-----------------------------------------------------------------------------|
// CODE (C++)
//-----------------------------------------------------------------------------|
*/

#include <02_00_LinkedList.cpp>
#include <iostream>
#include <string>
#include <stringstream>
#include <iomanip>
#include <random>

// (+) --------------------------------|
// #returnKthToLast( LinkedList, int )
// ------------------------------------|
// Desc:    Removes the Kth to last element of a Linked List
// Params:  LinkedList arg1 - The list to remove from
//          int arg2 - The value 'K', a cardinal position from the list's end
// PreCons: None
// PosCons: The Kth to last element has been removed
// RetVal:  None
void returnKthToLast( LinkedList tgtList, int K ) {
   // Generate an address table
   nodeLL* addressTable[1000];
   int nodeNumber = 0;
   nodeLL* currNode = tgtList.head->next;
   while( currNode != nullptr ) {
      addressTable[nodeNumber] = currNode;
      nodeNumber++;
   } // Closing while - List traversed, address table populated
   nodeNumber = nodeNumber - K;
   tgtList.remove( nodeNumber );
} // Closing returnKthToLast( )



//-----------------------------------------------------------------------------|
// DRIVER
//-----------------------------------------------------------------------------|

// (+) --------------------------------|
// #main( int, char* )
// ------------------------------------|
// Desc:    Code driver
// Params:  int arg1 - The number of command line arguments passed in
//          char* arg2 - The content of the command line arguments
// PreCons: None
// PosCons: None
// RetVal:  int - The exit code (0 for normal, -1 for error)
int main( int argc, char* argv[ ] ) {
   std::cout << "Test of returnKthToLast( ):" << std::endl << std::endl;

   std::cout << "Instantiating list..." << std::endl;
   LinkedList testList = LinkedList( );
   for( int i = 0 ; i < 100; i++ ) {
      int currVal = rand( 1001 );
      testList.insert( currVal );
   }
   testList.print( );

   std::cout << "Testing removeDups( )..." << std::endl;

   removeDups( testList );

   testList.print( );

   return( 0 );
} // Closing main( int, char* )

// End of file - 02_02_ReturnKthToLast.cpp

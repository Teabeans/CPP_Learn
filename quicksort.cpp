//-------|---------|---------|---------|---------|---------|---------|---------|
//
// quicksort.cpp
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-----------------------------------------------------------------------------|
// AUTHORSHIP
//-----------------------------------------------------------------------------|
//
// Tim Lum
// twhlum@gmail.com
// Created:  2018.08.20
// Modified: 2018.08.21
//

//-----------------------------------------------------------------------------|
// ACKNOWLEDGMENTS
//-----------------------------------------------------------------------------|
//
// Template author:
// Tim Lum (github.com/Teabeans/Template_Cpp)
//

//-----------------------------------------------------------------------------|
// FILE DESCRIPTION
//-----------------------------------------------------------------------------|
//
// <Short explanation of file purpose and function>
//
// (If this file contains 'main()' ) Program Description:
// <Explanation of overall program purpose and function>
//

//-----------------------------------------------------------------------------|
// PACKAGE FILES
//-----------------------------------------------------------------------------|
//
// <Files needed to run this program>
//

//-----------------------------------------------------------------------------|
// USAGE
//-----------------------------------------------------------------------------|
//
// <Description of setup and usage>
//

//-----------------------------------------------------------------------------|
// ERRATA
//-----------------------------------------------------------------------------|
//
// <Any other comments>
//

//-----------------------------------------------------------------------------|
// LICENSE
//-----------------------------------------------------------------------------|
// 
// <License> or <Refer to LICENSE.txt>
//

//-----------------------------------------------------------------------------|
// CODE STANDARDS
//-----------------------------------------------------------------------------|
//
// <Standards> or <Refer to CODESTANDARDS.txt>
//

//-----------------------------------------------------------------------------|
// IMPORTS / INCLUDES
//-----------------------------------------------------------------------------|

// CONTAINERS
// #include <array>              // http://www.cplusplus.com/reference/array/array/
// #include <deque>              // http://www.cplusplus.com/reference/deque/deque/
// #include <forward_list>       // http://www.cplusplus.com/reference/forward_list/forward_list/
// #include <list>               // http://www.cplusplus.com/reference/list/list/
// #include <map>                // http://www.cplusplus.com/reference/map/map/
// #include <queue>              // http://www.cplusplus.com/reference/queue/queue/
// #include <set>                // http://www.cplusplus.com/reference/set/set/
// #include <stack>              // http://www.cplusplus.com/reference/stack/stack/
// #include <unordered_map>      // http://www.cplusplus.com/reference/unordered_map/unordered_map/
// #include <unordered_set>      // http://www.cplusplus.com/reference/unordered_set/unordered_set/
// #include <vector>             // http://www.cplusplus.com/reference/vector/vector/

// INPUT / OUTPUT
#include <iostream>              // For input/output (C++)
// #include <stdio.h>            // For input/output (C)
#include <iomanip>               // For width-formatted outputs
// #include <fstream>            // For file-stream

// MULTITHREADING
// #include <pthread.h>          // https://www.tutorialspoint.com/cplusplus/cpp_multithreading.htm
// #include <atomic>             // http://www.cplusplus.com/reference/atomic/
// #include <condition_variable> // http://www.cplusplus.com/reference/condition_variable/
// #include <future>             // http://www.cplusplus.com/reference/future/
// #include <mutex>              // http://www.cplusplus.com/reference/mutex/
// #include <thread>             // http://www.cplusplus.com/reference/thread/thread/

// EXCEPTIONS
#include <exception>             // http://www.cplusplus.com/reference/exception/exception/
#include <assert.h>              // http://www.cplusplus.com/reference/cassert/assert/

// OTHER
#include <algorithm>             // http://www.cplusplus.com/reference/algorithm
#include <chrono>                // http://www.cplusplus.com/reference/chrono/
// #include <time.h>             // Superceded by <chrono>
#include <random>                // http://www.cplusplus.com/reference/random/
#include <string>                // http://www.cplusplus.com/reference/string/
#include <sstream>               // http://www.cplusplus.com/reference/sstream/
#include <utility>               // http://www.cplusplus.com/reference/utility/
// #include <unistd.h>           // Provides access to the POSIX operating system AP

// CLASS DECLARATIONS
// #include "MyFile.h"

//-----------------------------------------------------------------------------|
// DECLARATIONS
//-----------------------------------------------------------------------------|

class quicksorter {
   private:
   int partition( int* tgtArray, int pivotIndex, int left, int right );
   void quicksort( int* tgtArray, int left, int right );
   int  selectPivotIndex( int* tgtArray, int left, int right );

   public:
   void quicksort( int* tgtArray, int size );

};

int* makeRandomArray( int size, int min, int max );
void printHelloWorld( );
void printArray( std::string title, int* tgtArray, int size );
void verbosePrint( std::string message );
void verbosePrintln( std::string message );

//-----------------------------------------------------------------------------|
// DEFINES
//-----------------------------------------------------------------------------|

// #define NDEBUG                // Include for assertions, comment to omit
#define PI  3.141569
#define TAU 6.283185

//-----------------------------------------------------------------------------|
// GLOBAL VARIABLES
//-----------------------------------------------------------------------------|

bool   VERBOSE    = true;
bool   DEBUG_MODE = true;
int    INT_PI     = 3;
int    INT_TAU    = 6;
float  FLOAT_PI   = 3.14159265;
float  FLOAT_TAU  = 6.28318530;
double DOUBLE_PI  = 3.141592653589793238;
double DOUBLE_TAU = 6.283185307179586476;

//-----------------------------------------------------------------------------|
// NAMESPACES
//-----------------------------------------------------------------------------|

// NOTE: Use of namespaces is discouraged
// using namespace std;

//-----------------------------------------------------------------------------|
// PRIVATE CLASS FIELDS
//-----------------------------------------------------------------------------|

//-----------------------------------------------------------------------------|
// PRIVATE CLASS METHODS
//-----------------------------------------------------------------------------|

// (-) --------------------------------|
// #partition( int*, int, int, int )
// ------------------------------------|
// Desc:    Partitions values around a pivot
// Params:  int* arg1 - The array to partition
//          int arg2 - The left-bound index of the sample area
//          int arg3 - The right-bound index of the sample area
// PreCons: None
// PosCons: The array has been partitioned
// RetVal:  The index of the pivot (partition)
int quicksorter::partition( int* tgtArray, int pivotIndex, int left, int right ) {
   // ------------------------------------|
   // STEP 0 - BASE CASE
   // ------------------------------------|
   verbosePrintln( "Checking partition() base case..." );

   if( left == right ) {
      verbosePrintln( "Partition base hit!" );
      return( left );
   }
   // ------------------------------------|
   // STEP 1 - MOVE THE PIVOT OUT OF THE WAY
   // ------------------------------------|
   std::swap( tgtArray[0], tgtArray[pivotIndex] );
   // Current location of the pivot
   int retIndex = 0;
   // The pivot value to compare against:
   int pivotVal = tgtArray[0];
   // tgtArray:
   //    0    1    2    3    4    5    6    7    8    9   Index
   // +----+----+----+----+----+----+----+----+----+----+
   // | 50 |  < |  > |  < |  > |  < |  > |  < |  > |  < | Value
   // +----+----+----+----+----+----+----+----+----+----+
   //    ^Left                                        ^Right

   // ------------------------------------|
   // STEP 2 - PARTITION THE REMAINING VALUES
   // ------------------------------------|
   while( left < ( right - 1 ) ) {
      if( tgtArray[left] <= pivotVal ) {
         // Value at left index is on correct side of pivot, so do nothing
         left++;
      }
      else if ( tgtArray[left] > pivotVal ) {
         if ( tgtArray[right] > pivotVal ) {
            // Value at right index is on correct side of pivot, so do nothing
            right--;
         }
         // Both left and right point to mis-aligned values, so swap
         else if ( tgtArray[right] <= pivotVal ) {
            std::swap( tgtArray[left], tgtArray[right] );
            left++;
         }
      }
   } // Comparisons complete
   // tgtArray:
   //    0    1    2    3    4    5    6    7    8    9   Index
   // +----+----+----+----+----+----+----+----+----+----+
   // | 50 |  < |  < |  < |  < |  > |  > |  > |  > |  > | Value
   // +----+----+----+----+----+----+----+----+----+----+
   //                        ^Left^Right

   // ------------------------------------|
   // STEP 3 - CORRECTLY PLACE THE PIVOT
   // ------------------------------------|
   std::swap( tgtArray[0], tgtArray[left] );
   retIndex = left;
   // tgtArray:              |-retIndex
   //    0    1    2    3    4    5    6    7    8    9   Index
   // +----+----+----+----+----+----+----+----+----+----+
   // |  < |  < |  < |  < | 50 |  > |  > |  > |  > |  > | Value
   // +----+----+----+----+----+----+----+----+----+----+
   //                        ^Left^Right
   return( retIndex );
} // Closing partition( int*, int, int, int )

// (-) --------------------------------|
// #selectPivotIndex( )
// ------------------------------------|
// Desc:    Selects a pivot value using the median-of-three (random) numbers
// Params:  int* arg1 - The array to sample from
//          int arg2 - The left-bound index of the sample area
//          int arg3 - The right-bound index of the sample area
// PreCons: None
// PosCons: None
// RetVal:  The median value of a random sampling
int quicksorter::selectPivotIndex( int* tgtArray, int left, int right ) {
   // Select (3) values at random within the range
   int range = ( right - left );
   int randInd1 = ( rand( ) % range ) + left;
   int randInd2 = ( rand( ) % range ) + left;
   int randInd3 = ( rand( ) % range ) + left;
   int randVal1 = tgtArray[randInd1];
   int randVal2 = tgtArray[randInd2];
   int randVal3 = tgtArray[randInd3];
   // Select the median
   int pivotVal = std::max( std::min( randVal1, randVal2), std::min( std::max( randVal1, randVal2 ), randVal3 ) );
   // Return the appropriate INDEX (the value is immaterial at this point)
   if( pivotVal == randVal1 ) {
      return( randInd1 );
   }
   else if( pivotVal == randVal2 ) {
      return( randInd2 );
   }
   else {
      return( randInd3 );
   }
} // Closing selectPivotIndex( )

// (-) --------------------------------|
// #quicksort( int*, int, int )
// ------------------------------------|
// Desc:    Sorts an array of integers
// Params:  int* arg1 - The array to sort
//          int arg2 - The left bound
//          int arg3 - The right bound
// PreCons: None
// PosCons: The array has been sorted from left to right bound
// RetVal:  None - The sort is performed in situ
void quicksorter::quicksort( int* tgtArray, int left, int right ) {
   verbosePrint( "quicksort() called: " );
   std::cout << left << " : " << right << std::endl;
   // ------------------------------------|
   // STEP 0 - BASE CONDITION
   // ------------------------------------|
   // If the range is 0, this range is sorted by definition
   if( left >= right ) {
      verbosePrintln( "quicksort() base case hit!" );
      return;
   }
   // ------------------------------------|
   // STEP 1 - SELECT A PIVOT
   // ------------------------------------|
   int pivotIndex = quicksorter::selectPivotIndex( tgtArray, left, right );
   // ------------------------------------|
   // STEP 2 - PARTITION VALUES AROUND THE PIVOT
   // ------------------------------------|
   int partitionIndex = quicksorter::partition( tgtArray, pivotIndex, left, right );
   // ------------------------------------|
   // STEP 3 - RECURSIVELY SORT THE LEFT
   // ------------------------------------|
   quicksorter::quicksort( tgtArray, left, ( partitionIndex - 1 ) );
   // ------------------------------------|
   // STEP 4 - RECURSIVELY SORT THE RIGHT
   // ------------------------------------|
   quicksorter::quicksort( tgtArray, ( partitionIndex + 1 ), right );
} // Closing quicksort( int*, int, int )

//-----------------------------------------------------------------------------|
// CLASS GETTERS/SETTERS
//-----------------------------------------------------------------------------|

//-----------------------------------------------------------------------------|
// PUBLIC CLASS FIELDS
//-----------------------------------------------------------------------------|

//-----------------------------------------------------------------------------|
// PUBLIC CLASS METHODS
//-----------------------------------------------------------------------------|

// (+) --------------------------------|
// #quicksort( int*, int )
// ------------------------------------|
// Desc:    Sorts an array of integers
// Params:  int* arg1 - The array to sort
//          int arg2 - The size of the array to sort
// PreCons: None
// PosCons: The array has been sorted to the [arg1] element from low to high
// RetVal:  None - The sort is performed in situ
void quicksorter::quicksort( int* tgtArray, int size ) {
   quicksorter::quicksort( tgtArray, 0, ( size - 1 ) );
} // Closing quicksort( int*, int )

//-----------------------------------------------------------------------------|
// DRIVER
//-----------------------------------------------------------------------------|

int main( int argc, char* argv[] ) {
   printHelloWorld( );
   std::string assertTest = "This is a test";
   assert( assertTest == "This is a test" );
   verbosePrintln( "Generating a random array..." );
   int size = 20;
   int* testArray = makeRandomArray( size, 0, 99 );
   printArray( "Contents of testArray:", testArray, size );

   verbosePrintln( "Instantiating Quicksorter..." );
   quicksorter theSorter;

   verbosePrintln( "Beginning quicksort()..." );
   theSorter.quicksort( testArray, size );

   printArray( "Results of quicksort:", testArray, size );
   return( 0 );
}

//-----------------------------------------------------------------------------|
// STATIC METHODS
//-----------------------------------------------------------------------------|

// (+) --------------------------------|
// #makeRandomArray( int, int, int )
// ------------------------------------|
// Desc:    Generates a NEW array populated based on its arguments
// Params:  int arg1 - The size of the NEW array
//          int arg2 - The minimum value (inclusive) within the array
//          int arg3 - The maximum value (inclusive) within the array
// PreCons: None
// PosCons: A NEW array has been allocated
// RetVal:  A pointer to the NEW array
int* makeRandomArray( int size, int min, int max ) {
   int* retArrayPtr = new int[size];
   int range = ( max - min ) + 1;
   int currVal;
   for( int i = 0 ; i < size ; i++ ) {
      currVal = ( rand( ) % range ) + min;
      retArrayPtr[i] = currVal;
   }
   return( retArrayPtr );
} // Closing makeRandomArray( int, int, int )

// (+) --------------------------------|
// #printArray( std::string, int* )
// ------------------------------------|
// Desc:    Prints an array to console along with a title
// Params:  string arg1 - The title describing the array
//          int* arg2 - The array to print
//          int arg3 - The array size
// PreCons: None
// PosCons: None
// RetVal:  None
void printArray( std::string title, int* tgtArray, int size ) {
   std::cout << title << std::endl;
   // [ ###
   std::cout << "[" << std::setw( 3 ) << tgtArray[0];
   for( int i = 1 ; i < size ; i++ ) {
      std::cout << " , " << tgtArray[i];
   }
   // [ ### , ### , ### ]
   std::cout << " ]" << std::endl;
} // Closing printArray( )

// (+) --------------------------------|
// #printHelloWorld( )
// ------------------------------------|
// Desc:    Prints "Hello, World!" to console out
// Params:  None
// PreCons: None
// PosCons: None
// RetVal:  None
void printHelloWorld( ) {
   std::cout << "Hello, World!" << std::endl;
} // Closing printHelloWorld( )

// (+) --------------------------------|
// #verbosePrint( )
// ------------------------------------|
// Desc:    Prints a message to console if the VERBOSE flag is active
// Params:  std::string arg1 - The message to print
// PreCons: None
// PosCons: None
// RetVal:  None
void verbosePrint( std::string message ) {
   if( VERBOSE ) {
      std::cout << message;
   }
} // Closing verbosePrint( )

// (+) --------------------------------|
// #verbosePrintln( )
// ------------------------------------|
// Desc:    Prints a message and newline to console if the VERBOSE flag is active
// Params:  std::string arg1 - The message to print
// PreCons: None
// PosCons: None
// RetVal:  None
void verbosePrintln( std::string message ) {
   if( VERBOSE ) {
      std::cout << message << std::endl;
   }
} // Closing verbosePrintln( )

// End of file - quicksort.cpp

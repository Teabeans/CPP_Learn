//-------|---------|---------|---------|---------|---------|---------|---------|
//
// <FileName>.<Extension>
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-----------------------------------------------------------------------------|
// AUTHORSHIP
//-----------------------------------------------------------------------------|
//
// <FirstName> <LastName>
// <ContactInformation>
// Created:  <YYYY.MM.DD>
// Modified: <YYYY.MM.DD>
//

//-----------------------------------------------------------------------------|
// ACKNOWLEDGMENTS
//-----------------------------------------------------------------------------|
//
// Template author:
// Tim Lum (github.com/Teabeans/Template_Cpp)
//
// Refer to ACKNOWLEDGEMENTS.txt
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
// Refer to PACKAGEFILES.txt
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

// None declared in the .cpp

//-----------------------------------------------------------------------------|
// DEFINES
//-----------------------------------------------------------------------------|

// #define NDEBUG                   // Omit for assertions, include to disable
#define PI  3.141569
#define TAU 6.283185
#define FAVORITE_COLOR gray

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

// None declared in the .cpp

//-----------------------------------------------------------------------------|
// PRIVATE CLASS METHODS
//-----------------------------------------------------------------------------|

// None for this class

//-----------------------------------------------------------------------------|
// CONSTRUCTORS / DESTRUCTORS
//-----------------------------------------------------------------------------|

// None for this class

//-----------------------------------------------------------------------------|
// CLASS GETTERS/SETTERS
//-----------------------------------------------------------------------------|

// None for this class

//-----------------------------------------------------------------------------|
// PUBLIC CLASS FIELDS
//-----------------------------------------------------------------------------|

// None declared in the .cpp

//-----------------------------------------------------------------------------|
// PUBLIC CLASS METHODS
//-----------------------------------------------------------------------------|

// None for this class

//-----------------------------------------------------------------------------|
// DRIVER (If applicable)
//-----------------------------------------------------------------------------|

int main( int argc, char* argv[] ) {
   printHelloWorld( );
   std::string assertTest = "This is a test";
   assert( assertTest == "This is a test" );

   return( 0 );
}

//-----------------------------------------------------------------------------|
// STATIC METHODS
//-----------------------------------------------------------------------------|

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
// #someMethod( )
// ------------------------------------|
// Desc:    TODO
// Params:  TODO
// PreCons: TODO
// PosCons: TODO
// RetVal:  TODO
void myClass::someMethod( ) {

} // Closing someMethod( )

// End of file - <FileName>.<Extension>

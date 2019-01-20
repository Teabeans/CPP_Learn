//-------|---------|---------|---------|---------|---------|---------|---------|
//
// cryptotest.cpp
//
//-------|---------|---------|---------|---------|---------|---------|---------|

//-----------------------------------------------------------------------------|
// AUTHORSHIP
//-----------------------------------------------------------------------------|
//
// Tim Lum
// twhlum@gmail.com
// Created:  2019.01.19
// Modified: 2019.01.19
//

//-----------------------------------------------------------------------------|
// ACKNOWLEDGMENTS
//-----------------------------------------------------------------------------|
//
// Template author:
// Tim Lum (github.com/Teabeans/CPP_Lean/template.h)
//
// Refer to ACKNOWLEDGEMENTS.txt
//

//-----------------------------------------------------------------------------|
// FILE DESCRIPTION
//-----------------------------------------------------------------------------|
//
// This file is a test of the OpenSSL library for PBKDF2 support

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
// OpenSSL library must be installed beforehand with:
// $ sudo apt-get install libssl-dev
//
// Compile with:
// $ g++ -std=c++11 *.cpp -lssl -lcrypto -o test.out
//
// Run with:
// $ ./test.out
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
#include <cstring>               // Fpr strlen( )
// #include <iomanip>            // For width-formatted outputs
// #include <fstream>            // For file-stream

// MULTITHREADING
// #include <pthread.h>          // https://www.tutorialspoint.com/cplusplus/cpp_multithreading.htm
// #include <atomic>             // http://www.cplusplus.com/reference/atomic/
// #include <condition_variable> // http://www.cplusplus.com/reference/condition_variable/
// #include <future>             // http://www.cplusplus.com/reference/future/
// #include <mutex>              // http://www.cplusplus.com/reference/mutex/
// #include <thread>             // http://www.cplusplus.com/reference/thread/thread/

// EXCEPTIONS
// #include <exception>          // http://www.cplusplus.com/reference/exception/exception/
// #include <assert.h>           // http://www.cplusplus.com/reference/cassert/assert/

// OTHER
// #include <algorithm>          // http://www.cplusplus.com/reference/algorithm
// #include <chrono>             // http://www.cplusplus.com/reference/chrono/
// #include <time.h>             // Superceded by <chrono>
// #include <random>             // http://www.cplusplus.com/reference/random/
#include <string>                // http://www.cplusplus.com/reference/string/
// #include <sstream>            // http://www.cplusplus.com/reference/sstream/
// #include <utility>            // http://www.cplusplus.com/reference/utility/
// #include <unistd.h>           // Provides access to the POSIX operating system AP

#include <openssl/evp.h>         // For the core OpenSSL library (Note: Must be installed)
#include <openssl/sha.h>         // SHA1 and SHA2 hashes (used in key generation)

//-----------------------------------------------------------------------------|
// GLOBAL VARIABLES
//-----------------------------------------------------------------------------|

// None for this class

//-----------------------------------------------------------------------------|
// NAMESPACES
//-----------------------------------------------------------------------------|

// NOTE: Use of namespaces is discouraged
// using namespace std;

//-----------------------------------------------------------------------------|
// DRIVER (If applicable)
//-----------------------------------------------------------------------------|

int main( int argc, char* argv[] ) {
   const char* password = "password";
   int passLength = 8;
   const char* theSalt = "salt";
   int saltLength = 4;
   int iterations = 10;
   int hashLen = 32; // Will be 32 bit
   unsigned char PBKDF2Result[32];

   // From https://www.openssl.org/docs/man1.1.0/crypto/PKCS5_PBKDF2_HMAC_SHA1.html
   PKCS5_PBKDF2_HMAC( password,
                      passLength,
                      (unsigned char*)theSalt,
                      saltLength,
                      iterations,
                      EVP_sha256(),
                      hashLen,
                      PBKDF2Result );

   for( int i = 0 ; i < 32 ; i++ ) {
      std::cout << PBKDF2Result[i];
   }
   
   std::cout << std::endl;

   return( 0 );
}

//-----------------------------------------------------------------------------|
// STATIC METHODS
//-----------------------------------------------------------------------------|

// None in this class

// End of file - crypotest.cpp

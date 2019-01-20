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
// PBKDF2 HMAC SHA-256 test vectors from
// https://stackoverflow.com/questions/5130513/pbkdf2-hmac-sha2-test-vectors
//

/*
PBKDF2 HMAC-SHA256 Test Vectors

Input:
  P = "password" (8 octets)
  S = "salt" (4 octets)
  c = 1
  dkLen = 32

Output:
  DK = 12 0f b6 cf fc f8 b3 2c
       43 e7 22 52 56 c4 f8 37
       a8 65 48 c9 2c cc 35 48
       08 05 98 7c b7 0b e1 7b (32 octets)


Input:
  P = "password" (8 octets)
  S = "salt" (4 octets)
  c = 2
  dkLen = 32

Output:
  DK = ae 4d 0c 95 af 6b 46 d3
       2d 0a df f9 28 f0 6d d0
       2a 30 3f 8e f3 c2 51 df
       d6 e2 d8 5a 95 47 4c 43 (32 octets)


Input:
  P = "password" (8 octets)
  S = "salt" (4 octets)
  c = 4096
  dkLen = 32

Output:
  DK = c5 e4 78 d5 92 88 c8 41
       aa 53 0d b6 84 5c 4c 8d
       96 28 93 a0 01 ce 4e 11
       a4 96 38 73 aa 98 13 4a (32 octets)


Input:
  P = "password" (8 octets)
  S = "salt" (4 octets)
  c = 16777216
  dkLen = 32

Output:
  DK = cf 81 c6 6f e8 cf c0 4d
       1f 31 ec b6 5d ab 40 89
       f7 f1 79 e8 9b 3b 0b cb
       17 ad 10 e3 ac 6e ba 46 (32 octets)


Input:
  P = "passwordPASSWORDpassword" (24 octets)
  S = "saltSALTsaltSALTsaltSALTsaltSALTsalt" (36 octets)
  c = 4096
  dkLen = 40

Output:
  DK = 34 8c 89 db cb d3 2b 2f
       32 d8 14 b8 11 6e 84 cf
       2b 17 34 7e bc 18 00 18
       1c 4e 2a 1f b8 dd 53 e1
       c6 35 51 8c 7d ac 47 e9 (40 octets)


Input:
  P = "pass\0word" (9 octets)
  S = "sa\0lt" (5 octets)
  c = 4096
  dkLen = 16

Output:
  DK = 89 b6 9d 05 16 f8 29 89
       3c 69 62 26 65 0a 86 87 (16 octets)
*/

//-----------------------------------------------------------------------------|
// LICENSE
//-----------------------------------------------------------------------------|
// 
// Refer to LICENSE.txt
//

//-----------------------------------------------------------------------------|
// CODE STANDARDS
//-----------------------------------------------------------------------------|
//
// Refer to CODESTANDARDS.txt
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
   const char* password = "passwordPASSWORDpassword";
   const char* theSalt = "saltSALTsaltSALTsaltSALTsaltSALTsalt";
   int iterations = 4096;
   int dkLen = 40; // Will be 32 byte eventually

   int passLength = 24;
   int saltLength = 36;
   unsigned char PBKDF2Result[dkLen];

   // From https://www.openssl.org/docs/man1.1.0/crypto/PKCS5_PBKDF2_HMAC_SHA1.html
   PKCS5_PBKDF2_HMAC( password,
                      passLength,
                      (unsigned char*)theSalt,
                      saltLength,
                      iterations,
                      EVP_sha256(),
                      dkLen, // Desired byte-length of the derived key
                      PBKDF2Result );

   for( int i = 0 ; i < dkLen ; i++ ) {
      if( i % 8 == 0 ) {
         std::cout << std::endl;
      }
      std::cout << std::setw(2) << std::setfill('0') << std::hex << (int)PBKDF2Result[i] << " ";
   }
   
   std::cout << std::endl;

   return( 0 );
}

//-----------------------------------------------------------------------------|
// STATIC METHODS
//-----------------------------------------------------------------------------|

// None in this class

// End of file - crypotest.cpp

// My work is below
#include <stdio.h>
#include <stdlib.h>

/*
 * readString - reads a line from a file given by
 * fileName and returns it as a c-string.  The line
 * return is removed from the string.
 * 
 * fileName is c-string representing the file to read.
 * 
 */
char* readString(char* fileName){
    // Make a int var = length of the string inside the file to be read, this var 
    // will represent the amount of memory needed for the initial string reading.

    // 1: Figure out what API to use to read the file.
    // 2: Use logic to assure there will be error handling if there is an error in accessing...
    //    or reading from the file.
    // 3: Allocate the memory dynamically for the string array that you will be copying from the...
    //    file given in the parameter "fileName".
    // 4: Return that copied string
    // 5: Free up the memory used by the aforementioned string array

}

/*
 * mysteryExplode - takes a string of characters and explodes it
 * as follows:
 * 
 * A non-empty string such as "Code" is turned into "CCoCodCode".
 *
 *   Return a new string similar to the string given above.
 *
 *  Example:
 *   mysteryExplosion("Code") --> "CCoCodCode"
 *   mysteryExplosion("abc") --> "aababc"
 *   mysteryExplosion(":)") --> "::)"
 * 
 */
char* mysteryExplode(const char* str) {
    // To get the length of the char* (array) of the final exploded word, you do:
    // L(char*) = (N(N+1) / 2) + 1
    //      Where N = strLen(str)
}

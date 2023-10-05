// My work is below
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab1.h"

/*
 * readString - reads a line from a file given by
 * fileName and returns it as a c-string.  The line
 * return is removed from the string.
 * 
 * fileName is c-string representing the file to read.
 * 
 */
char* readString(char* fileName){
    // START - Variables
    FILE *fptr; // Instantiates a file pointer to be used
    char* contents = "\0";  // Instantiates a C string (array) equal to null pointer (empty)
    long file_size;  // Instantiates a variable to hold the numerical size of the file in the parameter
    // END   - Variables

    // Opens the file specified in the parameters of the function in read mode
    fptr = fopen(fileName, "r");
    if(fptr == NULL) { // If the file doesn't exist, print some stuff
        fprintf(stderr, "File Location Equal to NULL, Unable To Access File.");
        return NULL;  // Stops function due to error thrown
    }

    // USE: fgets or fscanf

    // START - file_size Calculations
    fseek(fptr, 0, SEEK_END);  // Moves the pointer to the end of the file using fseek function
    file_size = ftell(fptr);   // Sets file_size equal to the value of the pointer (which is at the end of the file)
    fseek(fptr, 0, SEEK_SET);  // Sets the pointer back to the start of the file to allow for reading from the file later
    if (file_size > 99) { // If the file size is bigger than 99, throw error due to not meeting requirements
        printf("File size is greater than 99.");  // Prints to console what happened
        fclose(fptr); // Closes file 
        return NULL;  // Stops function due to error thrown
    }
    // STOP  - file_size Calculations    

    // START - Dynamic Memory Allocation
    contents = (char*)malloc(MAX_LINE_LEN * sizeof(char)); // Dynamically allocates memory needed using malloc!    
    if (contents == NULL) {
        fprintf(stderr, "There was an error in dynamically allocating memory for contents.");
        free(contents); // Frees the memory used for contents
        fclose(fptr); // Closes file 
        return NULL;  // Stops function due to error thrown
    }
    // STOP  - Dynamic Memory Allocation

    // START - Reading from the file and putting the information into 'contents'
    fgets(contents, file_size, fptr);  // Read stuff from the file and put it into contents
    contents[MAX_LINE_LEN]; // Ends the c string in a null pointer to properly end the c string
    // STOP  - Reading from the file and putting the information into 'contents'

    // Closing out of files and memory if everything worked
    fclose(fptr); // Closes the file if no errors were thrown
    
    //free(file_size);  // Frees the memory used for the file size

    // RETURN STATEMENT
    return contents; // Returns the contents of the file as a c string with dynamically allocated memory as well as with a null ender to it
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
    int strLength = strlen(str);
    int finalStrLength = ((strLength * (strLength + 1)) / 2) + 1;
    char* resultStr = (char*)malloc(finalStrLength); // Allocate memory for the result string

    resultStr[0] = '\0'; // init. the result str as empty string

    for (int i = 0 ; i < strLength ; i++) {
        char concatStr[finalStrLength];
        strncpy(concatStr, str, i);
        concatStr[i] = '\0'; // Null-terminate the substring
        strcat(resultStr, concatStr);
    }

    return resultStr;
}

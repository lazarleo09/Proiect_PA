///\file main.c
///\brief C program for solving the crypting and decrypting messages as specified in the requirements.
///
/// Created by Lazar Leonard Ruben on 01/06/18.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "message.h"//>print_array(),decrypt(),crypt()
#include "generators.h"//>prime_no(),generate_prime(),generate_non_prime(),prime_no()
#include <windows.h>
#include <time.h>


int main()
{
///\brief Main function.
    ///
    ///Function calls of crypt and decrypt.

    printf("\nPlease enter a string:\t");

    srand(time(NULL));
    
    struct message test;
    test.text = (char*) malloc(1000*sizeof(char));
    gets(test.text);
    test.size = strlen ( test.text );

    struct message test2;

    test2 = decrypt( test );
     
    print_array( test2 );
    printf("\n");

    test = crypt ( test2 );

    print_array( test );
        printf("\n");

    test2 = decrypt( test );

    print_array( test2 );
        printf("\n");

    system("pause");
        return 0;
}

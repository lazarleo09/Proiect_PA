///\file message.c
///\brief C file implementation for crypt/decrypt functions.
///
/// Created by Lazar Leonard Ruben on 01/06/18.



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generators.h"

struct message
{///\var struct message Structure used to store the message  
    char *text;
    int size;
};

void print_array( struct message array )
{
    ///\fn print_array() 
        ///\brief This function print on the console screen the message array. 
        ///\param array Structure variable used to store the message. 
        ///\var i A variable used for iteration. 

    int i;

    for( i = 0; i < array.size; i++ )
    {
        printf ("%c", array.text[i]);
    }
}

struct message decrypt( struct message array )
{    

    ///\fn decrypt () 
        ///\brief This function return the decrypted message. 
        ///\param array The message that will be decrypted. 
        ///\var letter A variable used to store current letter 
        ///\var last_letter A variable used to store the precedent letter 
        ///\var apparitions A variable used to counter the apparitions of a letter 
        ///\var i A variable used for iteration.
        ///\var d_array A structure variable used to store the decrypted message.   



    char letter = '+';
    char last_letter = '*';
    int apparitions = 1;
    int i;
    struct message d_array;
    d_array.size = 0;
    d_array.text = (char *) malloc(d_array.size * sizeof(char));

    for( i = 0; i < array.size + 2; i++ )
    {
        if( letter != last_letter )
        {
            if( prime_no( apparitions ) )
            {
                d_array.size++;
                d_array.text = (char *)realloc( d_array.text, d_array.size * sizeof(char) );
                d_array.text[d_array.size - 1] = last_letter;
            }

            apparitions = 1;
            last_letter = letter;
            letter = array.text[i];
        }
        else
        {
            apparitions++;
            last_letter = letter;
            letter = array.text[i];
        }
    }

    return d_array;
}

struct message crypt ( struct message array )  
{    

    ///\fn crypt () 
        ///\brief This function return the crypted message. 
        ///\param array The message that will be crypted. 
        ///\var letter A variable used to store current letter 
        ///\var last_letter A variable used to store the precedent letter 
        ///\var apparitions A variable used to counter the apparitions of a letter 
        ///\var i A variable used for iteration. 
        ///\var j A variable used for iteration.
        ///\var flag A flag variable. when (flag == 1) then there will be a non prime array of a letter.
        ///\var c_array A structure variable used to store the crypted message. 


 

    struct message c_array;
    c_array.size = 0;
    c_array.text = (char *) malloc(c_array.size * sizeof(char));
    int j = 0;
    char letter;
    int letter_num;
    int flag;
    int i;

    for( i = 0; i < array.size; i++)
    {
        flag = rand() % 2;

        while( flag )
        {
            generate_letter( &letter );
            generate_non_prime( &letter_num );
            c_array.size += letter_num;
            c_array.text = (char *) realloc( c_array.text, c_array.size);

            for( ; j < c_array.size; j++ )
            {
                c_array.text[j] = letter;
            }

            flag = rand() %2;
        }

        generate_prime( &letter_num );
        c_array.size += letter_num;
        c_array.text = (char *) realloc( c_array.text, c_array.size);

        for( ; j < c_array.size; j++ )
        {
            c_array.text[j] = array.text[i];
        }
    }

    return c_array;
}

///\file generators.c
///\brief C library implementation for generating assets used in solving the crypting and decrypting of a text.
///
/// Created by Lazar Leonard Ruben on 01/06/18.
///
/// Implements prime number check , letter generator , prime number generator , non prime number generator.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prime_no( int number )
{
///\fn int prime_no()
    ///\brief Checks if a number is prime.
    ///
    int i;

    if( number == 0 || number == 1 ) return 0;

    for( i = 2; i < number / 2 + 1; i ++ )
    {
        if( number % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

void generate_letter(char *letter)
{
///\fn generate_letter()
    ///\brief Generates a random letter.
    ///
    
    int pick , var;
    pick = rand() % 2 ;

    if(pick==0)
    {
        var = rand() % 26 ;
        var = var + 97 ;
        *letter = var ;
    }
    else
    {
        var = rand() % 26 ;
        var = var + 65 ;
        *letter = var ;
    }
}

void generate_prime(int *n)
{
///\fn generate_prime()
    ///\brief Generates a prime number from 2 to 13 
    ///
    /// int stock is an array used to store the first 6 prime numbers , only those were used to ease the readability of crypted messages output.
    int stock[6] = {2,3,5,7,11,13};
    int pick , i ;
    pick = rand() % 6 ;
    *n = stock[pick];
}

void generate_non_prime(int *n)
{
///\fn generate_non_prime()
    ///\brief Generates a non prime number from 1 to 14 
    ///
    int pick = 2;

    while( prime_no( pick ) )
    {
        pick = rand()%14 ;
    }

    *n = pick;
}
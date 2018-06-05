///\file message.h
///\brief C library implementation for crypt/decrypt functions.
///
/// Created by Lazar Leonard Ruben on 01/06/18.
///
/// Implements prime number check , letter generator , prime number generator , non prime number generator.

struct message{
    char *text;
    int size;
};

void print_array( struct message array );
struct message decrypt( struct message array );
struct message crypt ( struct message array );

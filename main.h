#ifndef MAIN_H
#define MAIN_H

#include "dosato_source/dosato.h" // Include the dosato library.

// each library must have a dosatoFunctionMapList called functions
DosatoFunctionMapList functions;

// each library must have a function called init that initializes the functions
void init();


Value sumTest (ValueArray args, bool debug);

#endif // MAIN_H
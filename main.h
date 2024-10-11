#ifndef MAIN_H
#define MAIN_H

#include "dosato_source/dosato.h" // Include the dosato library API


// each library must have a function called init that initializes the functions
void init(void* vm);

// each library must have a dosatoFunctionMapList called functions
DosatoFunctionMapList functions;

// function forward declaration
Value sumTest (ValueArray args, bool debug);

#endif // MAIN_H
#include "main.h"

DosatoFunctionMapList functions;
void* main_vm;

void init(void* vm) {
    // must set vm to the main_vm
    main_vm = vm;

    // make sure to initialize the functions list
    init_DosatoFunctionMapList(&functions);

    // add the functions to the list, these functions can be called from the dosato code
    write_DosatoFunctionMapList(&functions, (DosatoFunctionMap){"sumTest", sumTest});
}

/**
 * Function must return Value, take ValueArray as arguments and a bool for debug.
 */
Value sumTest (ValueArray args, bool debug) {
    // check if the number of arguments is correct
    if (args.count != 2) {
        return BUILD_EXCEPTION(E_WRONG_NUMBER_OF_ARGUMENTS);
    }

    // get the arguments
    Value a = GET_ARG(args, 0);
    Value b = GET_ARG(args, 1);

    // check if the arguments are floats, if so, cast them to double
    if (ISFLOATTYPE(a.type) || ISFLOATTYPE(b.type)) {
        CAST_SAFE(a, TYPE_DOUBLE);
        CAST_SAFE(b, TYPE_DOUBLE);

        // return the sum of the two arguments with BUILD_DOUBLE
        return BUILD_DOUBLE(a.as.doubleValue + b.as.doubleValue);
    }

    // cast them to long
    CAST_SAFE(a, TYPE_LONG);
    CAST_SAFE(b, TYPE_LONG);

    // return the sum of the two arguments with BUILD_LONG
    return BUILD_LONG(a.as.longValue + b.as.longValue);
}
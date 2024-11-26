#include "main.h"

DosatoFunctionMapList functions;
void* main_vm;

void init(void* vm) {
    // must set vm to the main_vm, in order for the garbage collector to work, this is required
    main_vm = vm;

    // make sure to initialize the functions list
    init_DosatoFunctionMapList(&functions);

    // add the functions to the list, these functions are exposed and can be called from the dosato code
    write_DosatoFunctionMapList(&functions, (DosatoFunctionMap){"sumTest", sumTest});
}

/**
 * Function must return `Value`, take `ValueArray` as arguments and a `bool` for debug.
 */
Value sumTest (ValueArray args, bool debug) {
    // check if the number of arguments is correct
    if (args.count != 2) {
        // throw an exception by returning BUILD_EXCEPTION
        return BUILD_EXCEPTION(E_WRONG_NUMBER_OF_ARGUMENTS);
    }

    // get the arguments
    Value a = GET_ARG(args, 0); // GET_ARG is a macro that gets the argument at the given index (because the arguments are in reverse order)
    Value b = GET_ARG(args, 1);

    // check if the arguments are floats, if so, cast them to double
    // Always make sure the type is correct before using the value
    if (ISFLOATTYPE(a.type) || ISFLOATTYPE(b.type)) {
        CAST_SAFE(a, TYPE_DOUBLE); // use the CAST_SAFE macro to cast the value to the correct type (Doesn't apply to strings)
        CAST_SAFE(b, TYPE_DOUBLE);

        // return the sum of the two arguments with BUILD_DOUBLE
        return BUILD_DOUBLE(AS_DOUBLE(a) + AS_DOUBLE(b)); // AS_DOUBLE is a macro that gets the double value of the value
    }

    // cast them to long
    CAST_SAFE(a, TYPE_LONG);
    CAST_SAFE(b, TYPE_LONG);

    // return the sum of the two arguments with BUILD_LONG
    return BUILD_LONG(AS_LONG(a) + AS_LONG(b));
}
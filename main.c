#include "main.h"

DosatoFunctionMapList functions;

void init() {
    // make sure to initialize the functions list
    init_DosatoFunctionMapList(&functions);

    // add the functions to the list
    write_DosatoFunctionMapList(&functions, (DosatoFunctionMap){"sumTest", sumTest});
}

Value sumTest (ValueArray args, bool debug) {
    if (args.count != 2) {
        return BUILD_EXCEPTION(E_WRONG_NUMBER_OF_ARGUMENTS);
    }

    Value a = GET_ARG_COPY(args, 0);
    Value b = GET_ARG_COPY(args, 1);

    if (ISFLOATTYPE(a.type) || ISFLOATTYPE(b.type)) {
        CAST_SAFE(a, TYPE_DOUBLE);
        CAST_SAFE(b, TYPE_DOUBLE);

        return BUILD_VALUE(TYPE_DOUBLE, doubleValue, a.as.doubleValue + b.as.doubleValue);
    }

    CAST_SAFE(a, TYPE_LONG);
    CAST_SAFE(b, TYPE_LONG);

    return BUILD_VALUE(TYPE_LONG, longValue, a.as.longValue + b.as.longValue);
}
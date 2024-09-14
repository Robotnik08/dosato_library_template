# Template library for Dosato

This is a template library for Dosato, a programming language.<br>
More information about Dosato can be found [here](https://github.com/Robotnik08/cdosato).

## How to use

This repository contains a dosato.h and dosato_lib.dll file, these might be outdated in the future, so if you want to use the latest version of Dosato you can download it from the [official repository](https://github.com/Robotnik08/cdosato).<br>

To use this library, you need to include the dosato.h file in your project and link the dosato_lib.dll file to your project.<br>

For this particular demo, use the following command to compile the program:<br>
```bash
make
```

This will generate the .dll file for your library.<br><br>

To test and use your library from within Dosato, open your script file and use the `import` keyword to import your library.<br>
```dosato
import "path/to/your/library.dll";
```

After importing your library, you can use the functions defined in your library.<br>
```dosato
import "path/to/your/library.dll";

do sayln(sumTest(5, 10));
```

The `test.to` file in contains an example of how to use this library.<br>
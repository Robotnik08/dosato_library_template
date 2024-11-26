# Template library for Dosato

This is a template library for Dosato, a programming language.<br>
More information about Dosato can be found [here](https://github.com/Robotnik08/cdosato).

## How to use

This repository contains a dosato.h and libdosato.dll file, these might be outdated in the future, so if you want to use the latest version of Dosato you can download it from the [official repository](https://github.com/Robotnik08/cdosato).<br>

To use this library, you need to include the dosato.h file in your project and link the dosato_lib.dll or dosato_lib.so file to your project.<br>

This demo contains only the header file, compile or fetch the .dll/.so file from the official repository.<br>
If you have Dosato installed, you can also find the .dll/.so file in the installed Dosato directory.<br>

For this particular demo, use the following command to compile the program:<br>
```bash
make
```

This will generate the .dll or .so file for your library.<br><br>

To test and use your library from within Dosato, open your script file and use the `import` keyword to import your library.<br>
Dosato will automatically append the .dll or .so file to the path you provide in the import statement.<br>

```dosato
import "path/to/your/library";
```

After importing your library, you can use the functions defined in your library.<br>
```dosato
import "path/to/your/library";

do sayln(sumTest(5, 10));
```

The `test.to` file in contains an example of how to use this library.<br>
# __Data Struct__

## __Quick Start__
 - Install the GCC or other C compiler.
 - Create the `bin` directory in the repository root.
 - All ready.

## __Table of Programs__
__Note__: For compile the codes and run them, you should execute the commands in the same location as the README.md file. Execute the program on your Linux terminal with the following command `./bin/program-name`.

### __Sort__
|Algorithm Name|Command to Compile|
|:---|:---|
|Bubble Sort|`gcc src/bubble-sort.c -o ./bin/bubble-sort.exe`|
|Selection Sort|`gcc src/selection-sort.c -o ./bin/selection-sort.exe`|
|Insertion Sort|`gcc src/util/array-util.c src/insertion-sort.c -o ./bin/insertion-sort.exe`|

### __Technique__
|Technique Name|Command to Compile|
|:---|:---|
|Abstract Data Type|`gcc src/abstract-data-type/cube.c src/abstract-data-type/main.c -o bin/adt-cube.exe`|`./bin/adt-cube.exe`|

### __Lists__
|Name|Command to Compile|
|:---|:---|
|Static List|`gcc ./src/list/static/main.c ./src/list/static/static-list.c  -o ./bin/static-list.exe`|
|Dynamic List|`gcc ./src/list/dynamic/main.c ./src/list/dynamic/dynamic-list.c  -o ./bin/dynamic-list.exe`|

## __References__
Backes, André Ricardo. Estrutura de Dados descomplicada: em linguagem C. 1. ed - Rio de Janeiro: Elsevier, 2016
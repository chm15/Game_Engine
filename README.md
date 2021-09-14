# Game Engine  ![Build](https://github.com/chm15/Game_Engine/workflows/CMake/badge.svg)

This is an entity-component-system multiplayer game engine (WIP).
  
## Building

``` shell
# From the base directory:
cd Build
cmake ../
make
```

## Testing
Run unit-tests:
``` shell
# From the base directory:
cd Build
cmake ../
make
make test
```

Debug a specific unit-test:
``` shell
# From the base directory:
cd Build
cmake ../ -DCMAKE_BUILD_TYPE=Debug
make
gdb Test/test_[SOME UNIT TEST]
```

## Build Documentation

Python is required. This will make a text file in the base directory called "Documentation.txt".  
``` shell
# From the base directory:
python MakeDocumentation.py
```

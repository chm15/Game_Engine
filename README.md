# Game Engine

This is an entity-component-system based multiplayer game engine.
  
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

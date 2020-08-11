# first pros project

to create a project use the command `prosv5 conductor new-project <folder>` where <folder> is the folder for the pros project. the current folder is `.`
``` 
gigantor@pop-os:~/Documents/GitHub/pros-example$ prosv5 conductor new-project .
Updating pros-mainline... Done
Applying kernel@3.2.1 [####################################] 100%
Finished applying kernel@3.2.1 to .
Applying okapilib@4.0.4 [####################################] 100%
Finished applying okapilib@4.0.4 to .
New PROS Project was created:
PROS Project for v5 at: /home/gigantor/Documents/GitHub/pros-example (pros-example)
Name Version Origin
-------- --------- -------------
kernel 3.2.1 pros-mainline
okapilib 4.0.4 pros-mainline
Building project...
Creating cold package with libpros,libc,libm,okapilib [OK]
Stripping cold package [DONE]
Section sizes:
text data bss total hex filename
1.56MB 4.33KB 47.62MB 49.19MB 312e17f bin/cold.package.elf
Compiled src/main.cpp [OK]
Adding timestamp [OK]
Linking hot project with ./bin/cold.package.elf and libpros,libc,libm,okapilib [OK]
Section sizes:
text data bss total hex filename
1.13KB 4.00B 2.00B 1.14KB 486 bin/hot.package.elf
Creating cold package binary for VEX EDR V5 [DONE]
Creating bin/hot.package.bin for VEX EDR V5 [DONE]
```

next I like to customize the `main.h` file: (line numbers given for pros kernel version 3.2.1)
35 `#define PROS_USE_LITERALS` -> `// #define PROS_USE_LITERALS`
42 `//#include "okapi/api.hpp"` -> `#include "okapi/api.hpp"`
55 `// using namespace okapi;` -> `using namespace okapi;`
`main.h` describes what each of these lines do

next try compiling then uploading then running the generated program
use the command `prosv5 make` this will compile (and link) the code into binary that can run on a V5 brain

next upload the last compiled binaries with the command `prosv5 upload`
next make sure your robot controller is paired with the robot, and no one is messing with the joysticks. then run the program
# summary
the normal way to upload your program to your brain will be:
1. compile: `prosv5 make`
2. upload: `prosv5 upload`
3. run: `prosv5 v5 run`

# where to write your code
the simplest way to write your code is in `src/main.cpp` this file has comments explaining what each function does/is useful for. 
```void autonomous();
void initialize();
void disabled();
void competition_initialize();
void opcontrol();
```
These functions are pros callback functions. AKA they are the functions pros will call when your robot is enabled/on.
you are meant to write put your code in these function bodies the `{ here }` parts

as your program gets more complicated, or you want to organize your code better, it is recommended to use multiple files (AKA ***ish*** C++ translation units). when doing this it is highly recommended to use header files (.hpp for C++ or .h for C). this can greatly improve code readability and portability. there are videos of how to do this online, I would recommend `The Cherno` on YouTube as it is a quality channel and YouTube is accessible. I would recommend watching:
```
C++ Header Files
How the C++ Compiler Works
How the C++ Linker Works
CLASSES in C++
How to Write a C++ Class
```
In general just do some research I'm sure you can find enough to overwhelming

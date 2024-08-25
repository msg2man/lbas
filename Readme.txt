Load Balancing Algorithm Simulator (lbas)
-----------------------------------------

lbas is a command line program written in C++11, that can be used to simulate running of
load balancing algorithms. 

Configuration parameters can be specified on the cmd line.

Example Usage:
./LBASimulator --servers "10" --tasks "100" --algorithm "PTC" --latencies "5" "10" --capabilities "1" "2";

It uses open source cmdparser header file from Florian (https://github.com/FlorianRappl/CmdParser).

Building
--------
lbas uses cmake to generate Makefiles and gnu gcc 11.4 compiler. It has been compiled on WSL and should
be able to compile on any OS provided the cmake and gcc are present.

- Clone the repo
- cd to <src dir> and make a dir called build
- cd to build dir and generate Makefiles using "cmake -DCMAKE_BUILD_TYPE=Release|Debug .."
- Build the project using "make", a binary named LBASimulator will be generated in the folder target


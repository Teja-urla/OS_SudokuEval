*********************************************************************************
             Assignment 2(pthread) - ReadMe file			CS21BTECH11059
*********************************************************************************

DESCRIPTION OF THE PROGRAM:
***************************
This is a multithreaded program that evaluates

Instructions To Execute:
************************
===> for Assgn2SrcpthreadCS21BTECH11059.cpp file:
=>  run the following command to compile the program:
    g++ Assgn2SrcpthreadCS21BTECH11059.cpp -lpthread 
=> Then run the following command:
    ./a.out
===> for Assgn2SrcOpenMpCS21BTECH11059.cpp file
=>  run the following command to compile the program:
    g++ Assgn2SrcOpenMpCS21BTECH11059.cpp -lm -fopenmp
=> Then run the following command:
    ./a.out    

Instructions To Follow:
***********************
The input file i.e inp.txt and the source code file i.e Assgn2SrcpthreadCS21BTECH11059.cpp and Assgn2SrcOpenMpCS21BTECH11059.cpp should be in the same folder.
In the input.txt file you have to write the number of points first and then the number of threads seperated by a space or a '\n'.

sizeof the matrix(n * n)=> n should be greater than 3 times number of threads.
n should be positive(Obiviously). Otherwise it the source code will give an error

You will get the desired output for valid inputs.
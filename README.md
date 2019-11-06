# Generic Array Algorithms Library - GRAAL

## About the project
In this exercise you should develop a series of functions that represent typical algorithms for array manipulation. Because we are still following an imperative programming paradigm, all functions should receive the range we wish to operate on as an argument. The primary goal of this exercise is to practice a higher level of abstract programming, where our code does not need to know in advance which type of data we are operating on. To do that our code requires the use of function template in association with function pointers. The former supports the passage of generic arguments to functions, whereas the latter helps us to defer some decisions to the client by allowing them to provide the code to operate on data. The secondary objective is to acquire programming experience by building a library of typical algorithms on arrays, called `GRAAL` — GeneRic Array Algorithms Library. By building this generic library we want to demonstrate the importance of programming abstraction and code reuse while developing an application in the next exercise.


## Compile and running
```bash
$ cmake -S . -Bbuild && cd build/
```

Visualization:
```bash
$ ./graal_driver
```
Google tests - By Professor Selan Rodrigues
```bash
$ ./selantests
```


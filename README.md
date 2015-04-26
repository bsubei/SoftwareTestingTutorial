# Summary
This short tutorial for software testing is an extra-credit mini-project I
made for my Programming Practicum class: CS 211 at UIC (which is supposed to
teach software engineering practices and tools). I thought it was necessary to
include some sort of material on software testing (since it's so crucial to
software engineering outside of academia-land), and I hope it helps people
get started with software testing.

# Introduction
This short tutorial will introduce some concepts about software testing, and how to get started with testing using the `GoogleTest` framework.

## GoogleTest? WTH?
What is `GoogleTest`? From [their website](https://code.google.com/p/googletest/): It's just Google's framework for writing C++ tests. I highly recommend you use their [Primer tutorial](https://code.google.com/p/googletest/wiki/V1_7_Primer#Assertions) as you go along this tutorial.

## Tests?
What do you mean "writing tests?" You mean a bunch of code that prints debug output that the programmer checks? Well, kind of. But think on a more efficient and larger scale, and the test checks the output for you (no more scrolling through endless lines of output crying about your decision to take up programming in the first place).

I won't write a book about software testing (mainly because I am no expert), but besides referring you to the [wikipedia page](http://en.wikipedia.org/wiki/Software_testing), I'll just invite you to imagine this scenario:

Imagine you sit down and try to define the requirements of your program. For simplicity, let's just say you define what it's supposed to output for every possible input. Now you can write some code that executes your original code, throws in some input, and alerts you if the output is not as expected. In a nutshell, this is what testing is all about (defining specs that your code should follow).

`GoogleTest` just provides an easy way to write and run tests for your C/C++ code. A quick usage example for now will suffice (more details in later sections): You write some C code for defining a stack data structure, and functions like `push()` and `pop()`. Then you write a test, which creates a stack and executes the functions. It then makes sure that you do those operations correctly (such as checking for the size of your stack after x `push`'es, etc.) When you run the test, it prints out `PASSED` in green if the tests pass, and `FAILED` in red if the tests fail (it also gives you details on why it failed). Check the `StackTestSuccess.png` screenshot below. This is what you should get at the end of the tutorial.

![Simple Stack Test Success](https://github.com/basheersubei/SoftwareTestingTutorial/blob/master/Screenshots/StackTestSuccess.png)

## Awesome Potential of Testing
I hear you say: "so, what? I could've just written that test code into my main when I need to test it or used a boolean TEST flag and just ran my program."

My response:

0- Eww. :-1: That is ugly, clunky (copy-paste error-prone), and wouldn't have a snow-ball's-chance-in-hell to be done that way in production-quality software. Do it the right way, please (you might as well learn now, as it makes life much easier). It's not just Google that writes tests (you don't have to stick to `GoogleTest` framework, just use some sort of testing method).

1- Separate test code from actual code-base (goodbye ugly and misplaced DEBUG statements). Now you can focus on improving and extending the tests to include more cases.

2- [Regression testing](http://en.wikipedia.org/wiki/Regression_testing). Every time any code is changed (patches, new features, etc), your entire code-base is tested to make sure **nothing** broke. Goodbye, elusive ghost bugs! With good enough tests, this will make your code as bug free as you can get! :smile:

3- [Automated testing](http://en.wikipedia.org/wiki/Test_automation). Holy momma! :open_mouth: You mean it can do this automatically? Every time I change my code? Can it also automatically test new changes to my code, send me an email if it fails, and have a neato status icon? For free? Yes! Use [Travis](https://travis-ci.org/) with [GitHub](https://github.com/)! :sunglasses:

4- [Test-driven Development](http://en.wikipedia.org/wiki/Test-driven_development). This might sound crazy, but a lot of times it's better to write the **tests first** before you write your actual **code**. It helps you define your requirements and input/output early on (before you get all caught up and distracted in an ugly mess of spaghetti code). Once you write down the tests, you know what your code should do, and so you can start working on writing per those specs. Of course, your tests would all fail at this point, but slowly, as you write your code, more and more tests will pass until you are all green. (best feeling in the world when all your tests go green!) :+1:

# GoogleTest Tutorial

## Note about compatibility
While GoogleTest should work fine with Windows, I don't have the time nor the interest to include Windows in this tutorial. Just use a Linux or Mac machine to follow along. It'll be good for you (need to learn how to use the terminal). This tutorial uses `Make` and `Makefile`s to build GoogleTest files, but advanced users can probably figure out other ways (like `CMake`).

## Project folder structure and files
 - SoftwareTestingTutorial (root project folder)
    - gtest-1.7.0 (folder that contains gtest source code)
    - Examples (folder that contains example C/C++ code and tests)
       - **stackExample.h**: header file that describes the definition of a stack and declares its functions (taken from my solution of [CS211](https://github.com/basheersubei/CS211) hw2)
       - **stackExample.c**: source code file that defines those functions.
       - **example_test.cc**: this is my test file. Inside of it, I define all the tests I will run. (don't worry about the `.cc` extension, it's pretty much the same as `.cpp` for C++).
       - **Makefile**: the file that defines what needs to be compiled and how they are linked. Don't worry! You'll most likely never need to change this much (besides file names and such).

## How to compile/run the example
 - Navigate to the `Examples` folder using `cd Examples` command.
 - Compile the tests and code using Makefile. Just run `make`.
 - Now you can run the test executable (called example_test here). Just type in `./example_test` in the terminal.

## Notes about the example
 - Notice the code in `stackExample.c` only defines a stack and its functions, but doesn't do anything with it (there's no `main` function). I didn't include one because it's irrelevant to the tutorial. The point here is to test your functions and data structures.
 - Take a look at the tests in example_test. Look at the simpler ones first. Notice the first one named `StackTest.OneElementStack` just creates a stack with one element (an int), checks that the stack is not empty or null pointer, and checks that the value of top element (using peek) in the stack is the same we put in. Notice how it calls the code from stackExample.c directly, with no need for a main. These tests are effectively your main when you run the tests.
 - The actual "checking" part of the test are the `EXPECT_xxx` lines. These are just assertions. 
 - The second test creates a stack, pushes another element onto it, and then checks that the element (using peek) is the same as what we pushed in.
 - The third test is a more complicated test that generates random ints, pushes them on the stack one by one, then pops them all one by one. At every step, it checks that the values are what we expect. That test was the only code I needed to debug the whole program, because once it passed, I knew the stack and its functions behaved the way I wanted (according to my test).
 - You might've noticed a bunch of GoogleTest compiled files in your directory (don't worry, just ignore these). You can clear your directory again by running `make clean` if you want to.

## How to use GoogleTest with your own code
"Ok, but how do I use GoogleTest for my own code, not yours?" Pretty simple:

### Make a Makefile
 - First, modify your `Makefile` to compile the desired files you have. Just copy-paste the Makefile I have (as a matter of fact, just copy the entire folder while you're at it and replace my example code with your actual code).
 - Then, replace the words "stackExample" with your code filename. The `Makefile` assumes you have a `.h` file as well.
 - Now, replace the words "example_test" with your test's filename (or just leave it as it is if you're lazy).

### Write your [tests](https://code.google.com/p/googletest/wiki/V1_7_Primer#Simple_Tests)
 - You can copy-paste the `example_test` for now.
 - Include your C code header file (don't leave it as `stackExample.h`). You don't need `cmath` or `limits.h` unless your tests use them (like with random numbers and stuff).
 - Now, each of your tests will basically look like this:

 		TEST(FirstCaseTest, TestName) {
 			// do stuff here
		}

### Compile and run your tests
 - Just type in `make` to compile, then run the executable. :smile:

# JUnit (for Java)

## How to install and run a basic test
The following steps come from this [UbuntuAnswers answer](http://askubuntu.com/a/120946/190889):

 - Just install junit from apt-get if you're on Linux: `sudo apt-get install junit`
 - Write your tests, then compile them in java and make sure you include your junit jar file in the classpath when compiling.
 - Now run your code, including JUnitCore, and don't forget to include classpath again.

## Example
Let's say you want to compile and run the BasicTest.java test (found in Examples folder):
 - Compile using `javac -cp /usr/share/java/junit4.jar TestBasic.java`
 - Run the test using `java -cp /usr/share/java/junit4.jar:. org.junit.runner.JUnitCore TestBasic`
[TOC]
# Introduction
This short tutorial will introduce some concepts about software testing, and how to get started with testing using the `GoogleTest` framework.

## GoogleTest? WTH?
What is `GoogleTest`? From [their website](https://code.google.com/p/googletest/): It's just Google's framework for writing C++ tests.
## Tests?
What do you mean "writing tests?" You mean a bunch of code that prints debug output that the programmer checks? Well, kind of. But think on a more efficient and larger scale, and the test checks the output for you (no more scrolling through endless lines of output crying about your decision to take up programming in the first place).

I won't write a book about software testing (mainly because I am no expert), but besides referring you to the [wikipedia page](http://en.wikipedia.org/wiki/Software_testing), I'll just invite you to imagine this scenario:

Imagine you sit down and try to define the requirements of your program. For simplicity, let's just say you define what it's supposed to output for every possible input. Now you can write some code that executes your original code, throws in some input, and alerts you if the output is not as expected. In a nutshell, this is what testing is all about (defining specs that your code should follow).

`GoogleTest` just provides an easy way to write and run tests for your C/C++ code. A quick usage example for now will suffice (more details in later sections): You write some C code for defining a stack data structure, and functions like `push()` and `pop()`. Then you write a test, which creates a stack and executes the functions. It then makes sure that you do those operations correctly (such as checking for the size of your stack after x `push`'es, etc.) When you run the test, it prints out `PASSED` in green if the tests pass, and `FAILED` in red if the tests fail (it also gives you details on why it failed). Check the `StackTestSuccess.png` screenshot.

## Awesome Potential of Testing
I hear you say: "so, what? I could've just written that test code into my main when I need to test it or used a boolean TEST flag and just ran my program."

My response:

0- Eww. :-1: That is ugly, clunky (copy-paste error-prone), and wouldn't have a snow-ball's-chance-in-hell to be done that way in production-quality software. Do it the right way, please (you might as well learn now, as it makes life much easier). It's not just Google that writes tests (you don't have to stick to `GoogleTest` framework, just use some sort of testing method).

1- Separate test code from actual code-base (goodbye ugly and misplaced DEBUG statements). Now you can focus on improving and extending the tests to include more cases.

2- [Regression testing](http://en.wikipedia.org/wiki/Regression_testing). Every time any code is changed (patches, new features, etc), your entire code-base is tested to make sure **nothing** broke. Goodbye, elusive ghost bugs! With good enough tests, this will make your code as bug free as you can get! :smile:

3- [Automated testing](http://en.wikipedia.org/wiki/Test_automation). Holy momma! :open_mouth: You mean it can do this automatically? Every time I change my code? Can it also automatically test new changes to my code, send me an email if it fails, and have a neato status icon? For free? Yes! Use [Travis](https://travis-ci.org/) with [GitHub](https://github.com/)! :sunglasses:

4- [Test-driven Development](http://en.wikipedia.org/wiki/Test-driven_development). This might sound crazy, but a lot of times it's better to write the **tests first** before you write your actual **code**. It helps you define your requirements and input/output early on (before you get all caught up and distracted in an ugly mess of spaghetti code). Once you write down the tests, you know what your code should do, and so you can start working on writing per those specs. Of course, your tests would all fail at this point, but slowly, as you write your code, more and more tests will pass until you are all green. (best feeling in the world when all your tests go green!) :+1:

# GoogleTest tutorial

## Installation (using Makefiles)

## Examples (from CS 211 projects)


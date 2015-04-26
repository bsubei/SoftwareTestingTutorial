// Copyright 2005, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A sample program demonstrating using Google C++ testing framework.
//
// Author: wan@google.com (Zhanyong Wan)


// This sample shows how to write a simple unit test for a function,
// using Google C++ testing framework.
//
// Writing a unit test using Google C++ testing framework is easy as 1-2-3:


// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// Don't forget gtest.h, which declares the testing framework.

#include <limits.h>
#include <cmath>
#include "stackExample.h"
#include "gtest/gtest.h"


// Step 2. Use the TEST macro to define your tests.
//
// TEST has two parameters: the test case name and the test name.
// After using the macro, you should define your test logic between a
// pair of braces.  You can use a bunch of macros to indicate the
// success or failure of a test.  EXPECT_TRUE and EXPECT_EQ are
// examples of such macros.  For a complete list, see gtest.h.
//
// <TechnicalDetails>
//
// In Google Test, tests are grouped into test cases.  This is how we
// keep test code organized.  You should put logically related tests
// into the same test case.
//
// The test case name and the test name should both be valid C++
// identifiers.  And you should not use underscore (_) in the names.
//
// Google Test guarantees that each test you define is run exactly
// once, but it makes no guarantee on the order the tests are
// executed.  Therefore, you should write your tests in such a way
// that their results don't depend on their order.
//
// </TechnicalDetails>

TEST(StackTest, OneElementStack) {
    // create an int
    int n1 = 77;

    // create a stack and put one int in it
    Node* top = stack_initialize(n1);

    // make sure the top pointer isn't null
    EXPECT_FALSE(top == NULL);
    // make sure the stack is not empty
    EXPECT_FALSE(is_empty(top));

    // make sure the top element in stack is same as n1
    int n2 = stack_peek(top);  // get top element
    EXPECT_EQ(n2, n1);  // check that int values are same
}

TEST(StackTest, PushOne) {
    // create an int
    int n1 = 77;

    // create a stack and put one int in it
    Node* top = stack_initialize(n1);

    // create another int
    int n2 = 25;

    // push it onto stack
    stack_push(&top, n2);

    // now check that the top element is the same as n2
    int n3 = stack_peek(top);
    EXPECT_EQ(n3, n2);
}

TEST(StackTest, InitializeRandomStack) {
    srand(time(NULL));  // initialize random seed

    // first, make an array of random ints
    int const ARRAY_SIZE = 1000;
    int random[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++)
        random[i] = rand();

    // then, initialize stack and fill it up with contents of random
    Node* top = stack_initialize(random[0]);
    EXPECT_FALSE(top == NULL);
    for (int i = 1; i < ARRAY_SIZE; i++) {
        // check stack is_empty not true
        EXPECT_FALSE(is_empty(top));

        // check previous element
        EXPECT_EQ(random[i-1], stack_peek(top));

        // now add new element
        stack_push(&top, random[i]);
    }

    int n = stack_peek(top);
    EXPECT_EQ(random[ARRAY_SIZE-1], n);


    // now pop all elements and check contents, notice decrementing loop
    for (int i = ARRAY_SIZE-1; i >= 0; i--) {
        // check stack is_empty not true
        EXPECT_FALSE(is_empty(top));

        int n = stack_peek(top);
        // check current element
        EXPECT_EQ(random[i], n);

        // now pop an element
        stack_pop(&top);
    }

    // now stack should be empty
    EXPECT_TRUE(is_empty(top));
}

// Step 3. Call RUN_ALL_TESTS() in main().
//
// We do this by linking in src/gtest_main.cc file, which consists of
// a main() function which calls RUN_ALL_TESTS() for us.
//
// This runs all the tests you've defined, prints the result, and
// returns 0 if successful, or 1 otherwise.
//
// Did you notice that we didn't register the tests?  The
// RUN_ALL_TESTS() macro magically knows about all the tests we
// defined.  Isn't this convenient?

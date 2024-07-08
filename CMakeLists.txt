cmake_minimum_required(VERSION 3.28)
project(leetcode C)
set(LINUX )
set(CMAKE_C_STANDARD 11)

add_executable(leetcode testLinkedList.c
        myBinaryTree.c
        myMath.c
        myStack.c
        myString.c
        myArray.c
        itertools.c
        myQueue.c
        myQueue.h
        mySearch.c
        mySearch.h
        myLinkedList.c
        myLinkedList.h)

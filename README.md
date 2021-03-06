# libadt - an abstract data types library
![BinaryTree](logo.png)

### Status

[![MIT licensed](https://img.shields.io/github/license/vndmtrx/libadt.svg)](https://github.com/vndmtrx/libadt/blob/master/LICENSE)
[![Build Status](https://travis-ci.org/vndmtrx/check-cmake-example.svg?branch=master)](https://travis-ci.org/vndmtrx/check-cmake-example)
[![codecov](https://codecov.io/gh/vndmtrx/libadt/branch/master/graph/badge.svg)](https://codecov.io/gh/vndmtrx/libadt)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/8b0eaaaf5c4040a8b50c47fb7acc8b92)](https://www.codacy.com/app/vndmtrx/libadt?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=vndmtrx/libadt&amp;utm_campaign=Badge_Grade)

### What is libadt?

Libadt is a C library for those who want to study a little more about Abstract Data Types. The library implements the most common types of structures of computer science and is extremely well documented.

> ADTs are a theoretical concept in computer science, used in the design and analysis of algorithms, data structures, and software systems, and do not correspond to specific features of computer languages - mainstream computer languages do not directly support formally specified ADTs. However, various language features correspond to certain aspects of ADTs, and are easily confused with ADTs proper; these include abstract types, opaque data types, protocols, and design by contract.
> -- [Wikipedia](http://en.wikipedia.org/wiki/Abstract_data_type)

### Why?

Because in C we deal directly with memory, and the structures provided by the language are quite primitive. And since in higher level languages there are other structures (such as classes and objects) that implement many of the features of data structures, there would be no advantage (or learning) in implementing these structures on such languages.

### What Structures do you have now?

* Singly-linked list ([README](src/lib/lists/README.md#singly-linked-lists));
* Doubly-linked list ([README](src/lib/lists/README.md#doubly-linked-lists));
* Deque using doubly-linked list as infrastructure ([README](src/lib/deques/README.md));
* Queues
  * using singly-linked list as infrastructure ([README](src/lib/queues/README.md));
  * using deque as infrastructure ([README](src/lib/queues/README.md));
* Stacks
  * using singly-linked list as infrastructure ([README](src/lib/stacks/README.md));
  * using deque as infrastructure ([README](src/lib/stacks/README.md));

But this repository is in its very beginning and another structures will come in time.

### What structures do you plan to implement?

At the present time, the following structures are being implemented:

* Circular Linked List ([README](src/lib/lists/README.md#a-special-case-circular-linked-lists));

Once completed, the next to be implemented are as follows:

* Trees (Binary Search Tree, AVL Tree, Red-black Tree);
* Heaps;
* Priority Structures (P-Queue, P-Stack and P-Deque);
* Sets using sorted tree as infrastructure;
* Stack and Queue using tree as infrastructure;
* Priority Structures (P-Queue, P-Stack and P-Deque) using sorted tree as infrastructure;
* Associative Arrays;
* Sparse Matrixes;
* Graphs;

### Other related algorithms

When we are dealing with data structures, certain code patterns appear in the form of specialized algorithms to work with each type of structure.

With that in mind, we will be adding these algorithms into another folder to avoid confusion between data structures and algorithms that operate on top of these.

Algorithms implemented:
 * Infix to Postfix converter using Stack;
 * Expression evaluator using Queue;
 * Iterators for Lists;

Algorithms being implemented:
 * Sorting
   * Quick Sort
   * Merge Sort

### Naming structure

In some data structures, you may notice that there is a prefix the name of each function. The prefixes refer to the structures used to build each structure. For example, stacks and queues use the prefix "sl_" because they use a simple linked list internally, in its implementation. This notation is used because, in the future, there can be other implementations using different support structures such as heaps or trees.

### Base Documentation

[Dictionary of Algorithms](https://xlinux.nist.gov/dads/)

### Future and beyond...

There is no future set. Getting to the point we implement all the most common and important structures, other focuses will be defined, always having its focus on the learning provided to the person who will use these structures.

Have fun!

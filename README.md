libadt - an abstract data types library
=======================================

![BinaryTree](logo.png)

### What is libadt?

Libadt is a C library for those who want to study a little more about Abstract Data Types. The library implements the most common types of structures of computer science and is extremely well documented.

> ADTs are a theoretical concept in computer science, used in the design and analysis of algorithms, data structures, and software systems, and do not correspond to specific features of computer languages - mainstream computer languages do not directly support formally specified ADTs. However, various language features correspond to certain aspects of ADTs, and are easily confused with ADTs proper; these include abstract types, opaque data types, protocols, and design by contract.
> -- [Wikipedia](http://en.wikipedia.org/wiki/Abstract_data_type)

### Why?

Because in C we deal directly with memory, and the structures provided by the language are quite primitive. And since in higher level languages there are other structures (such as classes and objects) that implement many of the features of data structures, there would be no advantage (or learning) in implementing these structures.

### What Structures do you have now?

* Single linked list ([README](lib/lists/README.md));

But this repository is in its very beginning and another structures will come in time.

### What structures do you plan to implement?

At the present time, the following structures are being implemented:

* Double linked list;
* Queue using single linked list as infrastructure;
* Stack using single linked list as infrastructure;
* Deque using double linked list as infrastructure;
* Queue and Stack using deque as infrastructure;

Once completed, the next to be implemented are as follows:

* Trees (Binary Search Tree, AVL Tree, Red-black Tree);
* Heaps;
* Associative Arrays;
* Sets;
* Graphs;
* Sparse Matrix;
* Stack and Queue using Tree as infrastructure;

### Future and beyond...

There is no future set. Getting to the point we implement all the most common and important structures, other focuses will be defined, always having its focus on the learning provided to the person who will use these structures.

### Addendum: Code Convention

As we know, everyone has their opinion about code design in programming languages, and C is no different. For this reason, this repository will use the convention explained on the [C Coding Standard] (http://users.ece.cmu.edu/~eno/coding/CCodingStandard.html) site.

Have fun!

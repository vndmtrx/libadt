Lists
=====

In computer science, a linked list is a data structure consisting of a group of nodes which together represent a sequence. Under the simplest form, each node is composed of data and a reference (in other words, a link) to the next node (and in more complex, to the prior element) in the sequence. This structure allows for efficient insertion or removal of elements from any position in the sequence.

The principal benefit of a linked list over a conventional array is that the list elements can easily be inserted or removed without reallocation or reorganization of the entire structure because the data items need not be stored contiguously in memory or on disk, while an array has to be declared in the source code, before compiling and running the program. Linked lists allow insertion and removal of nodes at any point in the list, and can do so with a constant number of operations if the link previous to the link being added or removed is maintained during list traversal.

### List Operations

The common operations executed on lists are the following:

 * create() - Create the list structure;
 * insert() - Add an element in the list, either on specific position or in the head of the list;
 * swap() - Change the position of two elements on the list;
 * remove() - Drop an element from the list, returning its data;
 * destroy() - Destroy the list structure. If there is elements in it, they are destroyed also.

Single Linked Lists
-------------------

### Operations and complexities

Single linked lists are among the simplest and most common data structures. They can be used to implement several other common abstract data types, including lists (the abstract data type), stacks, queues, associative arrays, and S-expressions, though it is not uncommon to implement the other data structures directly without using a list as the basis of implementation.

On the other hand, simple linked lists by themselves do not allow random access to the data, or any form of efficient indexing. Thus, many basic operations — such as obtaining the last node of the list (assuming that the last node is not maintained as separate node reference in the list structure), or finding a node that contains a given datum, or locating the place where a new node should be inserted — may require sequential scanning of most or all of the list elements.

function name | complexity | explanation
:-- | :--:  |:--
slist_create | O(1) | 
slist_insert_el | O(1) | 
slist_swap_el | O(n) | because it needs to find prior element
slist_rem_el | O(n) | because it needs to find prior element
slist_destroy | O(n) | removing in the head avoids the O(n^2)

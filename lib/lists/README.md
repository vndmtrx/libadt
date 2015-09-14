Lists
=====

In computer science, a linked list is a data structure consisting of a group of nodes which together represent a sequence. Under the simplest form, each node is composed of data and a reference (in other words, a link) to the next node (and in more complex, to the prior element) in the sequence. This structure allows for efficient insertion or removal of elements from any position in the sequence.

The principal benefit of a linked list over a conventional array is that the list elements can easily be inserted or removed without reallocation or reorganization of the entire structure because the data items need not be stored contiguously in memory or on disk, while an array has to be declared in the source code, before compiling and running the program. Linked lists allow insertion and removal of nodes at any point in the list, and can do so with a constant number of operations if the link previous to the link being added or removed is maintained during list traversal.

### List Operations

The common operations executed on lists are the following:

 * _create()_ - Create the list structure;
 * _insert()_ - Add an element in the list, either on specific position or in the the list edges;
 * _move()_ - Change position of one element on the list;
 * _swap()_ - Change the position of two elements on the list;
 * _remove()_ - Drop an element from the list, returning its data;
 * _destroy()_ - Destroy the list structure. If there is elements in it, they are destroyed also.

Singly Linked Lists
-------------------

Singly linked lists are among the simplest and most common data structures. They can be used to implement several other common abstract data types, including lists (the abstract data type), stacks, queues, associative arrays, and S-expressions, though it is not uncommon to implement the other data structures directly without using a list as the basis of implementation.

On the other hand, singly linked lists by themselves do not allow random access to the data, or any form of efficient indexing. Thus, many basic operations — such as obtaining the last node of the list (assuming that the last node is not maintained as separate node reference in the list structure), or finding a node that contains a given datum, or locating the place where a new node should be inserted — may require sequential scanning of most or all of the list elements.

### Operations and complexities

function name | complexity | explanation
:-- | :--:  |:--
_slist_create_ | O(1) | 
_slist_insert_el_next_ | O(1) | 
_slist_move_el_ | O(n)| because it needs to find prior element
_slist_swap_el_ | O(n) | because it needs to find prior element
_slist_rem_el_ | O(n) | O(1) if remove the head element
_slist_destroy_ | O(n) | removing in the head avoids the O(n^2)

More on [Wikipedia](https://en.wikipedia.org/wiki/Linked_list)

Doubly Linked Lists
-------------------

Like singly linked lists, doubly-linked list is a linked data structure that consists of a set of sequentially linked records called nodes. However, each node contains two fields, that are references to the previous and to the next node in the sequence of nodes. It can be conceptualized as two singly linked lists formed from the same data items, but in opposite sequential orders.

The two node links allow traversal of the list in either direction. While adding or removing a node in a doubly-linked list requires changing more links than the same operations on a singly linked list, the operations are simpler and potentially more efficient (for nodes other than first nodes) because there is no need to keep track of the previous node during traversal or no need to traverse the list to find the previous node, so that its link can be modified.

### Operations and complexities

function name | complexity | explanation
:-- | :--:  |:--
_dlist_create_ | O(1) | 
_dlist_insert_el_next_ | O(1) | 
_dlist_insert_el_prev_ | O(1) | 
_dlist_move_el_next_ | O(1)| 
_dlist_move_el_prev_ | O(1)| 
_dlist_swap_el_ | O(1) | two move operations
_dlist_rem_el_ | O(1) | 
_dlist_destroy_ | O(n) | 

More on [Wikipedia](https://en.wikipedia.org/wiki/Doubly_linked_list)

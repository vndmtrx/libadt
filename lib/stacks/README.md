Stacks
======

In computer science, a stack is a abstract data type in which the entities are stacked in order and the mainly operations are the addition of and removal from the front position. This makes the queue a Last-In-First-Out (LIFO) data structure. In a LIFO data structure, the first element added to the queue will be the last one to be removed. 

Stacks are extensively used in computation, as it is used to define local variables in functions along it's calls. It's because of this behavior that it's called _call stack_.

More on [Wikipedia](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))

### Stack Operations

The common ADT operations executed on queues are the following:

* _create()_ - Create the queue structure;
* _push()_ - Insert an element on the head of the stack;
* _peek()_ - Look for the head of the stack, without remove the element;
* _pop()_ - Remove the head element of the stack;
* _destroy()_ - Destroy the stack structure. If there are elements in it, they are destroyed also.

### Stack implementation and complexities

function name | complexity | explanation
:-- | :--:  |:--
_sl_stack_create_ | O(1) | 
_sl_stack_push_ | O(1) | 
_sl_stack_peek_ | O(1)| 
_sl_stack_pop_ | O(1) | 
_sl_stack_destroy_ | O(n) | 

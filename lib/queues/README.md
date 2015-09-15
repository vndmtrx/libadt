Queues
======

In computer science, a queue is a abstract data type in which the entities are kept in order and the mainly operations are the addition of entities to the rear position and removal from the front position, known as dequeue. This makes the queue a First-In-First-Out (FIFO) data structure. In a FIFO data structure, the first element added to the queue will be the first one to be removed. 

Queues are common in computer programs, as a way to couple different parts of an application which produce and consume resources in different rates. Queues are, essentially, pipes.

More on [Wikipedia](https://en.wikipedia.org/wiki/Queue_(abstract_data_type))

### Queue Operations

The common ADT operations executed on queues are the following:

* _create()_ - Create the queue structure;
* _push()_ - Insert an element on the queue, in the head;
* _peek()_ - Look for the tail of the queue, without remove the element from the queue;
* _pop()_ - Remove the tail element of the queue;
* _destroy()_ - Destroy the queue structure. If there are elements in it, they are destroyed also.

### Queue implementation and complexities

function name | complexity | explanation
:-- | :--:  |:--
_sl_queue_create_ | O(1) | 
_sl_queue_push_ | O(1) | 
_sl_queue_peek_ | O(1)| 
_sl_queue_pop_ | O(1) | 
_sl_queue_destroy_ | O(n) | removing in the head avoids the O(n^2)

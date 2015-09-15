Deques
======

A deque (Double Ended QUEue) is an abstract data type that generalizes a queue and a stack, for which elements can be added to or removed from either the front (head) or back (tail).

This is similar to a data structure of queue or stack. The difference is that the data can be read, inserted or removed at both ends.

Deques can be used in job scheduling and to implement non-deterministic finite automata. For the first, a special type of job scheduling, called A-Steal, implements a task scheduler for several processors. For Each processor, is maintained a deque with threads to be executed. The next thread to be executed by an specific processor is caught from the head of the deque. When a processor finishes execution of your own threads, it can "steal" a thread from another processor. In this case, the stolen thread is caught from the tail of deque.

More on [Wikipedia](https://en.wikipedia.org/wiki/Double-ended_queue)

### Deque operations

The common ADT operations executed on deques are the following:

* _create()_ - Create the deque structure;
* _push()_ - Insert an element on the deque, at the rear end of the deque;
* _first()_ - Look for the first element of the deque, without remove it;
* _pop()_ - Remove the element in the rear of the queue, returning it;
* _put()_ - Insert an element on the deque, at the front end of the deque;
* _last()_ - Look for the last element of the deque, without remove it;
* _get()_ - Remove the element in the front of the queue, returning it;
* _destroy()_ - Destroy the queue structure. If there are elements in it, they are destroyed also.

### Deque implementation and complexities

function name | complexity | explanation
:-- | :--:  |:--
_dl_deque_create_ | O(1) | 
_dl_deque_push_ | O(1) | 
_dl_deque_first_ | O(1)| 
_dl_deque_pop_ | O(1) | 
_dl_deque_put_ | O(1) | 
_dl_deque_last_ | O(1)| 
_dl_deque_get_ | O(1) | 
_dl_deque_destroy_ | O(n) | 

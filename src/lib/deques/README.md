Deques
======

A deque (Double Ended QUEue) is an abstract data type that generalizes a queue and a stack, for which elements can be added to or removed from either the front (head) or back (tail).

This is similar to a data structure of queue or stack. The difference is that the data can be read, inserted or removed at both ends.

Deques can be used in job scheduling and to implement non-deterministic finite automata. For the first, a special type of job scheduling, called A-Steal, implements a task scheduler for several processors. For Each processor, it is maintained a deque with threads to be executed. The next thread to be executed by an specific processor is caught from the head of the deque. When a processor finishes execution of its own threads, it can "steal" a thread from another processor. In this case, the stolen thread is caught from the tail of the deque. Another common application of the deque is storing a software application's list of undo operations.

More on [Wikipedia](https://en.wikipedia.org/wiki/Double-ended_queue)

### Deque operations

The common ADT operations executed on deques are the following:

* _create()_ - Create the deque structure;
* _push_left()_ - Insert an element on the deque, at the rear end of the deque;
* _peek_left()_ - Look for the first element of the deque, without remove it;
* _pop_left()_ - Remove the element in the rear of the queue, returning it;
* _push_right()_ - Insert an element on the deque, at the front end of the deque;
* _peek_right()_ - Look for the last element of the deque, without remove it;
* _pop_right()_ - Remove the element in the front of the queue, returning it;
* _destroy()_ - Destroy the queue structure. If there are elements in it, they are destroyed also.

### Deque implementation and complexities

function name | complexity | explanation
:-- | :--:  |:--
_dl_deque_create_ | O(1) | 
_dl_deque_push_left_ | O(1) | 
_dl_deque_peek_left_ | O(1)| 
_dl_deque_pop_left_ | O(1) | 
_dl_deque_push_right_ | O(1) | 
_dl_deque_peek_right_ | O(1)| 
_dl_deque_pop_right_ | O(1) | 
_dl_deque_destroy_ | O(n) | 

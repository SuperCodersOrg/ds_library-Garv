### Session 1
* Date: 21-06-2026 (12.30AM-2.00AM)

* Duration: 2 hours

* Goal: Dynamic Array Implementation(Append, Insert, Remove, Constructors)

 * Problem Encountered: I face some issues with the constructor which used the iterable container. I was not sure how to implement it correctly. 

* What I Tried: I tried to use a template constructor that takes a container as an argument and then iterates through the container to append each element to the dynamic array. However, I was not sure how to handle the resizing of the array when appending elements from the container.

* Outcome: later i implemented the append method which handled resizing by making a resize method which had a parameter with newcapacity and it deleted the old data and created a new array with the new capacity and copied the old data to the new array. then i used this resize method in the append method to resize the array when needed and i used the append method in the constructor to append elements from the container and the iterable begin , end constructor too.

### Session 2
* Date: 22-06-2026 (9.30AM-12.30PM)

* Duration: 2.30 hours

* Goal: Dynamic Array Implementation(get,set,clear,size,begin,end,Copy Constructor,Assignment Operator,Destructor)

 * Problem Encountered: in the begin method i was not sure how to return an iterator that points to the first element like if the dynamic array was just initialized it pointed to *data[0] which was a nullptr.

* What I Tried: to solve this issue i made the begin method return a pointer to the first element of the array which is data and if the array is empty it will return nullptr. for the end method i made it return a pointer to one past the last element which is data + size.

* Outcome: almost the implementation of the dynamic array is done and i have tested it with some test cases and it works fine. i will do more testing and then move on to the next part of the project which is the linked list implementation. pushed the code to the repository and updated the design document with the new methods and constructors.



# Producer Comsumer Problem

The producer generates items and puts items onto the table. 
The consumer will pick up items. The table can only hold two items at the same time. When the table is complete, the producer will wait. 
When there are no items, the consumer will wait. We use semaphores to synchronize producer and consumer.  Mutual exclusion should be considered. 
We use threads in the producer program and consumer program. Shared memory is used for the “table”.


To compile the programs: 

$ g++ producer.cpp -pthread -lrt -o producer

$ g++ consumer.cpp -pthread -lrt -o consumer

$ ./producer & ./consumer &


#Example 


<img width="713" alt="Screen Shot 2022-11-01 at 11 58 26 PM" src="https://user-images.githubusercontent.com/90429123/199392329-7d9f1243-072b-4e16-b5b2-8adf897b6879.png">

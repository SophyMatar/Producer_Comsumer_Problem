# Producer Comsumer Problem

The producer generates items and puts items onto the table. 
The consumer will pick up items. The table can only hold two items at the same time. When the table is complete, the producer will wait. 
When there are no items, the consumer will wait. We use semaphores to synchronize producer and consumer.  Mutual exclusion should be considered. 
We use threads in the producer program and consumer program. Shared memory is used for the “table”.


To compile the programs: 

$ gcc producer.cpp -pthread -lrt -o producer

$ gcc consumer.cpp -pthread -lrt -o consumer

$ ./producer & ./consumer &


#Example 



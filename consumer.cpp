

#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <iostream>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    //create variables for shared memory and a table
    int SMemory;
    int* table;
    
    // allocates a shared memory
    SMemory = shm_open("table", O_CREAT | O_RDWR, 0666); // creates shared memory object -> table
    ftruncate(sharedMemory, sizeof(int)); // size of shared memory
    table = static_cast<int*>(mmap(0, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, SMemory, 0)); // maps object to the address
    
    sem_t* full = sem_open("full", O_CREAT, 0666, 0); // creates semaphores
    sem_t* empty = sem_open("empty", O_CREAT, 0666, 3);
    sem_t* mutex = sem_open("mutex", O_CREAT, 0666, 1);

    // iterate through the operation five times
    for (int i = 0; i < 5; ++i) {
        sem_wait(full);
        sleep(1); 
        sem_wait(mutex); // unlock mutex
        if (*table > 0) { // if the table has exisiting items = not empty:
            --(*table);// consume an item in the table
            std::cout << "An item has been consumed from the table." << std::endl << "The table now contains " << *table << " items\n";
        }
        else {
            std::cout << "Table is empty!\n";
        }
        sem_post(mutex); // close the mutex
        sem_post(empty);
    }
    // close the semaphores
    sem_close(full);
    sem_close(empty);
    sem_close(mutex);

    // unlink the semaphores
    sem_unlink("full");
    sem_unlink("empty");
    sem_unlink("mutex");

    // deallocate the shared memory
    munmap(table, sizeof(int));
    close(SMemory);
    shm_unlink("table");
    return 0;
}

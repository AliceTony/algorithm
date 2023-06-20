#include <semaphore.h>
class FooBar {
private:
    int n;
    sem_t *first = new sem_t;
    sem_t *second = new sem_t;
public:
    FooBar(int n) {
        this->n = n;
        sem_init(first , 0 , 0);
        sem_init(second , 0 , 0);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            sem_wait(first);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            sem_post(second);
            sem_init(first , 0 , 0);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            sem_post(first);
            sem_wait(second);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            sem_init(second , 0 , 0);
        }
    }
};
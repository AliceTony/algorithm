#include <semaphore.h>
class Foo {
private:
    sem_t first_wait;
    sem_t second_wait;
public:
    bool wait1 , wait2 , wait3;
    Foo() {
        sem_init(&first_wait, 0 , 0);
        sem_init(&second_wait, 0 , 0);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&first_wait);
    }

    void second(function<void()> printSecond) {
        sem_wait(&first_wait);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&second_wait);
    }

    void third(function<void()> printThird) {
        sem_wait(&second_wait);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
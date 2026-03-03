class Foo {
private:
    int state;
    mutex mtx;
    condition_variable cv;

public:
    Foo() {
        state = 0;
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mtx);

        printFirst();
        state = 1;

        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [this]() {
            return state >= 1;
        });

        printSecond();
        state = 2;

        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [this]() {
            return state >= 2;
        });

        printThird();
    }
};
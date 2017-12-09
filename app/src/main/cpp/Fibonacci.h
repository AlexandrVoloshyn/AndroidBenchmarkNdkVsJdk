//
// Created by Admin on 22.09.2017.
//

#ifndef TESTANDROIDAPP_FIBONACCI_H
#define TESTANDROIDAPP_FIBONACCI_H

class Fibonacci {
public:
    jint getFibonacci(jint num) {
        if (num == 1)
            return 1;
        if (num == 0)
            return 0;
        return getFibonacci(num - 1) + getFibonacci(num - 2);
    }
};


#endif //TESTANDROIDAPP_FIBONACCI_H

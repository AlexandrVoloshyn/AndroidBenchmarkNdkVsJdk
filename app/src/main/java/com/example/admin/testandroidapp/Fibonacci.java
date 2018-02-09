/**
 * Created by Admin on 19.09.2017.
 */
package com.example.admin.testandroidapp;

public class Fibonacci {
    public int getFibonacci(int n) {
        if (n == 1)
            return 1;
        if (n == 0)
            return 0;
        return getFibonacci(n - 1) + getFibonacci(n - 2);
    }
}

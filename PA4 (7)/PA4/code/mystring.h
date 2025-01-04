#ifndef MY_STRING
#define MY_STRING

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

/*
include any libraries here
*/

using namespace std;

class MyString {
    /*
    A basic MyString class has been provided. It is highly encouraged to use this class to make your implementation significantly straightforward.
    If you do decide to use this class, do not change its class name.
    Feel free to edit this class however you deem fit, including the attributes as well as methods. Make all edits within this header file (in-line the methods as done below).
    */

    private:
        string str;
        int property;

    public:
        MyString(string str, int property): str(str), property(property){}
        
        string get_string() const {
            return str;
        }

        void set_string(const string str){
            this->str = str;
        }

        int get_property() const {
            return property;
        }

        void set_property(const int property){
            this->property = property;
        }
};

#endif
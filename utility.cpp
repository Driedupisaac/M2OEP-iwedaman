//
// Created by Isaac Wedaman on 2/19/25.
//
#include <ctype.h>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include <string>

char get_char_from_user() {
    //getting input
    string input;
    cout << "Please enter a character: ";
    getline(cin, input);

    //input validation - checking if the length of the input is 1
    while(input.length() != 1) {
        if(input.length() == 0) {
            cout << "Invalid! Please enter something! [a character]: ";
            getline(cin, input);
        }
        else {
            cout << "Please enter a character of length one: ";
            getline(cin, input);
        }

    }
    return input[0];
}

string get_word_from_user() {
    //getting input
    string input;
    cout << "Please enter a word: ";
    getline(cin, input);

    //boolean for the word's validity being a word
    bool checker = true;

    //checking if there is a whitespace - if false, then the input is NOT a word
    for(char character : input) {
        if(isspace(character)) {
            checker = false;
        }
    }

    //pre-emptive check for checker being a word
    if(checker) {
        return input;
    }

    //input validation
    while(!checker) {
        if (input.length() == 0) {
            cout << "Please enter a word (with letters): ";
        }
        else {
            cout << "Please enter a word: ";
        }

        getline(cin, input);

        //looping through the input to see if there is a whitespace (and thus not a word)
        checker = true;
        for(char character : input) {
            if(isspace(character)) {
                checker = false;
            }
        }
    }
    return input;
}

string get_sentence_from_user() {
    //getting input
    string input;
    getline(cin, input);

    //checking if the length is 0 - sentences can be anything
    while(input.length() == 0) {
        cout << "Invalid - no input! please enter something: ";
        getline(cin, input);

    }
    return input;
}

int get_int_from_user() {
    string input;
    int integer;
    bool checker = false;

    //getting input
    cout << "Please enter an integer: ";
    getline(cin, input);

    //turning input to a stringstream, and reading an integer into it
    stringstream ss(input);
    if (ss >> integer) {
        checker = true;
    }

    //while loop for input validation
    while (!checker) {
        cout << "Invalid! -  Please enter an integer: ";
        getline(cin, input);

        stringstream ss(input);
        if (ss >> integer) {
            checker = true;
        }
    }
    return integer;
}

double get_float_from_user() {
    string input;
    double number;
    bool checker = false;

    //getting input
    cout << "Please enter a double: ";
    getline(cin, input);

    //doing the same method as with getting an integer, but this time reading a double into the
    //stringstream
    stringstream ss(input);
    if (ss >> number) {
        checker = true;
    }

    //input validation
    while (!checker) {
        cout << "Invalid! -  Please enter a double: ";
        getline(cin, input);

        stringstream ss(input);
        if (ss >> number) {
            checker = true;
        }
        else {
            cout << "Invalid! -  Please enter a double: ";
        }
    }
    return number;
}


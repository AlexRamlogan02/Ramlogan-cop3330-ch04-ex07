/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Alexandra Ramlogan
 *  Chapter 4 Exercise 7
 */

//#include "std_lib_facilities.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    //variables
    int low = 0;
    int high = 100;
    int mid; //the guess
    int i;

    /*
    *  to solve this program, i used a binary search to search for an answer within 7 tries. if 
    * the program cant find the answer within 7 tries, it admits defeat
    */
    for (i = 0; i < 7; i++) //only ask 7 questions
    {
        //valid is to check if the number is correct. search is to ask if the number is less than or greater than mid
        string valid; //i declare the string inside the loop so that it deletes & resets after each loop
        string search;
        mid = (low + high) / 2;
        cout << "is " << mid << " the number you're thinking of?\n";
        cin >> valid;
        if (valid == "yes" || valid == "y") // if its correct break the loop
        {
            cout << "the number is " << mid << "!\n";
            break;
        }
        else //else, ask if the number is less than the guess
        {
            cout << "is the number youre thinking of less than " << mid << "?\n";
            cin >> search;
            if (search == "yes" || search == "y") //if it is, high = mid + 1
            {
                high = mid + 1;
            }
            else
            { //if not, low = mid -1
                low = mid - 1;
            }
        }
    }

    if (i == 7) //if i reaches 7 and the loop ends, the program is defeated
    {
        cout << "I couldn't find your number\n";
    }

    return 0;
}

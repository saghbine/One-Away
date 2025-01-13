//
//  main.cpp
//  One Away
//
//  Created by daniel saghbine on 12/17/24.
//  CTCI 1.5 One Away

#include <iostream>
#include <cstdlib>
using namespace std;

bool One_Away(const string &s1, const string &s2);

int main()
{
    string str1, str2;
    
    cout<<"problem\n-------\n\tThere are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.\n\n";
    
    cout<<"input\n-----\n\tType: ";
    cin>>str1;
    cout<<"\tType again: ";
    cin>>str2;
    
    cout<<"\noutput\n------\n\tThe strings are"<<(One_Away(str1, str2) ? "" : "n't")<<" none or one edit away.\n\n";
    
    cout<<"solution\n--------\n\tAuxiliary space complexity: O(1); time complexity: O(n).\n\n";
    
    return 0;
}

bool One_Away(const string &s1, const string &s2) // s1 and s2 are both input strings
{
    if(abs(int(s1.size())-int(s2.size())) > 1) // if s1 and s2 are more than one character off from each other
        return false; // they aren't none or one edit away
    
    int counter=0; // mistake counter mechanism
    
    for(int i1=0, i2=0; i1 < s1.size() && i2 < s2.size(); i1++, i2++) // check char at indices 0...size-1 in s1 and s2
    {
        if(s1[i1] != s2[i2]) // if select char in s1 isn't equivalent to select char in s2
        {
            counter++; // count mistake
            
            if(counter == 1 && s1.size() != s2.size()) // if there is one mistake and s1 and s1 don't have equivalent sizes
            {
                if(s1.size() > s2.size()) // if s1 is bigger than s2
                    i1++; // move i1 to next index in s1
                else // if s2 is bigger than s1
                    i2++; // move i2 to next index in s2
                
                if(s1[i1] != s2[i2]) // if select char in s1 isn't equivalent to select char in s2
                    counter++; // count mistake
            }
            
            if(counter > 1) // if there is more than one mistake
                return false; // they aren't none or one edit away
        }
    }
    
    return true; // they are none or one edit away
}

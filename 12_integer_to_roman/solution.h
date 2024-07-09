#pragma once

#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        /*
            Symbol	Value
            I	1
            V	5
            X	10
            L	50
            C	100
            D	500
            M	1000
        */
        string result;
        
        result += quotientToRoman(num / 1000, 'M', 'Z', 'Z');
        num = num % 1000;
        
        result += quotientToRoman(num / 100, 'C', 'D', 'M');
        num = num % 100;
        
        result += quotientToRoman(num / 10, 'X', 'L', 'C');
        num = num % 10;
        
        result += quotientToRoman(num, 'I', 'V', 'X');
        
        return result;
    }
    
private:
    string quotientToRoman(int digit, char one, char five, char ten)
    {
        switch (digit)
        {
        case 9:
            return string(1, one) + string(1, ten);
        case 8:
        case 7:
        case 6:
        case 5:
            return string(1, five) + string(digit - 5, one);
        case 4:
            return string(1, one) + string(1, five);
        default:
            return string(digit, one);
        }
    }
};

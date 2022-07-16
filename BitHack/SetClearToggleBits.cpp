#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    int number = 235; //11101011
    int bitPosition = 2;

    //print number in binary
    cout << "Input Number decimal = " << number << ", binary = " << std::bitset<8>(number) << endl; //Assuming input value will fit in 8 bit

    //Checkig a bit in specific position
    int bit = (number >> bitPosition) & 1U;
    cout << "Bit at poistion[" << bitPosition << "] for " << number << "[" << std::bitset<8>(number) << "] = " << bit << endl;

    //Set 2nd bit: 235 (11101011)  --> 239 (11101111)
    //Set is done using bitwise OR operator
    int setValue = number | (1 << bitPosition);
    cout << "Set bit at position[" << bitPosition << "]: before= " << number << "[" << std::bitset<8>(number) << "] after= " << setValue << "[" << std::bitset<8>(setValue) << "] " << endl;

    //Clear is done using bitwise AND operator
    //Invert the bit string with the bitwise NOT operator (~), then AND (&) it.
    //Clear 0 bit: (235) 11101011 --> (234) 11101010 
    bitPosition = 0;
    int clearValue = number & ~(1 << bitPosition);
    cout << "Clear bit at position[" << bitPosition << "]: before= " << number << "[" << std::bitset<8>(number) << "] after= " << clearValue << "[" << std::bitset<8>(clearValue) << "] " << endl;

    //Toggle is done usinf biwise XOR operator
    //Toggle 3rd bit --> (235) 11101011  --> (227) 11100011  
    bitPosition = 3;
    int toggleValue = number ^ (1 << bitPosition);
    cout << "Toggle bit at position[" << bitPosition << "]: before= " << number << "[" << std::bitset<8>(number) << "] after= " << toggleValue << "[" << std::bitset<8>(toggleValue) << "] " << endl;

    //Changing the nth bit to x(either 0 or 1)
    //Its not a toggle, we need to change the bit irrrespective of its current value
    //Logic - first clear the bit at that position and then perfomr logic OR with X(0 or 1)
    //i.e change the 6th bit to 0
    int bitToChange = 0; //change 1 to 0 for 6th bit 11101011 --> 10101011
    bitPosition = 6;
    int newNumber = (number & ~(1UL << bitPosition)) | (bitToChange << bitPosition);
    cout << "Changing bit at position[" << bitPosition << "] to "<< bitToChange  << " : before= " << number << "[" << std::bitset<8>(number) << "] after= " << newNumber << "[" << std::bitset<8>(newNumber) << "] " << endl;

    return 0;
}

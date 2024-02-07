//Jake Kistler
//University of Oklahoma
//CS 2413
//Data file maker using the Mersenne Twister

#include <iostream>
#include <fstream>
#include <random>
#include <ctime>

using namespace std;
const int NUMBERS_TO_GEN = 20000;

int main(int argc, char **argv)
{
    ofstream outputFile("randomNumbers.txt");
    if (!outputFile.is_open())
    {
        cout << "Error, unable to open file." << endl;
        return 1;
    }

    mt19937 mt(static_cast<unsigned int>(time(nullptr)));
    uniform_int_distribution<int> distribution(10000000, 99999999);

    for (int i = 0; i < NUMBERS_TO_GEN; i++)
    {
        int randomNumber = distribution(mt);
        outputFile << randomNumber << endl;
    }

    outputFile.close();

    cout << "Generated " << NUMBERS_TO_GEN <<  " random numbers and saved them to 'randomNumbers.txt'." << endl;

    return 0;
}

/*
So what is this? Well to get past the limits of Random() I went looking for random number generators that have cpp libraries for them
started here: https://cplusplus.com/reference/random/
This set me off with one of the three generators listed, I picked the Mersenne Twister ONLY due to the fact that I have heard of it before
Which brings me to line 18, here I have created a instance of the Mersenne twister engine, I'd like to say this is an object but I imagine it's different in some complex way
seed said engine with time like random() and cast that result into an unsigined int

The distrobution in the following line bounds the numbers produced by the Mersenne Twister
*/
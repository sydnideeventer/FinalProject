//Sydni-Dee Venter
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

const string FILENAME = "short.txt";

//function counts how many numbers are in the file
int countNums()
{
    int count = 0;
    int cNum;
    
    ifstream file;
    file.open(FILENAME);
    
    while(!file.eof())
    {
        file >> cNum;
        count++;
    }
    
    file.close();

    return count;
}

//function checks if number is even
bool isEven(int num)
{
    return num % 2 == 0;
}

//function checks if number is odd
bool isOdd(int num)
{
    return !isEven(num);
}

//function checks if number is prime
bool isPrime(int num)
{
    if(num <= 1)
    {
        return false;
    }
    else
    {
        for(int i = 2; i <= num; ++i)
        {
            if(i == num)
            {
                return true;
            }
            else if(num % i == 0)
            {
                return false;
            }
        }
    }
   
    return false;
}

//function outputs the minimum number in the file
int calcMin()
{
    ifstream inFile;
    inFile.open(FILENAME);
    
    int min;
    int cNum;
    
    inFile >> min;
    
    while(!inFile.eof())
    {
        inFile >> cNum;
        
        if(cNum < min)
        {
            min = cNum;
        }
    }
    
    inFile.close();
    return min;
}

//function outputs the maximum number in the file
int calcMax()
{
    ifstream inFile;
    inFile.open(FILENAME);
    
    int max;
    int cNum;
    
    inFile >> max;
    
    while(!inFile.eof())
    {
        inFile >> cNum;
        
        if(cNum > max)
        {
            max = cNum;
        }
    }
    
    inFile.close();
    return max;
}

//function calculates and outputs the sum of all the numbers in the file
int calcSum()
{
    ifstream inFile;
    inFile.open(FILENAME);
    
    int sum = 0;
    int cNum;
    
    while(!inFile.eof())
    {
        inFile >> cNum;
        sum += cNum;
    }
    
    inFile.close();
    return sum;
}

//function calculates and outputs the average of the numbers in the file
double calcMean()
{
    return (double) calcSum() / countNums();
}

//function calculates and outputs the standard deviation
double calcStanDev()
{
    ifstream inFile;
    inFile.open(FILENAME);
    int cNum;
    double sum = 0.0;
    double sd = 0.0;
    double mean = calcMean();
    int vals = countNums();
    
    while(!inFile.eof())
    {
        inFile >> cNum;
        sum += pow(cNum - mean, 2);
    }
    
    sd = sum / vals;
    sd = sqrt(sd);
    
    inFile.close();
    return sd;
}

//function calculates and outputs the number of even numbers
int countEven()
{
    int count = 0;
    int cNum;
    
    ifstream inFile;
    ofstream outFile;
    inFile.open(FILENAME);
    outFile.open("evens.txt");
    
    while(!inFile.eof())
    {
        inFile >> cNum;
        if(isEven(cNum))
        {
            count++;
            outFile << cNum << endl;
        }
    }
    
    inFile.close();
    outFile.close();
    
    return count;
}

//function counts and outputs the number of odd numbers
int countOdd()
{
    int count = 0;
    int cNum;
    
    ifstream inFile;
    ofstream outFile;
    inFile.open(FILENAME);
    outFile.open("odds.txt");
    
    while(!inFile.eof())
    {
        inFile >> cNum;
        if(isOdd(cNum))
        {
            count++;
            outFile << cNum << endl;
        }
    }
    
    inFile.close();
    outFile.close();
    
    return count;
}

//function counts and outputs the number of prime numbers
int countPrime()
{
    int count = 0;
    int cNum;
    
    ifstream inFile;
    ofstream outFile;
    inFile.open(FILENAME);
    outFile.open("primes.txt");
    
    while(!inFile.eof())
    {
        inFile >> cNum;
        if(isPrime(cNum))
        {
            count++;
            outFile << cNum << endl;
        }
    }
    
    inFile.close();
    outFile.close();
    
    return count;
}

//main
int main()
{ 
    cout << "Numbers read in: " << countNums() << endl;
    cout << "Even numbers: " << countEven() << endl;
    cout << "Odd numbers: " << countOdd() << endl;
    cout << "Prime numbers: " << countPrime() << endl;
    cout << "Min number: " << calcMin() << endl;
    cout << "Max number: " << calcMax() << endl;
    cout << "Sum: " << calcSum() << endl;
    cout << "Mean: " << calcMean() << endl;
    cout << "Standard Deviation: " << calcStanDev() << endl;
    return 0;
}

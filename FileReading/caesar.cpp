//Sydni-Dee Venter
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

const int CAPA = 65;
const int CAPZ = 90;
const int LOWA = 97;
const int LOWZ = 122; 

const string MSGFILE = "message.txt";
const string CODEDFILE = "coded.txt";
const string DECODEDFILE = "decoded.txt";


//Funtion displays menu
void display_menu()
{
    cout << "What do you want to do?" << endl;
    cout << "\t(0) Encode" << endl;
    cout << "\t(1) Decode" << endl;
    cout << "Action: ";
}

//Function calculates and returns the key
int calc_key()
{
    string k;
    cout << "Enter key: ";
    cin >> k;
    
    int amount = 0;
    
    for(int i = 0; i < k.length(); i++)
    {
        amount += (char) k[i];
    }
    
    amount = (amount % 23) + 3;
    
    return amount;
}

//Function encodes a message from file and writes encoded message to another file
void encode(int key)
{
    
    ifstream inFile;
    inFile.open(MSGFILE);
    
    ofstream outFile;
    outFile.open(CODEDFILE);

    string s;
    getline(inFile, s);
    
    int forward = key;
    int backward = 26 - key;
    
    char lowLimit = LOWA + backward - 1;
    char upLimit = CAPA + backward - 1;
    
    
    for(int i = 0; i < s.length(); i++)
    {
        char cur = (char) s[i];
        
        if(isalpha(cur))
        {
            if(cur >= 'a' && cur <= lowLimit)
            {
                cur += forward;
            }
            else if(cur >= lowLimit + 1 && cur <= 'z')
            {
                cur -= backward;
            }
            else if(cur >= 'A' && cur <= upLimit)
            {
                cur += forward;
            }
            else if(cur >= upLimit + 1 && cur <= 'Z')
            {
                cur -= backward;
            }
            
            outFile << cur;
        }
        else
        {
            outFile << cur;
        }
    }
    
    outFile.close();
    
    string code; 
    ifstream enFile(CODEDFILE);
    getline(enFile, code);
    
    cout << "Your encoded message is: " << code << endl;
    
    enFile.close();
    inFile.close();
}

//Function reads an encoded message from a file then decodes it and writes the message to a file
void decode(int key)
{
    ifstream inFile;
    inFile.open(CODEDFILE);
    
    ofstream outFile;
    outFile.open(DECODEDFILE);

    string s;
    getline(inFile, s);
    
    int forward = 26 - key;
    int backward = key;
    
    char lowLimit = LOWA + backward - 1;
    char upLimit = CAPA + backward - 1;
    
    
    for(int i = 0; i < s.length(); i++)
    {
        char cur = (char) s[i];
        
        if(isalpha(cur))
        {
            if(cur >= 'a' && cur <= lowLimit)
            {
                cur += forward;
            }
            else if(cur >= lowLimit + 1 && cur <= 'z')
            {
                cur -= backward;
            }
            else if(cur >= 'A' && cur <= upLimit)
            {
                cur += forward;
            }
            else if(cur >= upLimit + 1 && cur <= 'Z')
            {
                cur -= backward;
            }
            
            outFile << cur;
        }
        else
        {
            outFile << cur;
        }
    }
    outFile.close();
    
    ifstream deFile(DECODEDFILE);
    string decode;
    getline(deFile, decode);
    
    cout << "Your decoded message is: " << decode << endl;
    
    deFile.close();
    inFile.close();
}

//Main
int main() 
{
    int choice;
    
    display_menu();
    cin >> choice;
    cout << endl;
    
    ifstream mesFile(MSGFILE);
    string message;
    getline(mesFile, message);
    
    cout << "Your message is: " << message << endl;
    
    mesFile.close();
    
    int key = calc_key();
    
    switch (choice)
    {
        case 0:
            encode(key);
            break;
            
        case 1:
            decode(key);
            break;
            
        default:
            break;
    }
    
    return 0;
}


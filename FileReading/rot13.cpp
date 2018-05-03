//Sydni-Dee Venter
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

const string MSGFILE = "message.txt";
const string CODEDFILE = "coded.txt";
const string DECODEDFILE = "decoded.txt";

//Function displays menu
void display_menu()
{
    cout << "What do you want to do?" << endl;
    cout << "\t(0) Encode" << endl;
    cout << "\t(1) Decode" << endl;
    cout << "Action: ";
}

//Function reads and encodes a file then outputs another file that is encoded
void encode()
{
    
    ifstream inFile;
    inFile.open(MSGFILE);
    
    ofstream outFile;
    outFile.open(CODEDFILE);

    string s;
    getline(inFile, s);
    
    for(int i = 0; i < s.length(); i++)
    {
        char cur = (char) s[i];
        
        if(isalpha(cur))
        {
            if(cur >= 'a' && cur <= 'm')
            {
                cur += 13;
            }
            else if(cur >= 'n' && cur <= 'z')
            {
                cur -= 13;
            }
            else if(cur >= 'A' && cur <= 'M')
            {
                cur += 13;
            }
            else if(cur >= 'N' && cur <= 'Z')
            {
                cur -= 13;
            }
            
            outFile << cur;
        }
        else
        {
            outFile << cur;
        }
    }
    
    inFile.close();
    outFile.close();
    
    string code; 
    ifstream enFile(CODEDFILE);
    getline(enFile, code);
    
    cout << "Your encoded message is: " << code << endl;
    
    enFile.close();
}


//Function takes in a coded message from a file and then decodes it and send the decoded message to a file
void decode()
{
    ifstream inFile;
    inFile.open(CODEDFILE);
    ofstream outFile;
    outFile.open(DECODEDFILE);
    
    string msg;
    getline(inFile, msg);
    
    for(int i = 0; i < msg.length(); i++)
    {
        char cur = (char) msg[i];
        
        if(isalpha(cur))
        {
            if(cur >= 'a' && cur <= 'm')
            {
                cur += 13;
            }
            else if(cur >= 'n' && cur <= 'z')
            {
                cur -= 13;
            }
            else if(cur >= 'A' && cur <= 'M')
            {
                cur += 13;
            }
            else if(cur >= 'N' && cur <= 'Z')
            {
                cur -= 13;
            }
            
            outFile << cur;
        }
        else
        {
            outFile << cur;
        }
    }
    
    inFile.close();
    outFile.close();
    
    ifstream deFile(DECODEDFILE);
    string decode;
    getline(deFile, decode);
    
    cout << "Your decoded message is: " << decode << endl;
    
    deFile.close();
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
    
    switch (choice)
    {
        case 0:
            encode();
            break;
            
        case 1:
            decode();
            break;
            
        default:
            break;
    }
    
    return 0;
}


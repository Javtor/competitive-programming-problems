#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string word;
    string max_word = "";
    int max_size = 0;
    getline(cin, word);
    while ( word != "asdasd" )
    {
        if ( max_size < word.size() ) 
        { 
            max_size = word.size();
            max_word = word;
        }           
        else if ( max_size == word.size() ) 
        { 
            max_word += "; ";
            max_word += word;
        }  
        getline(cin, word);          
    }

    cout << max_size << " , " << max_word << endl;    
}    
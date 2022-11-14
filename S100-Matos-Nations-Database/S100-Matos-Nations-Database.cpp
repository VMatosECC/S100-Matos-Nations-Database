// S100-Matos-Nations-Database.cpp 
// Author:  V. Matos
// Goal:    Provide an interface to retrieve from a parallel array 
//          database the capital, currency, and language(s) of a 
//          given country.
// ----------------------------------------------------------------------

//Preprocessor declarations
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// Prototypes -------------------------------------------------------------
void queryDatabase(vector<string>& vcountry, vector<string>& vcapital,
                   vector<string>& vcurrency, vector<string>& vlanguage);

void makeDatabase(vector<string>& vcountry, vector<string>& vcapital,
                  vector<string>& vcurrency, vector<string>& vlanguage);


int main()
{
    vector<string> vcountry;
    vector<string> vcapital;
    vector<string> vcurrency;
    vector<string> vlanguage;

    makeDatabase(vcountry, vcapital, vcurrency, vlanguage);
    queryDatabase(vcountry, vcapital, vcurrency, vlanguage);
}

// User-defined functions ---------------------------------------------------
void makeDatabase(vector<string>& vcountry, vector<string>& vcapital, 
                  vector<string>& vcurrency, vector<string>& vlanguage)
{
    string fileName = "c:/temp/xcountry.txt";
    ifstream infile(fileName);
    if (!infile)
    {
        cout << "Error - file not found: " << fileName << endl;
        exit(1);
    }
    string strValue;
    while ( getline(infile, strValue) )
    {
        vcountry.push_back(strValue);
    }
    infile.close();


}

void queryDatabase(vector<string>& vcountry, vector<string>& vcapital,
                   vector<string>& vcurrency, vector<string>& vlanguage)
{

}
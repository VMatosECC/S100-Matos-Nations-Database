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

void populateVector(string fileName, vector<string>& v);
int  sequentialSearch(string key, vector<string> v);
int  binarySearch(string key, vector<string> v);

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
    populateVector("c:/temp/xcountry.txt", vcountry);
    populateVector("c:/temp/xcapital.txt", vcapital);
    populateVector("c:/temp/xlanguage.txt", vlanguage);
    populateVector("c:/temp/xcurrency.txt", vcurrency);

}

void populateVector(string fileName, vector<string>& v)
{
    ifstream infile(fileName);
    if (!infile)
    {
        cout << "Error - file not found: " << fileName << endl;
        exit(1);
    }
    string strValue;
    while (getline(infile, strValue, '\n'))
    {
        v.push_back(strValue);
    }
    infile.close();
}


void queryDatabase(vector<string>& vcountry, vector<string>& vcapital,
                   vector<string>& vcurrency, vector<string>& vlanguage)
{
    string strCountry;
    do
    {
        cout << "Enter country [xxx to end]: ";
        getline(cin, strCountry);
        if (strCountry == "xxx") break;

        //int pos = sequentialSearch(strCountry, vcountry);
        int pos = binarySearch(strCountry, vcountry);

        if (pos >= 0)
        {
            cout << "Capital city:        " << vcapital[pos] << endl;
            cout << "Language(s):         " << vlanguage[pos] << endl;
            cout << "Currency:            " << vcurrency[pos] << endl;
        }
        else
        {
            cout << "Country not found in the database" << endl;
        }
        cout << endl;

    } while (true);
}

int sequentialSearch(string key, vector<string> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == key) return i;
    }
    return -1;          //data not found
}

int  binarySearch(string key, vector<string> v)
{
    int first = 0;
    int last = v.size() - 1;
    while (first <= last)
    {
        int mid = (first + last) / 2;
        if (v[mid] == key) return mid;  //match found!

        if (v[mid] < key)
            first = mid + 1;        //explore right side
        else
            last = mid - 1;         //explore left side
    }
    return -1;
}

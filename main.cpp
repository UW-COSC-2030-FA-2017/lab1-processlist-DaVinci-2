/*
 * Jeremy Reynolds
 * Lab1
 * Due Sept 18 2017
 * CoSc 2030
 *
 */


#include <iostream>
#include <string>
#include <fstream>


using namespace std;


int main() {


    ifstream inData;
    string fileName;

    cout << "Enter the data file Name : " << endl;//asks user to input filename
    //inputs user input into fileName
    getline(cin,fileName);
    inData.open(fileName.c_str()); //heres where i try to open the file with the users input?

    string a[4] = {""};
    string temp = "";
    int cnt = 0; // Start count
    if(inData.is_open())
    {
       
        inData.seekg(0,ios_base::beg); // Start at beginning of file

        bool loop = true;
        char ints;

        while(inData.get(ints))
        {
            if((ints==' ' || ints=='\n' ||ints=='\b'||ints=='\r'||ints=='\t')&& temp!="") // checks
            {
                ++cnt;
                if(a[0]=="")
                {
                    a[0] = temp;
                }
                else if(a[1]=="")
                {
                    a[1] = temp;
                }
                else if(a[2]=="")
                {
                    a[2] = temp;
                }
                else if(a[3]=="")
                {
                    a[3] = temp;
                }
                else
                {
                    a[2] = a[3];
                    a[3] = temp;
                }
                temp = "";
            }
            else if((ints>='0' && ints<= '9') || ints=='.')// continue checking
                temp+=ints;
        }
    }
    if(temp!="")
    {
        ++cnt;
        if(a[0]=="")
        {
            a[0] = temp;
        }
        else if(a[1]=="")
        {
            a[1] = temp;
        }
        else if(a[2]=="")
        {
            a[2] = temp;
        }
        else if(a[3]=="")
        {
            a[3] = temp;
        }
        else
        {
            a[2] = a[3];
            a[3] = temp;
        }
    }
    cout <<"Total Numbers : "<<cnt<<endl; // Display total # of numbers
    
    cout << "First two #'s in file: "  << a[0] << " " <<  a[1] << endl;
    cout << "Last two #'s in file: "  << a[2] << " " <<  a[3] << endl;
    
    inData.close(); // Closes file and returns 0
    
    return 0;
}





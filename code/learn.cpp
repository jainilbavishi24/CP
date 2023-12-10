#include<bits/stdc++.h>
#include<algorithm>
#include<fstream>
using namespace std;
typedef long long lli;
#define jainil lli;
    // code by JAINIL
struct Address 
{
    string street;
    string city;
    string state;
    int zip;
};

struct Person 
 {
    string name;
    int age;
    Address address; // This is a struct within a struct
};
/*struct learn
{

}*/ //if we dont use semicolon it will give error
int main()
{
    int shelf = 5;
    int anotherShelf = 10;
   //jainil j=890580985;
    int* const shelfPointer = &shelf;   // Top-level const pointer: Can't change where it points

    const int* bookPointer = &shelf; 
    cout<<bookPointer<<endl;    // Low-level const pointer: Can't change the value through pointer
    bookPointer = &anotherShelf;         // But you can change where the pointer points

    const int* const constBookPointer = &shelf; // Both low-level and top-level const
    // constBookPointer = &anotherShelf;       // Can't change where it points
    // *constBookPointer = 15;                // Can't change the value through pointer
    cout<<shelfPointer<<endl;
    cout<<bookPointer<<endl;
    cout<<constBookPointer<<endl;
        int x;
        decltype(x) y;
        y=7;
    cout<<y<<endl;
    Person person1 = {"John Doe", 30, {"123 Main St", "Anytown", "CA", 12345}};

    cout << "Name: " << person1.name << ", Age: " << person1.age << endl;
    cout << "Address: " << person1.address.street << ", " << person1.address.city << ", "
         << person1.address.state << " " << person1.address.zip << endl;
    string trial;
    getline(cin, trial);
    cout<<trial<<endl;
    ifstream inputFile("C:\\Users\\bavis\\OneDrive\\Desktop\\CP\\code\\input.txt");  // Create an input file stream
    ofstream outputFile("C:\\Users\\bavis\\OneDrive\\Documents\\output.txt");  // Create an output file stream

    if (inputFile && outputFile) {  // Check if both files were opened successfully
        string line;
        while (getline(inputFile, line)) 
        {
            outputFile << line << endl;  // Write each line to the output file
        }
        

        cout << "Contents copied from input.txt to output.txt." << endl;
    } else {
        cout << "Error opening files!" << endl;
    }
    int a[5]={5,16,7,8,9};
    int *ptr=a;
    for(int i=0;i<5;i++)
    {
        cout<<i<<*(a+i)<<*(ptr+i)<<a[i]<<endl;
    }


    return 0;

}
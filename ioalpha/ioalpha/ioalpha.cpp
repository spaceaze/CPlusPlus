#include <iostream>
#include <stdlib.h>
#include <fstream>

class Student
{
private:
    int number;
    char name[50];
    float gpa;
public:
    Student(int n, const char* s, float g);
    void save(ofstream& of);
    void load(ifstream& inf);
};

main()
{
    Student me(11321, "Myself", 4.3);
    ofstream myfile;
    myfile.open("silly.dat", ios::binary | ios::out);
    me.save(myfile);
    myfile.close();
    return(0);
}

void Student::save(ofstream& of)
{
    of.write(&number, sizeof(number));
    of.write(name, sizeof(name));
    of.write(&gpa, sizeof(gpa));
}

void Student::load(ifstream& inf)
{
    inf.read(&number, sizeof(number));
    inf.read(name, sizeof(name));
    inf.read(&gpa, sizeof(gpa));
}
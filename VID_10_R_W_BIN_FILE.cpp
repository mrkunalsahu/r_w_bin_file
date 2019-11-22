#include<iostream>
#include<fstream>
using namespace std;
#pragma pack(push,1)// This make compiler allocate the structure memory just according to the size of member variables. Without this the structure will have more memory than the size of the variables. 

struct a 
{

char name[50];
int age;

double height;	
};

#pragma pack(pop)

int main()
{
 a ob={"Sachin",20,170};
	string fileName="test.bin";
	////// This is the writing section\\\\\\\\
	
	ofstream outputFile;
	outputFile.open(fileName,ios::binary);
	if(outputFile.is_open())
	{

outputFile.write(reinterpret_cast<char *>(&ob),sizeof(a));//same as outputFile.write((char*)&obj,sizeof(obj));
outputFile.close();

	}
	else
		cout<<"\nCould not create the file " + fileName;
	
///////This is the reading section\\\\

a b = {};

	ifstream inputFile; 
	inputFile.open(fileName,ios::binary);
	if(inputFile.is_open())
	{

inputFile.read(reinterpret_cast<char *>(&b),sizeof(a));//same as outputFile.write((char*)&obj,sizeof(obj));
inputFile.close();

	}
	else
		cout<<"\nCould not open the file " + fileName;

cout<<"\n";
cout<<b.name<<","<<b.age<<","<<b.height;
cout<<endl<<sizeof(b);

	return 0;


}
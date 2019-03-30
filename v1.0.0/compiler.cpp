#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
ofstream fout;
ifstream code;
void pre_compile()
{
}
void define_var(stringstream &ss)
{
}
void compile()
{
	string command;
	while(getline(code,command))
	{
		stringstream ss(command);
		string tmp;
		ss>>tmp;
		if(tmp=="var") define_var(ss);
	}
}
int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		fprintf(stderr,"error: input file too much or too little!\n");
		fprintf(stdout,"failed to compile!\n");
		exit(1);
	}
	string code_name(argv[1]);
	cout<<"preparing to compile "<<code_name<<" ..."<<endl;
	code.open(code_name);
	size_t pos_of_dot=code_name.find('.');
	if(pos_of_dot!=string::npos) code_name=code_name.substr(0,pos_of_dot-1);
	fout.open(code_name+".skc");
	cout<<"pre-compiling..."<<endl;
	pre_compile();
	cout<<"successfully pre-compiled!"<<endl;
	cout<<"compiling ..."<<endl;
	compile();
	cout<<"successfully compiled!"<<endl;
	return 0;
}

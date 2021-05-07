#include <iostream>
#include<exception>
using namespace std;

class myexception: public exception{
  virtual const char* what() const throw(){
    return "STUPID!!! Not integer!!";
  }
}myex;

int main(){
	int x,y,a; 
	double d;
do{  
  a=0;

try{
  cout<<"Input 2 numbers:";
 	cin >> x >> y;
	if(cin.fail()) throw myex;
	if (y==0) throw "Error divided by zero";  

	d=(double) x/y;
	cout<< "The result is "<<d<<endl;	
}
catch(exception& e){
  cout << e.what() << endl;
  a=1;
  cin.clear();// fflush(stdin)
  cin.ignore(100,'\n');
}
catch(const char *error){
  cerr<<error;
  cout<<endl;
  a=1;
}
}while(a);
	return 0;
}
	

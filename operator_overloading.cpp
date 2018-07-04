#include<iostream>
using namespace std;

class marks{
int intmarks,extmarks;
public:
    marks(){
    intmarks=extmarks=0;
    }
    marks(int im,int em){
    intmarks=im;
    extmarks=em;
    }
    void display(){
    cout<<intmarks<<"\n"<<extmarks<<"\n";
    }
    //Note only one parameter is passed if it is a member function of the class (for ex in this we need to
    // pass only one argument because m1 is passed by default )
    marks operator+(marks m){
    marks temp;
    temp.intmarks=intmarks+m.intmarks;
    temp.extmarks=extmarks+m.extmarks;
    return temp;
    }

};



int main(){

marks m1(10,20),m2(30,40),m3;
m3=m1+m2;
m3.display();
return 0;
}

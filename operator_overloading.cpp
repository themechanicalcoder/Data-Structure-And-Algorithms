#include<iostream>
using namespace std;

class marks{
int intmarks,extmarks;
int a[7]={1,2,3,4,5,6,7};
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
    cout<<"overloading the + operator \n";
    marks temp;
    temp.intmarks=intmarks+m.intmarks;
    temp.extmarks=extmarks+m.extmarks;
    return temp;
    }
    void operator--(){
    cout<<"overloading the prefix -- operator on extramarks  \n";
    extmarks-=1;

    }
    //note int is written in the bracket which tells that it poatfix
    marks operator++(int){
    cout<<"overloading the postfix operation extramarks \n";
    marks temp;
    temp.extmarks=extmarks;
    extmarks+=1;
    return temp;
    }
    int operator[](int val){
    return a[val];
    }
    marks operator-(marks m);
    friend void operator-=(marks &cur_obj,int redmarks);


};
//return type class name :: function name
marks  marks::operator-(marks m){
    cout<<"overloading the - operator \n";
    marks temp;
    temp.intmarks=intmarks-m.intmarks;
    temp.extmarks=extmarks-m.extmarks;
    return temp;
}
//since it is friend function we need to pass two parameters other wise only void operator-=(int redmarks)if it was member function
void operator-=(marks &cur_obj,int redmarks){
    cout<<"overloading the - operator \n";
    cur_obj.intmarks-=redmarks;
}


int main(){

marks m1(10,20),m2(30,40),m4,m3,m5(10,11),m6;
m3=m1+m2;
m3.display();
m4=m2-m1;
m4.display();
m4-=10;
m4.display();
m3-=10;
m3.display();
--m3;
m3.display();
m5++.display();
m5.display();
cout<<"overloading the [] operator \n";
cout<<m2[4]<<"\n";
return 0;
}

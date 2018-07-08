#include<bits/stdc++.h>
using namespace std;
        //instead of class "typename" can also be used
        //in this case both the parameters  should be same as only one class is written inside the templste
template<class T>
T display(T x,T y){
    return (x>y)?x:y;
}

template<class T1=string,class T2=int>
class myclass{
    T1 p1;
    T2 p2;
public:
    myclass(T1 x,T2 y){
    p1=x;
    p2=y;
    }
    void print(){
    cout<<"p1= "<<p1<<" p2= "<<p2<<"\n";
    }


};
//explicit specialisation of generic function
//similar to function overloading
template<class T1>
class myclass<T1,float>{
    T1  p1;
    float p2;
public:
    myclass(T1 x,float y){
    p1=x;
    p2=y;
    }
    void print(){
    cout<<"called explicitly from the float version \n";
    cout<<"p1= "<<p1<<" p2= "<<p2<<"\n";
    }



};

int main(){
cout<<display(1,2)<<"\n";
cout<<display(1.1,3.4)<<"\n";
cout<<display("ab","cd")<<"\n";
myclass<>obj("this is me ",19);
myclass<int,float>obj1(19,22.03);
myclass<int,string>obj3(19,"this is me ");
obj.print();
obj1.print();
obj3.print();

return 0;
}

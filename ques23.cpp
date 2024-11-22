#include<iostream>
using namespace std;
//let suppose the value is 180 ->then 
class A{
    int a;

    public:
    static int func(int num){
        return num*2;
    }
};
class B{
    public:
      static int func(int num){
        return num *3;
    }
};
class C{
    public:
     static int func(int num){
        return num *5;

    }
};
class D{
    int val;

    public:
    D(){
        val = 1;

    }
    void update_val(int target){
        int n = target;
        int count2 = 0;
        int count3 = 0;
        int count5 = 0;
    
        while(val != target){
            while(n%2 == 0){
                 n= n/2;
                val =  A::func(val);
                count2++;

            }
            while(n%3 == 0){
                n = n/3;
                val = B::func(val);
                count3++;
            }
            while(n%5 == 0){
                n = n/5;
                val = C::func(val);
                count5++;
            }
        }
    cout<<"number divisible by 2:"<<count2<<"times"<<endl;
    cout<<"number divisible by 3 is:"<<count3<<"times"<<endl;
    cout<<"number divisible by 5 is: "<<count5<<"times"<<endl;

    

    }

};
int main(){

D obj1;
int target;
cin>>target;
while(target != -1)
{    
    obj1.update_val(target);
    cin>>target;


}






    return 0;
}

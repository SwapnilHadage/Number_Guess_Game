#include<iostream>
#include<conio.h>
#include<random> //for generating random number
#include<exception>
#include<limits>

using namespace std;

int selectRange(mt19937 &gen){
    int num;
    cout<<"***Choose Difficulty Level***\n";
    cout<<"\t1: Easy (0-10)\n\t2: Medium (0-50)\n\t3:Hard (0-100)\n";
    

    while(true){
        cin >> num;
    if(cin.fail() or (num>3 or num<-2)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Invalid Input.. Please Enter An Integer..\n";
        }else{
        break;
        }
    }
    
    if(num==-1) return -1;

    if(num==1){
        num=10;
    }else{
        if(num==2){
            num=50;
            }else{
                num=100;}
    }
    uniform_int_distribution<> dist(0,num);
    return dist(gen); 
}


int main(){
    random_device rd;
    mt19937 gen(rd());
    int input, maxRange_num, attempt=0;;

    cout<<"***Welcome!!!***\n"<<endl;
    maxRange_num=selectRange(gen);
    cout<<"Enter -2 to Change Difficulty Mode or Enter -1 to Exit\n5";
    if(maxRange_num==-1){
        cout<<"Bye..BYe..\n";
        return 0;
    }


while(true){
    cout<<"Enter Your Guess.. \n";
    while(true){
        cin>>input;
        if(cin.fail() or input<-2){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Invalid Input.. Please Enter An Integer..\n";
        }else{
            break;
        }
    }

    if(input==-1){
        cout<<"Bye..BYe..\n";
        return 0;
    }else if(input==-2){
        maxRange_num=selectRange(gen);
        continue;
    }
        
    if(input==maxRange_num){
        cout<<"WOW! Matched!..After "<<attempt<<" Attempts..\n";
        attempt=0;
    }else{
        if(input>maxRange_num){
            cout<<"Too High...Try Again...\n"<<endl;
        }else{
            cout<<"Too Low...Try Again...\n"<<endl;
        }

    }
    attempt++;


    }
    return 0;
}
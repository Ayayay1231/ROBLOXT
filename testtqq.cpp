#include<iostream>
#include <ctime>

using namespace std;
enum choice{atk,heavyAtk,def,counter};
//enum state{myturn,oppturn,end};

int pHP = 3 , eHP = 3;

void shows(int myHP ,int enHP){
    cout << "==================" << endl;
    cout << "My Hp : " << myHP << endl;
    cout << "Opponent's Hp : " << enHP << endl;
    cout << "==================" << endl;
    cout << " " << endl;

}

void MyPhase(int &myHp,int &enHP){
    int ops;
    cout << "================ You're attacking! ================" << endl;
    cout << "0 for attack / 1 for heavy attack  " << endl;
    while(true){
    cout << "Input a command :   " ;
    cin >> ops;

        if(ops == atk or ops == heavyAtk){
            break;
        }else
        cout << "Invalid command" << endl;
    }

    int oppDefChoice = (rand()%2)+2;

    if(ops == atk ){
        if(oppDefChoice == def){
            cout << "========================" << endl;
            cout << "  Opponent blocked!! " << endl;
            cout << "========================" << endl;
            cout << " " << endl;
        }else{
            enHP -= 1;
            cout << "========================" << endl;
            cout << "  Opponent got attaked!! " << endl;
            cout << "  Opponent's HP : "<< enHP << endl;
            cout << "========================" << endl;
            cout << " " << endl;

        }

    }else if (ops == heavyAtk)
    {
        if(oppDefChoice == def){
            enHP -= 2;
            cout << "========================" << endl;
            cout << "  Opponent got a heavy attaked!! " << endl;
            cout << "  Opponent's HP : "<< enHP << endl;
            cout << "========================" << endl;
            cout << " " << endl;
        }else{
            myHp -= 1;
            cout << "========================" << endl;
            cout << "  You got countered!! " << endl;
            cout << "  Your HP : "<< myHp << endl;
            cout << "========================" << endl;
            cout << " " << endl;
    }
    



}
}


void OpponentPhase(int &myHp,int &enHP){
    int Defops;

    cout << "================ Opponent's attacking! ================" << endl;
    cout << "0 for Defend / 1 for Counter  " << endl;


    while(true){
    cout << "Input a command :   ";
    cin >> Defops;
        if(Defops == (def-2) or Defops == (counter-2)){
            break;
        }else{
            cout << "Invalid command" << endl ;
        }
    }


    int OppoAtk = (rand()%2)  ;

    if(Defops+2 == def ){
        if(OppoAtk == atk){
             cout << "========================" << endl;
            cout << "  You blocked!! " << endl;
            cout << "========================" << endl;
            cout << " " << endl;
        }else{
            myHp -= 2;
            cout << "========================" << endl;
            cout << "  Opponent use a heavy attack!! " << endl;
            cout << "  Your HP : "<< myHp << endl;
            cout << "========================" << endl;
            cout << " " << endl;
        }
        
        
    }else if (Defops+2 == counter )
    {
        if(OppoAtk == atk){
            myHp -= 1;
            cout << "========================" << endl;
            cout << "  Opponent attack!! " << endl;
            cout << "  Your HP : "<< myHp << endl;
            cout << "========================" << endl;
            cout << " " << endl;
        }else{
            enHP -= 2;
            cout << "========================" << endl;
            cout << "  You've countered!! " << endl;
            cout << "  Opponent's HP : "<< enHP << endl;
            cout << "========================" << endl;
            cout << " " << endl;
        }
    }
    
    



}


int main(){
    srand(time(0));
    int MEHP = pHP;
    int OPPHP = eHP;
    bool Myturn = true;

    while (MEHP > 0 and OPPHP > 0)

    {
        shows(MEHP,OPPHP);

       if(Myturn){
        MyPhase(MEHP,OPPHP);
       }else{
        OpponentPhase(MEHP,OPPHP);
       }

       if (MEHP <= 0)
       {
        cout << "========================" << endl;
        cout << "        YOU LOSE" << endl;
        cout << "========================" << endl;
        cout << " " << endl;
       }
       else if (OPPHP <= 0){
        cout << "========================" << endl;
        cout << "        YOU WIN!!" << endl;
        cout << "========================" << endl;
        cout << " " << endl;

       }

       Myturn = !Myturn;
       
    }
    
    return 0;


}

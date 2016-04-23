#include "Encryption.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <array>
using namespace std;

Encryption::Encryption()
{
    //ctor
}

Encryption::~Encryption()
{
    //dtor
}

int Encryption::randGen(int minimum,int maximum){
    return rand() % (maximum+minimum);
}

vector<char> Encryption::faro(vector<char> message,int reps){
    vector<char> scrambled=message;
    /*for(int i=0;i<scrambled.size();i++){
        cout<<scrambled[i]<<endl;
    }*/
    int sizer=scrambled.size();
    int repCount=0;
    while(repCount!=reps){
        char mixer[sizer]; //char *mixer = new char[scrambled.size()]
        int counter=0;
        int marker;
        //cout<<"scrambled size"<<scrambled.size()<<endl;

        for(int i=0;i<(int)scrambled.size()/2;i++){
            mixer[counter]=scrambled[i];
            //cout<<scrambled[i];
            marker=i;
            //cout<<"counter = "<<counter<<" mixer[counter]"<<mixer[counter]<<endl;
            counter=counter+2;
        }
        if(scrambled.size() % 2!=0){
            mixer[counter] = scrambled[marker+1];
        }
        //cout<<"counter = "<<counter<<" mixer[counter]"<<mixer[counter]<<" scr"<<scrambled[marker+1]<<endl;

        //cout<<endl;
        //cout<<"marker"<<marker<<endl;
        //marker++;
        for(int i=0;i<scrambled.size();i++){
            //cout<<mixer[i]<<endl;
        }
        int opCounter=1;
        //cout<<"marker = "<<marker<<endl;
        for(int i=marker+2;i<scrambled.size();i++){
            mixer[opCounter]=scrambled[i];
            //cout<<scrambled[i];
            //cout<<mixer[opCounter]<<" "<<opCounter<<endl;
            opCounter=opCounter+2;
        }
        /*cout<<"contents of mixer"<<endl;
        for(int i = 0; i < 19; i++){
            cout<<mixer[i];
        }*/
        //cout<<endl;
        vector<char> loader={};
        //int spec=scrambled.size();
        //loader.reserve(spec);
        for(int i=0;i<scrambled.size();i++){
            loader.push_back(mixer[i]);
            //cout<<mixer[i]<<endl;
        }
        //cout<<"loader"<<loader[loader.size()-1]<<endl;
        for(int i=0;i<loader.size();i++){
            //cout<<loader[i]<<endl;
        }
        scrambled=loader;
        repCount++;
    }
    return scrambled;
}

vector<char> Encryption::antiFaro(vector<char> scrambled,int reps){
    int repCount=0;
    vector<char> deScramble=scrambled;
    cout<<"time to unscramble "<<endl;
    for(int i =0; i < scrambled.size(); i++){
        //cout<<scrambled[i]<<endl;
    }

    while(repCount!=reps){
        char holder[deScramble.size()];
        int counter=0;
        int marker;
        for(int i=0;i<deScramble.size();i=i+2){
            holder[counter]=deScramble[i];
            //cout<<holder[counter]<<deScramble[i];
            counter++;
            marker=i;
            /*if(counter==deScramble.size()/2){
                break;
            }*/
        }if(deScramble.size() % 2!=0){
            holder[counter+1]=deScramble[marker+2];
            //cout<<"faulty point"<<holder[counter+1]<<endl;
        }else{
        counter=counter+2;
        }
        //cout<<endl;
        //counter--;
        for(int i=1;i<deScramble.size();i=i+2){
            holder[counter]=deScramble[i];
            //cout<<holder[counter];
            counter++;
            /*if(counter==deScramble.size()-2){
                break;
            }*/
        }
        //cout<<endl;
        vector<char> loader;
        for(int i=0;i<deScramble.size();i++){
            loader.push_back(holder[i]);
        }
        deScramble=loader;
        repCount++;
        }
        return deScramble;
}

vector<char> Encryption::sixPile(vector<char> input,int reps){
    int repCount=0;
    vector<char> pool=input;
    int sizer=input.size();
    while(repCount!=reps){
        int pileCount=1;
        vector<char> p1;
        vector<char> p2;
        vector<char> p3;
        vector<char> p4;
        vector<char> p5;
        vector<char> p6;
        stack<char> deck;
        for(int i=pool.size()-1;i>=0;i--){
            deck.push(pool[i]);
        }
        while(!deck.empty()){
            if(pileCount==1){
                p1.push_back(deck.top());
                deck.pop();
                pileCount++;
            }else if(pileCount==2){
                p2.push_back(deck.top());
                deck.pop();
                pileCount++;
            }else if(pileCount==3){
                p3.push_back(deck.top());
                deck.pop();
                pileCount++;
            }else if(pileCount==4){
                p4.push_back(deck.top());
                deck.pop();
                pileCount++;
            }else if(pileCount==5){
                p5.push_back(deck.top());
                deck.pop();
                pileCount++;
            }else if(pileCount==6){
                p6.push_back(deck.top());
                deck.pop();
                pileCount=1;
            }
        }
        vector<char> shuffled;
        for(int i=0;i<p1.size();i++){
            shuffled.push_back(p1[i]);
        }
        for(int i=0;i<p5.size();i++){
            shuffled.push_back(p5[i]);
        }
        for(int i=0;i<p3.size();i++){
            shuffled.push_back(p3[i]);
        }
        for(int i=0;i<p6.size();i++){
            shuffled.push_back(p6[i]);
        }
        for(int i=0;i<p2.size();i++){
            shuffled.push_back(p2[i]);
        }
        for(int i=0;i<p4.size();i++){
            shuffled.push_back(p4[i]);
        }
        pool=shuffled;
        repCount++;
    }
    return pool;
}

vector<char> Encryption::antiSixPile(vector<char> input,int reps){
    int repCount=0;
    vector<char> pool=input;
    int sizer=pool.size();
    //cout<<"sizer: "<<sizer<<endl;
    while(repCount!=reps){
        int determinant=(sizer%6);
        int a1=0;
        int a2=0;
        int a3=0;
        int a4=0;
        int a5=0;
        int a6=0;
        queue<char> p1;
        queue<char> p2;
        queue<char> p3;
        queue<char> p4;
        queue<char> p5;
        queue<char> p6;
        vector<char> deShuffle;
        if(determinant==1){
            a1=1;
        }else if(determinant==2){
            a1=1;
            a2=1;
        }else if(determinant==3){
            a1=1;
            a2=1;
            a3=1;
        }else if(determinant==4){
            a1=1;
            a2=1;
            a3=1;
            a4=1;
        }else if(determinant==5){
            a1=1;
            a2=1;
            a3=1;
            a4=1;
            a5=1;
        }/*
        cout<<"determinant: "<<determinant<<endl;
        cout<<"a1: "<<a1<<endl;
        cout<<"a2: "<<a2<<endl;
        cout<<"a3: "<<a3<<endl;
        cout<<"a4: "<<a4<<endl;
        cout<<"a5: "<<a5<<endl;
        cout<<"a6: "<<a6<<endl;*/
        for(int i=((sizer/6)+a1)-1;i>=0;i--){
            p1.push(pool[i]);
        }
        for(int i=(((sizer/6)+a1)+((sizer/6)+a5))-1;i>=((sizer/6)+a1)-1;i--){
            p5.push(pool[i]);
        }
        for(int i=(((sizer/6)+a1)+((sizer/6)+a5)+((sizer/6)+a3))-1;i>=(((sizer/6)+a1)+((sizer/6)+a5))-1;i--){
            p3.push(pool[i]);
        }
        for(int i=(((sizer/6)+a1)+((sizer/6)+a5)+((sizer/6)+a3)+((sizer/6)+a6))-1;i>=(((sizer/6)+a1)+((sizer/6)+a5)+((sizer/6)+a3))-1;i--){
            p6.push(pool[i]);
        }
        for(int i=(((sizer/6)+a1)+((sizer/6)+a5)+((sizer/6)+a3)+((sizer/6)+a6)+((sizer/6)+a2))-1;i>=(((sizer/6)+a1)+((sizer/6)+a5)+((sizer/6)+a3)+((sizer/6)+a6))-1;i--){
            p2.push(pool[i]);
        }
        for(int i=(((sizer/6)+a1)+((sizer/6)+a5)+((sizer/6)+a3)+((sizer/6)+a6)+((sizer/6)+a2)+((sizer/6)+a4))-1;i>=(((sizer/6)+a1)+((sizer/6)+a5)+((sizer/6)+a3)+((sizer/6)+a6)+((sizer/6)+a2))-1;i--){
            p4.push(pool[i]);
        }
        int unDeal=determinant;
        int counter=0;
        stack<char> deckBox;
        while(deckBox.size()<pool.size()){
            if(unDeal==6){
                deckBox.push(p6.front());
                counter++;
                p6.pop();
                unDeal--;
            }else if(unDeal==5){
                deckBox.push(p5.front());
                counter++;
                p5.pop();
                unDeal--;
            }else if(unDeal==4){
                deckBox.push(p4.front());
                counter++;
                p4.pop();
                unDeal--;
            }else if(unDeal==3){
                deckBox.push(p3.front());
                counter++;
                p3.pop();
                unDeal--;
            }else if(unDeal==2){
                deckBox.push(p2.front());
                counter++;
                p2.pop();
                unDeal--;
            }else if(unDeal==1){
                deckBox.push(p1.front());
                counter++;
                p1.pop();
                unDeal=6;
            }
        }
        for(int i=0;i<sizer;i++){
        char loader=(deckBox.top());
        deShuffle.push_back(loader);
        deckBox.pop();
        }

        //cout<<"hi"<<endl;
        pool=deShuffle;
        repCount++;
    }
    return pool;
}

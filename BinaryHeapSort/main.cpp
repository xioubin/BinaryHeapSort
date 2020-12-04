//
//  main.cpp
//  BinaryHeapSort
//
//  Created by 謝育斌 on 2020/12/3.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
typedef struct data{
    int priority;
    char ch;
    data();
    data(int priority,char ch);
}Data;

data::data(){
    priority=-1;
    ch=' ';
}

data::data(int pri,char c){
    priority=pri;
    ch=c;
}

void BinaryHeapSort(vector<data>& input,int end){
    if(input[end].priority<input[end/2].priority){
        swap(input[end],input[end/2]);
        if(end>1) BinaryHeapSort(input, end/2);
    }
    else
        return;
}



char popBinaryHeap(vector<data>& input){
    char output=input[1].ch;
    swap(input[1],input[input.size()-1]);
    input.erase(input.end() - 1);
    int loc=1;
    while(loc*2<input.size()){
        if(input[loc*2].priority<input[loc*2+1].priority||loc*2+1==input.size()){
            if(input[loc*2].priority<input[loc].priority){
                swap(input[loc*2],input[loc]);
                loc*=2;
            }
            else
                loc*=2;
        }
        else if(input[loc*2].priority>input[loc*2+1].priority){
            if(input[loc].priority>input[loc*2+1].priority){
                swap(input[loc],input[loc*2+1]);
                loc=loc*2+1;
            }
            else
                loc*=2 + 1;
        }
        else break;
    }
    return output;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //cout << "your mother fucker!";
    
    vector<Data> input{Data()};
    string line;
    getline(cin,line);
    stringstream ss(line);
    char ch,c;
    int pri;
    while(ss>>ch>>pri){
        input.push_back(data(pri,ch));
        BinaryHeapSort(input, (int)input.size()-1);
        ss>>ch;
    }
    
    while(input.size()>=2){
        c=popBinaryHeap(input);
        cout<<c;
        //for(int i=1;i<input.size();i++)
        //{
        //    cout<<"pri: "<<input[i].priority<<" ch: "<<input[i].ch<<endl;
        //}
    }
    return 0;
}

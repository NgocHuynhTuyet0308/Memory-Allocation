#include <iostream>
#define maxl 100
using namespace std;


void inputData(int processSize[], int blockSize[], int &processQ, int &blockQ){
    cout<<"Input the number of process: "<<endl;
    cin>>processQ;
    cout<<"Input the number of block: "<<endl;
    cin>>blockQ;
    cout<<"Input process size: "<<endl;
    for(int i=0; i<processQ; i++){
        cin>>processSize[i];
    }
    cout<<"Input block size: "<<endl;
    for(int i=0; i<blockQ; i++){
        cin>>blockSize[i];
    }
}
void lastFit(int processSize[], int blockSize[], int &processQ, int &blockQ, int allocation[]){
    for(int i=0; i<processQ; i++){
        allocation[i] = -1;
    }
    for(int i=0; i<processQ; i++){
        for(int j=blockQ-1; j>=0; j--){
            if(blockSize[j] >= processSize[i]){
                allocation[i] = j;
                blockSize[j] = blockSize[j] - processSize[i];
                break;
            }
        }
    }
}
void outputData(int processSize[], int blockSize[], int &processQ, int &blockQ, int allocation[]){
    cout<<"Process size"<<endl;
    for(int i=0; i<processQ; i++){
        cout<<processSize[i]<<" ";
        if(allocation[i] != -1){
            cout<<allocation[i] + 1;
        }else{
            cout<<"Not allocated";
        }
        cout<<endl;
    }
}
int main(){
    int processSize[maxl], blockSize[maxl];
    int processQ, blockQ;
    int allocation[maxl];

    inputData(processSize, blockSize, processQ, blockQ);
    lastFit(processSize, blockSize, processQ, blockQ, allocation);
    outputData(processSize, blockSize, processQ, blockQ, allocation);

    return 0;
}
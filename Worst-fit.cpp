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
int getMax(int blockSize[], int blockQ){
    int max = blockSize[0];
    for(int i=0; i<blockQ; i++){
        if(blockSize[i] > max) max = blockSize[i];
    }
    return max;
}
void worstFit(int processSize[], int blockSize[], int &processQ, int &blockQ, int allocation[]){
    for(int i=0; i<processQ; i++){
        allocation[i] = -1;
    }
    
    for(int i=0; i<processQ; i++){
        int bestIdx = -1;
        for(int j=0; j<blockQ; j++){
           if(blockSize[j] >= processSize[i]){
                if(bestIdx==-1){
                    bestIdx = j;
                }else{
                    if(blockSize[bestIdx] < blockSize[j]){
                        bestIdx = j;
                    }
                }
           }
        }
        if(bestIdx != -1){
             allocation[i] = bestIdx;
            blockSize[bestIdx] = blockSize[bestIdx] - processSize[i];
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
    worstFit(processSize, blockSize, processQ, blockQ, allocation);
    outputData(processSize, blockSize, processQ, blockQ, allocation);
    
    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAXINT 100
using namespace std;


int multFunc(char*,char *);
int iToC(int,char*);
int lengthStr(char*);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int N = 0;
    cin >> N;
   
    char output[MAXINT] = {'1'};
    char *po = output;
    char input[MAXINT] = {'1'};
    char *pi = input;
   
    int i=1;
    
    
    for(i=1;i<N+1;i++){               
        
        iToC(i,pi);        
        multFunc(po,pi);             
    }    
    
    cout << output << endl ;
        
    return 0;
}

int iToC(int input,char *pi){
    
    char tempStr[MAXINT];
    int i =0;
    int temp = input;
    
    while(1){
        tempStr[i++] = temp%10+48;
        temp = temp/10;
        if(temp==0){ 
            tempStr[i] = '\0';
            break;
        }  
    }
    
    for(int j=0;j<i;j++){
        pi[j] = tempStr[i-j-1];
    }
    pi[i] = '\0';
    
    return true;
}

int lengthStr(char *a){
    int result=0;
    int i=0;    
    
    while(1){
        if(a[i++] == '\0'){
            //cout << "break";
            result = i-1;
            break;
        }    
    }
    
    //cout << "length : " << result <<endl;
    
   return result; 
}

int multFunc(char *a,char *b){
    
   
    int aLength = lengthStr(a);
    int bLength = lengthStr(b);
  
    int i=0;
    int j=0;
    char sum[bLength][aLength+bLength]; 
    char result[aLength+bLength]; 
   
    for(i=0;i<bLength;i++){
        for(j=0;j<aLength+bLength;j++){
            
            sum[i][j]='0';
            
        }
        
      
    }
      
    
    int temp=0;
    int addCnt = 0;
    
    for(j=0;j<bLength;j++){
        addCnt = 0;
        for(i=aLength;i>0;i--){            
            temp = (static_cast<int>(a[i-1])-48)*(static_cast<int>(b[j])-48)+addCnt;
            sum[j][i+j] = temp%10+48;
           
            addCnt = temp/10;
            if(i==1){
                sum[j][i+j-1] = addCnt+48;
                
            }
        }
       
    }
         
    addCnt = 0;
    for(j=aLength+bLength-1;j>-1;j--){
        
        temp = addCnt;
        for(i=0;i<bLength;i++){
            temp += sum[i][j]-48;
                      
        }
               
        addCnt = temp/10;
        result[j] = temp%10+48;
        if(i==0){            
            result[0] = addCnt+48;
        }
        
    }
   
    int cntTemp =0 ;
    
    for(i=0;i<aLength+bLength;i++){
         
        if(!(i==0 && result[0]=='0')){
            a[cntTemp] = result[i];    
            cntTemp++;
        }
    }
   
    a[cntTemp]='\0';
     
    return true;
}




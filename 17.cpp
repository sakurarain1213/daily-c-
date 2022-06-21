#include <bits/stdc++.h>
using namespace std;


int main(){
    int cas;
    cin>>cas;
    for(int n=0;n<cas;n++){
        int times[500]={0};//初始化
        int len;
        cin>>len;
        int num[len];

        for(int i=0;i<len;i++){
            cin>>num[i];
            times[num[i]]++;
        }
        cout<<"case #"<<n<<":"<<endl;

        while(1){
            for(int i=0;i<len;i++){
                if(num[i]==(max_element(times,times+500))-times)
                    cout<<num[i]<<" ";
            }
            *max_element(times,times+500)=0;
            if(*max_element(times,times+500)==0){
                cout<<endl;
                break;
            }
        }
    }
}

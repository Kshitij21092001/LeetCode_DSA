class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int months[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        int sum=0;
        for(int i=0;i<12;i++){
            sum+=months[i];
            months[i]=sum;
        }

        int aliceCome=0;
        int aliceGo=0;
        int bobCome=0;
        int bobGo=0;

        if(stoi(arriveAlice.substr(0,2))==1){
            aliceCome+=stoi(arriveAlice.substr(3,2));
        }
        else{
            int month=stoi(arriveAlice.substr(0,2));
            aliceCome+=(months[month-2]+stoi(arriveAlice.substr(3,2)));
        }

        if(stoi(leaveAlice.substr(0,2))==1){
            aliceGo+=stoi(leaveAlice.substr(3,2));
        }
        else{
            int month=stoi(leaveAlice.substr(0,2));
            aliceGo+=(months[month-2]+stoi(leaveAlice.substr(3,2)));
        }

        if(stoi(arriveBob.substr(0,2))==1){
            bobCome+=stoi(arriveBob.substr(3,2));
        }
        else{
            int month=stoi(arriveBob.substr(0,2));
            bobCome+=(months[month-2]+stoi(arriveBob.substr(3,2)));
        }

        if(stoi(leaveBob.substr(0,2))==1){
            bobGo+=stoi(leaveBob.substr(3,2));
        }
        else{
            int month=stoi(leaveBob.substr(0,2));
            bobGo+=(months[month-2]+stoi(leaveBob.substr(3,2)));
        }

        if(bobGo<aliceCome || aliceGo<bobCome)return 0;
        return min(aliceGo,bobGo)-max(aliceCome,bobCome)+1;
    }
};
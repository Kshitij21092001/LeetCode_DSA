class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int starthr=stoi(startTime.substr(0,2));
        int startmin=stoi(startTime.substr(3,2));
        int startsec=stoi(startTime.substr(6,2));

        int endhr=stoi(endTime.substr(0,2));
        int endmin=stoi(endTime.substr(3,2));
        int endsec=stoi(endTime.substr(6,2));

        int tstartSec=(3600*starthr)+(60*startmin)+(startsec);
        int tendSec=(3600*endhr)+(60*endmin)+(endsec);

        return abs(tstartSec-tendSec);
    }
};
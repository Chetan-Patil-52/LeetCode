class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(begin(meetings),end(meetings));

        vector<long long> lastAvailableAt(n,0);// this will strore when the room will be avl
        vector<int> roomUsedCount(n,0);// count the number of time each room is used

        for(vector<int>& meet : meetings){
            int start = meet[0];
            int end   = meet[1];

            bool found = false;
            long long EarlyEndRoomTime = LLONG_MAX;
            int EarlyEndRoom           = 0;

            for(int room = 0;room<n;room++){// as mentioned there would be n rooms from (0-(n-1));
                if(lastAvailableAt[room] <= start){
                    found = true;
                    lastAvailableAt[room] = end;
                    roomUsedCount[room]++;
                    break;
                }
                if(lastAvailableAt[room] < EarlyEndRoomTime){
                    EarlyEndRoom = room;
                    EarlyEndRoomTime = lastAvailableAt[room];
                }

            }

            if(!found){
                lastAvailableAt[EarlyEndRoom] += (end-start);
                roomUsedCount[EarlyEndRoom]++;
            }
        }

        int resultRoom = -1;
        int maxUse     = 0;
        for(int room = 0;room <n;room++){
            if(roomUsedCount[room] > maxUse){
                maxUse = roomUsedCount[room];
                resultRoom = room;
            }
        }
        return resultRoom;
    }
};

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


// Using priority queues
class Solution {
public:
    typedef pair<long long, int> P;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Using 2 priorirty queues
        int m = meetings.size();
        sort(begin(meetings),end(meetings));
        vector<int> roomUsedCount(n,0);
        priority_queue<P,vector<P>,greater<P>> usedRooms;
        priority_queue<int,vector<int>,greater<int>> availableRooms;

        for(int room = 0; room<n;room++){
            availableRooms.push(room);
        }

        for(vector<int>& meet : meetings){
            int start = meet[0];
            int end   = meet[1];
            int duration = end-start;

            while(!usedRooms.empty() && usedRooms.top().first <= start){
                int room = usedRooms.top().second;
                usedRooms.pop();
                availableRooms.push(room);
            }

            if(!availableRooms.empty()){
                int room = availableRooms.top();
                availableRooms.pop();
                usedRooms.push({end,room});
                roomUsedCount[room]++;
            }else{
                int room = usedRooms.top().second;
                long long endTime = usedRooms.top().first;

                usedRooms.pop();
                usedRooms.push({endTime + duration,room});
                roomUsedCount[room]++;
            }
        }

        int maxUse = 0;
        int resultRoom = -1;

        for(int room=0;room<n;room++){
            if(roomUsedCount[room] > maxUse){
                maxUse = roomUsedCount[room];
                resultRoom = room;
            }
        }
        return resultRoom;
    }
};

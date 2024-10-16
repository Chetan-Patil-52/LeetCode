class Solution {
public:
    typedef pair<int ,char> P;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<P, vector<P>> pq;

        if(a > 0) {
            pq.push({a, 'a'});
        }
        if(b > 0) {
            pq.push({b, 'b'});
        }
        if(c > 0) {
            pq.push({c, 'c'});
        }

        string result = "";

        while(!pq.empty()) {
            int currCount = pq.top().first;
            char currChar = pq.top().second;
            pq.pop();

            // Check if the last two characters are the same as the current one
            if(result.size() >= 2 && result[result.length()-1] == currChar && result[result.length()-2] == currChar) {
                if(pq.empty()) {
                    break; // No more characters to use
                }

                // Use the next character in the queue
                int nextCount = pq.top().first;
                char nextChar = pq.top().second;
                pq.pop();

                result.push_back(nextChar);
                nextCount--;

                if(nextCount > 0) {
                    pq.push({nextCount, nextChar});
                }

                pq.push({currCount, currChar}); // Push the current char back
            } else {
                result.push_back(currChar);
                currCount--;

                if(currCount > 0) {
                    pq.push({currCount, currChar});
                }
            }
        }

        return result;
    }
};

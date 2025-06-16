class Solution {
public:
    int maxDiff(int num) {
        string maxi = to_string(num);
        string mini = maxi;
        int n = maxi.size();

        char char1 = '\0';
        int i;
        bool flag = false;
        
        // MAXI logic: replace first non-9 digit with '9'
        for (int j = 0; j < n; j++) {
            if (maxi[j] != '9') {
                i = j;
                flag = true;
                char1 = maxi[i];
                break;
            }
        }
        for (i; i < n; i++) {
            if (flag && maxi[i] == char1) {
                maxi[i] = '9';
            }
        }

        // MINI logic: replace first digit not '1' with '1' (if at index 0), else with '0'
        char char2 = '\0';
        flag = false;
        for (int j = 0; j < n; j++) {
            if (mini[j] != '1' && mini[j] != '0') {
                i = j;
                flag = true;
                char2 = mini[i];
                break;
            }
        }

        if (flag) {
            char replace_with = (i == 0) ? '1' : '0';
            for (i; i < n; i++) {
                if (mini[i] == char2) {
                    mini[i] = replace_with;
                }
            }
        }

        int result1 = stoi(maxi);
        int result2 = stoi(mini);
        int result = result1 - result2;
        return result;
    } 
};

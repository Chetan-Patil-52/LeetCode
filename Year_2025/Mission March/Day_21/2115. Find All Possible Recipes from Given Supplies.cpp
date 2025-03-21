// Bruteforce 
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        int n = recipes.size();
        vector<string> result;

        unordered_set<string> st(begin(supplies),end(supplies));

        vector<bool> cooked(n,false);

        int count = n;

        while(count--){
            

            for(int j=0;j<n;j++){
                if(cooked[j] == true){
                    continue;
                }

                bool possible = true;
                for(int k=0;k<ingredients[j].size();k++){
                    if(!st.count(ingredients[j][k])){
                        possible = false;
                        break;
                    }
                }

                    if(possible){
                        st.insert(recipes[j]);
                        result.push_back(recipes[j]);
                        cooked[j] = true;
                    }


            }
        }
        return result;

    }
};

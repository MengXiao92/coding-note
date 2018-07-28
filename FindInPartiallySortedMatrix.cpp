class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty())  return false;
        int rowLength = array.size();
        int colLength = array[0].size();
        for(int i = rowLength -1; i >= 0; i--){
            if(array[i].empty()) continue;
            if(target >= array[i][0]){
                for(int j = 0; j < colLength; j++){
                    if(target == array[i][j]){
                        return true;
                    }else if(target > array[i][j]){
                        continue;
                    }else{
                        break;
                    }
                }
            }
            else continue;
        }
        return false;
    }
};

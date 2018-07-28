class Solution {
public:
    void replaceSpace(char *str,int length) {
        if(str==NULL || length <= 0) return ;
        int strLength = 0;
        int spaceNum = 0;
        int i = 0;
        while(str[i] != '\0'){
            ++strLength;
            if(str[i] == ' ')
                ++spaceNum;
            ++i;
        }
        int newStrLength = strLength + spaceNum * 2;
        if(newStrLength > length) return ;
        int indexStr = strLength;
        int newIndexStr = newStrLength;
        
        while(indexStr>=0 && newIndexStr >= indexStr){
            if(str[indexStr] == ' '){
                str[newIndexStr--] = '0';
                str[newIndexStr--] = '2';
                str[newIndexStr--] = '%';
            }
            else{
                str[newIndexStr--] = str[indexStr];
            }
            --indexStr;
        }
    }
};

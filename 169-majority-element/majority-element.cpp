class Solution {
public:
    int majorityElement(vector<int>& arr) {
    int element;
        int count =0;
        
        for(int i=0;i<arr.size();i++){
            if(count==0){
                count++;
                element = arr[i];
            }
            else if(arr[i]==element){
                count++;
            }
            else{
                count--;
            }
        }
        
        for(auto x:arr){
            if (x == element)
                count++;
        }
        
        return (count > arr.size() / 2) ? element : -1;
    }
};
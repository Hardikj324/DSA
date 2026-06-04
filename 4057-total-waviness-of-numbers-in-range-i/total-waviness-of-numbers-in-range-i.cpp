class Solution {
public:
int waviness(int num) {
    int cnt=0;
    vector<int> arr;

    while(num>0){
        arr.push_back(num%10);
        num=num/10;
    }

    int n = arr.size();

        if (n < 3) return 0;

    for(int i=1;i<n-1;i++){
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) cnt++;
        if(arr[i]<arr[i-1] && arr[i]<arr[i+1]) cnt++;
    }

    return cnt;

}
    int totalWaviness(int num1, int num2) {
        int total = 0;

        for (int i = num1; i <= num2; i++) {
            total += waviness(i);
        }

        return total;
    }
};
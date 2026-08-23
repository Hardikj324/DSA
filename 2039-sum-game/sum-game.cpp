class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int sum_first = 0, sum_second = 0;
        int mark_first = 0, mark_second = 0;

        for (int i = 0; i < n; i++) {
            char curr = num[i];
            if (i < n/2) {
                if (curr == '?') mark_first++;
                else sum_first += (curr - '0');
            } else {
                if (curr == '?') mark_second++;
                else sum_second += (curr - '0');
            }
        }

        int total = mark_first + mark_second;

        if (total % 2 == 1) return true;

        int  diff = sum_first - sum_second;
        int qdiff = mark_second - mark_first;

        return diff !=9*(qdiff/2);




    }
};
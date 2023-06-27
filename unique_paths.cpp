 class Solution {
 public:
     int uniquePaths(int m, int n) {
         vector<int>dp()
         return helper(m, n);
     }

 private:
     int helper(int m, int n) {
         if (m == 1 && n == 1)
             return 1;
         if (m < 1 || n < 1)
             return 0;

         int count = 0;
         count += helper(m - 1, n);
         count += helper(m, n - 1);

         return count;
     }
 };


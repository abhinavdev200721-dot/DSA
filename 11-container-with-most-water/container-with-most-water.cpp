// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int len=height.size();
//         int max=0; 
//         int ind1=0;
//         int ind2=0;
//         int bmax=0;
//         for(int i=0;i<len;i++){
//             if(height[i]>max){
//                 max=height[i];
//                 ind1=i;
//             }
//         }
//         for(int i=0;i<len;i++){
//             if(height[len-i-1]<=max){
//                 bmax=height[len-i-1];
//                 ind2=(len-i-1);
//                 break;
//             }
//         }
        
//         // return ind2;
//         return {min(bmax,max)*(ind2-ind1)};
//     }
// };

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ind1 = 0;                 
        int ind2 = height.size() - 1;  
        int max_area = 0;
        
        while (ind1 < ind2) {
            int current_area = min(height[ind1], height[ind2]) * (ind2 - ind1);
           
            if (current_area > max_area) {
                max_area = current_area;
            }
            if (height[ind1] < height[ind2]) {
                ind1++;
            } else {
                ind2--;
            }
        }
        
        return max_area;
    }
};

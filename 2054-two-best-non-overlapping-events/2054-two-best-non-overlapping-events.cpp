class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        sort(events.begin(),events.end());

        vector<int> suffix(n);
        suffix[n-1] = events[n-1][2];

        for(int i=n-2;i>=0;i--){
            suffix[i] = max(events[i][2],suffix[i+1]);
        }
        
        int maxsum =0;
        for(int i=0;i<n;i++){
            int left = i+1, right = n-1;
            int next = -1;
            while(left<=right){
                int mid = left+(right-left)/2;
                if(events[mid][0]>events[i][1]){
                    next = mid;
                    right= mid-1;
                }else{
                    left=mid+1;
                }
            }

            if(next!=-1){
                maxsum = max(maxsum,events[i][2]+suffix[next]);
            }
            maxsum = max(maxsum,events[i][2]);
        }
        return maxsum;

        
    }
};
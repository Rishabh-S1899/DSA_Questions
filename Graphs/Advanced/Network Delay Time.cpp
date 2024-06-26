//Solved using Bellman Ford Algorithm, can also be done using  Dijkstra's Algorithm


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> distance(n+1,INT_MAX);
        int j=1;
        distance[k]=0;
        int size=times.size();
        while(j!=n){
            for(int i=0; i<size ;i++){
                if(distance[times[i][0]]!=INT_MAX &&distance[times[i][0]]+times[i][2] < distance[times[i][1]]){
                    distance[times[i][1]]=distance[times[i][0]]+times[i][2];
                }
            }
            j++;
        }
        int maxvalue=INT_MIN;
        for(int i=1;i<n+1;i++){
            if(distance[i]==INT_MAX){
                return -1;
            }
            if(distance[i]>maxvalue){
                maxvalue=distance[i];
            }
        }
        return maxvalue;
    }
};

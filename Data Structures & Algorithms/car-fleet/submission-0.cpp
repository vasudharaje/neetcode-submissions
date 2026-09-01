class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed){
        vector<pair<int,int>> cars(position.size());
        for(int i =0; i<position.size(); i++){
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.begin(), cars.end());
        int fleets = 0;
        double slowest_so_far = 0.0;
        int n = position.size();
        for(int i=n-1; i>=0 ; i--){
            double time = (double)(target - cars[i].first)/cars[i].second;
            if(time>slowest_so_far){
                fleets++;
                slowest_so_far = time;
            }
        }
        return fleets;
    }
};

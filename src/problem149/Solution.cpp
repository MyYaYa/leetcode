/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int result = 0;
        for(int i = 0; i < points.size(); i++){
            int samePoint = 1;
            int K0 = 0;
            unordered_map<string, int> map;
            for(int j = i + 1; j < points.size(); j++){
                if(points[i].x == points[j].x && points[i].y == points[j].y){
                    samePoint++;
                }
                else if(points[i].x == points[j].x){
                    K0++;
                }
                else{
                    double slope = double(points[i].y - points[j].y) / double(points[i].x - points[j].x);
                    string slope_str = slope == 0.0 ? to_string(0.0) : to_string(slope);
                    map[slope_str]++;
                }
            }
            int localMax = K0;
            for(auto it = map.begin(); it != map.end(); it++){
                localMax = max(localMax, it->second);
            }
            localMax += samePoint;
            result = max(result, localMax);
        }
        return result;
    }
};
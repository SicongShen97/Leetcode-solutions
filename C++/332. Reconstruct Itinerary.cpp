/*
回溯：横向遍历目的地，纵横向递归出发地
*/
class Solution {
public:
    unordered_map<string, map<string, int>> targets;
    vector<string> path;
    bool backtrack(const string& from, int ticketNum) {
        if (path.size() == ticketNum + 1) {
            return true;
        }
        for (pair<const string, int>& target : targets[from]) {
            if (target.second > 0) {
                path.push_back(target.first);
                target.second--;
                if (backtrack(target.first, ticketNum)) return true;
                target.second++;
                path.pop_back();
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        targets.clear();
        path.clear();
        for (auto ticket : tickets) {
            targets[ticket[0]][ticket[1]]++;
        }
        path.push_back("JFK");
        backtrack("JFK", tickets.size());
        return path;
    }
};
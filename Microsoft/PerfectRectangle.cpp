class Solution {
 public:
  bool isRectangleCover(vector<vector<int>>& r) {
    int n = r.size();

    if (n == 1) return true;
    map<pair<int, int>, int> pointCounts;

    for (auto& it : r) {
      pointCounts[{it[0], it[1]}]++;
      pointCounts[{it[2], it[3]}]++;
      pointCounts[{it[0], it[3]}]--;
      pointCounts[{it[2], it[1]}]--;
    }

    int numMarks = 0;

    for (auto it = pointCounts.begin(); it != pointCounts.end(); it++) {
      if (it->second != 0) {
        if (abs(it->second) != 1) return false;

        numMarks++;
      }
    }

    return numMarks == 4;
  }
};

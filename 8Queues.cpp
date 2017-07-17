/**
 * 八皇后问题：
 * 创建一个包含8个元素的数组，每个数组的第i个数表示第i行的棋子的列号。
 * 因为列和行不能重复，所以列号一定是0~7，可以求出数组的全排列，然后筛除对角线的排列。
 * 
 * N皇后可以类推
 */

#include <vector>
#include <iostream>

using namespace std;

typedef vector<int>::iterator VecIt;

vector<vector<int>> result;

void permuation(vector<int> &nums, VecIt begin);
bool checkDiagonal(vector<int> &nums);

int queues(int n = 8) {
    // 初始化行和列的号
    vector<int> chess;
    for(int i = 0; i < n; ++i) {
        chess.push_back(i);
    }

    result.clear();
    permuation(chess, chess.begin());
    return result.size();
}

// 检查对角线的元素
bool checkDiagonal(vector<int> &nums) {
    for(int i = 0; i < nums.size() - 1; ++i) {
        for(int j = i + 1; j < nums.size(); ++j) {
            if (abs(nums[i] - nums[j]) == j - i) {
                return false;
            }
        }
    }
    return true;
}

// 求全排列的方法
void permuation(vector<int> &nums, VecIt begin) {
    if(begin == nums.end()) {
        if(checkDiagonal(nums)) {
            result.push_back(nums);
        }
    }

    for(auto it = begin; it != nums.end(); ++it) {
        swap(*it, *begin);
        VecIt iter = begin + 1;
        permuation(nums, iter);
        swap(*it, *begin);
    }
}

int main() {

    // vector<int> nums{1,2,3,4};
    // permuation(nums, nums.begin());

    // cout << result.size() << endl;

    // for(auto &v : result) {
    //     for(auto &i : v) {
    //         cout << i << "\t";
    //     }
    //     cout << "\n";
    // }

    cout << queues() << endl;
    getchar();
    return 0;
}
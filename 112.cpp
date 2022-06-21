 #include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    // 定义各个数值代表的字符串
    vector<string> dataChen = {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
    };
    // 结果数组
    vector<string> result;
public:
    vector<string> letterCombinations(string digits) {
        // 如果给定的字符串是空，则返回空数组
        if (digits.empty()) {
            return result;
        }
        // 当前正在处理的字符串
        string temp;
        // 深搜，从 0 开始
        dfs(digits, temp, 0);
        return result;
    }
    /**
     * 深搜所有的组合
     * @param digits 字符串
     * @param temp 当前正在处理的字符串
     * @param index 当前处理的下标
     */
    void dfs(string digits, string &temp, int index) {
       
        if (index > digits.length()) { // 越界直接返回
            return;
        }
        if (temp.length() == digits.length()) {  // 达到符合要求的边界，保存值到结果数组，并返回
            result.push_back(temp);
            return;
        }
      
        int number_data = digits[index] - '0';  // 获取字符串中 index 处的数字    // 获取其代表的字符串的索引
        number_data -= 2;  // 获取代表的字符串
        string basicString = dataChen[number_data]; // 遍历整个代表的字符串，分为取和不取两种状态
        for (int i = 0; i < basicString.length(); ++i) {  // 取该值
            temp.push_back(basicString[i]); // 进入下一次迭代，将正在处理的索引 + 1
            dfs(digits, temp, index + 1);  // 不取该值
            temp.pop_back();
        }
    }
};
int main() {
   string s;
   cin>>s;
    Solution *pSolution = new Solution;
    auto vector1 = pSolution->letterCombinations(s);
    for (int i = 0; i < vector1.size(); ++i) {
        cout << vector1[i] << " ";
    }
   // system("pause");
    return 0;
}

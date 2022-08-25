//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。 
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：digits = "23"
//输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 
//
// 示例 2： 
//
// 
//输入：digits = ""
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：digits = "2"
//输出：["a","b","c"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= digits.length <= 4 
// digits[i] 是范围 ['2', '9'] 的一个数字。 
// 
//
// Related Topics 哈希表 字符串 回溯 👍 2061 👎 0

//自己写出的版本
class Solution {
public:
    unordered_map<int, string> hash{{1, ""}, {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
    vector<string> ans;
    string path;
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return vector<string>();
        int n = digits.size();
        dfs(digits, 0);
        return ans;
    }

    void dfs(string digits, int u)
    {
        if(u == digits.size())
        {
            ans.push_back(path);
            return;
        }
        auto idx = digits[u] - '0';
            
        for(int j = 0; j < hash[idx].size(); j ++)
        {
            path.push_back(hash[idx][j]);
            dfs(digits, u + 1);
            path.pop_back();
        } 
    }
};


#if 0
class Solution {
public:
    vector<char> digit[10];
    vector<string> res;

    void init() {
        char cur = 'a';
        for (int i = 2; i < 10; i++) {
            for (int j = 0; j < 3; j++)
                digit[i].push_back(cur++);
            if (i == 7 || i == 9)
                digit[i].push_back(cur++);
        }
    }

    void solve(string digits, int d, string cur) {
        if (d == digits.length()) {
            res.push_back(cur);
            return;
        }

        int cur_num = digits[d] - '0';

        for (int i = 0; i < digit[cur_num].size(); i++)
            solve(digits, d + 1, cur + digit[cur_num][i]);
    }

    vector<string> letterCombinations(string digits) {
        if (digits == "")
            return res;
        init();
        solve(digits, 0, "");
        return res;
    }
};

class Solution {
public:
    vector<string> ans;
    string strs[10] = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz",
    };

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ans;
        dfs(digits, 0, "");
        return ans;
    }

    void dfs(string& digits, int u, string path) {
        if (u == digits.size()) ans.push_back(path);
        else {
            for (auto c : strs[digits[u] - '0'])
                dfs(digits, u + 1, path + c);
        }
    }
};

#endif

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return vector<string>();
        string chs[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        std::vector<string> ans;
        ans.push_back("");
        for(int i = 0; i < digits.size(); i ++)
        {
            vector<string> newRes;
            auto cur = digits[i] - '0';
            for(int j = 0; j < ans.size(); j ++)
            {
                for(int k = 0; k < chs[cur].size(); k ++)
                    newRes.push_back(ans[j] + chs[cur][k]);
            }
            ans = newRes;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

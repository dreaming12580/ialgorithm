package java_lc;

import java.util.Set;
import java.util.HashSet;
import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

class MaxRectangle {
    class Trie {
        Trie[] childs;
        boolean isLeaf;
        public Trie() {
            childs = new Trie[26];
        }



    }

    Trie root;
    Map<Integer, Set<String>> map;   // 清单根据单词长度集合起来
    int maxArea;
    int maxLength;
    List<String> ans;    // 别忘最后转换成数组输出

    public String[] maxRectangle(String[] words) {
        root = new Trie();
        // 构造字典树
        for (String str: words) {
            Trie node = root;
            for (char c : str.toCharArray()) {
                if (node.childs[c-'a'] == null) {
                    node.childs[c-'a'] = new Trie();
                }
                node = node.childs[c-'a'];
            }
            node.isLeaf = true;
        }

        map = new HashMap<>();
        ans = new ArrayList<>();
        for (String w : words) {
            int len = w.length();
            maxLength = Math.max(maxLength, len);
            Set<String> set = map.getOrDefault(len, new HashSet<>());
            set.add(w);
            map.put(len, set);
        }
        
        List<String> path = new ArrayList<>();
        for (int key : map.keySet()) {
            path.clear();
            // 回溯需要的参数是： 相同长度单词的集合，存放路径的列表，当前单词的长度
            dfs(map.get(key), path, key);
        }

        String[] ultimate = new String[ans.size()];
        return ans.toArray(ultimate);
    }

    // 回溯的套路
    // 
    public void dfs(Set<String> dic, List<String> path, int wordLen) {
        // 剪枝， dic里的情况不可能得到最优解， 提前过滤掉不考虑
        if (wordLen * maxLength <= maxArea) return;

        // 终止条件：如果path 矩阵的高度已经超过清单中最长单词长度， 结束
        if (path.size() > maxLength) return;

        for (String str : dic) {
            // 做选择
            path.add(str);
            boolean[] res = isValid(path);
            if (res[0]) {   // 下面还可以再加
                int area = path.size() * path.get(0).length();
                if (res[1] && (area > maxArea)) {
                    // 每列都是单词的矩阵
                    maxArea = area;
                    // ans = path; 一定注意这里不能直接把path引用交给答案
                    ans = new ArrayList<>(path);
                }
                // 回溯
                dfs(dic, path, wordLen);
            }
            // 撤销选择
            path.remove(path.size() - 1);
        }
    }

    public boolean[] isValid(List<String> input) {
        boolean allLeaf = true;
        int m = input.size();
        int n = input.get(0).length();
        for (int j = 0; j < n; ++j) {
            // 按列来看单词是否在字典树
            Trie node = root;
            for (int i = 0; i < m; ++i) {
                int c = input.get(i).charAt(j) - 'a';
                if (node.childs[c] == null) {
                    return new boolean[] {false, false};
                }
                node = node.childs[c];
            }
            if (!node.isLeaf) {
                allLeaf = false;
            }
        }
        return new boolean[]{true, allLeaf};
    }
}




















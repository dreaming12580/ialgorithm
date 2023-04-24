
package java_lc;

public class masterMind {

    class Solution {
        public int[] masterMind(String solution, String guess) {
            int fake = 0, real = 0;
            int[] map = new int[26];
    
            for (int i = 0; i < 4; ++i) {
                char sol = solution.charAt(i), gue = guess.charAt(i);
                if (sol == gue) {
                    real++;
                } else {
                    if (map[sol - 'A'] < 0) {
                        fake++;
                    }
                    map[sol - 'A']++;
                    if (map[gue - 'A'] > 0) {
                        fake++;
                    }
                    map[gue - 'A']--;
                }
            }
            int[] ans = {real, fake};
            return ans;
        }
    }
    
}
















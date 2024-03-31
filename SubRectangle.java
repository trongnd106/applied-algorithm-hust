// Largest Black SubRectangle

import java.util.Scanner;
import java.util.Stack;
import java.lang.Math;

public class Main {
    public int largestArea(int[][] a){
        int[] currRow = a[0];
        int maxAns = maxHistogram(currRow);
        for(int i = 1; i < a.length; i++){
            for(int j = 0; j < a[0].length; j++){
                if(a[i][j] == 1){
                    currRow[j] += 1;
                } else currRow[j] = 0;
            }
            int currAns = maxHistogram(currRow);
            maxAns = Math.max(currAns, maxAns);
        }
        return maxAns;
    }
    public int[] prevSmaller(int[] a){
        int[] ps = new int[a.length];
        Stack<Integer> st = new Stack<>();
        
        for(int i = 0; i < a.length; i++){
            while(!st.isEmpty() && a[st.peek()] >= a[i]){
                st.pop();
            }
            if(st.isEmpty()){
                ps[i] = -1;
            } else {
                ps[i] = st.peek();
            }
            st.push(i);
        }
        return ps;
    }
    public int[] nextSmaller(int[] a){
        int[] ns = new int[a.length];
        Stack<Integer> st = new Stack<>();
        int aSize = a.length;
        for(int i = aSize-1; i >= 0; i--){
            while(!st.isEmpty() && a[st.peek()] >= a[i]){
                st.pop();
            }
            if(st.isEmpty()){
                ns[i] = aSize;
            } else {
                ns[i] = st.peek();
            }
            st.push(i);
        }
        return ns;
    }
    public int maxHistogram(int[] a){
        int maxAns = 0;
        int[] ps = prevSmaller(a);
        int[] ns = nextSmaller(a);
        
        for(int i = 0; i < a.length; i++){
            int currMax = (ns[i] - ps[i] - 1)*a[i];
            maxAns = Math.max(maxAns, currMax);
        }
        return maxAns;
    }
    public static void main(String[] args){
        Scanner inp = new Scanner(System.in);
        int n = inp.nextInt();
        int m = inp.nextInt();
        int[][] a = new int[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                a[i][j] = inp.nextInt();
            }
        }
        Main LR = new Main();
        int res = LR.largestArea(a);
        System.out.println(res);
        inp.close();
    }
}

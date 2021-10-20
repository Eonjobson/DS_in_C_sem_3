import java.util.Stack;

public class next_smaller_element {
    public static void main(String[] args) {
        int[] a ={3,10,5,1,15,10,7,6};
        Stack<Integer> s = next_small(a);
        while(!s.isEmpty()){
            System.out.println(s.peek());
            s.pop();

        }
    }
    static Stack next_small(int[] a){
        Stack<Integer> s = new Stack<>();
        Stack<Integer> ans = new Stack<>();
        for(int i=a.length-1;i>=0;i--){
            while(!s.isEmpty() && s.peek()>=a[i]){
                s.pop();
            }
            if(s.isEmpty()){
                ans.push(-1);
            }
            else{
                ans.push(s.peek());
            }
            s.push(a[i]);
        }
        return ans;
    }
}

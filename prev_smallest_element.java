import java.util.Stack;

/**
 * prev_smallest_element
 */
public class prev_smallest_element {

 public static void main(String[] args) {
     int[] a = {5,6,3,2,8};
     prev_smaller(a);
 }   
 static void prev_smaller(int[] a){
     Stack<Integer> ans = new Stack<>();
     for(int i=0;i<a.length;i++){
         while(!ans.isEmpty() && ans.peek()>=a[i]){
             ans.pop();
         }
        if(ans.isEmpty()){
            System.out.println("-1");
        }
        else{
            System.out.println(ans.peek());
        }
        ans.push(a[i]);

     }
 }
}
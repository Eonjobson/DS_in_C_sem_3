import java.util.*;
public class subsets {
    public static void main(String[] args) {
        String s = "abc";
        //subs("", s);
         
    }   
    public static void subs(String p,String up){
        if(up.isEmpty()){
            System.out.println(p);
            return;
        }
        char ch= up.charAt(0);
        subs(p+ch,up.substring(1));
        subs(p, up.substring(1));
        
    } 
    public static ArrayList<String> subsarray(String p,String up){
        
        if(up.isEmpty()){
            ArrayList<String> subs = new ArrayList<String>();
            subs.add(p);
            return subs;    
        }
        char ch = up.charAt(0);
        ArrayList<String> left = subsarray(p+ch,up.substring(1));
        ArrayList<String> right = subsarray(p, up.substring(1));
        left.addAll(right);
        return left;

    }
}

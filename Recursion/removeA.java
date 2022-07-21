//Recursively remove As
//Example = baccad -> bccd
/**
 * removeA
 */
public class removeA {
    public static void main(String[] args) {
        String s = "baccad";
        remove("",s);
    }
    public static void remove(String p,String up) {
        if(up.isEmpty()){
            System.out.println(p);
            return;
        }
        char ch = up.charAt(0);
        if(ch=='a')
        {
            remove(p, up.substring(1));
        }
        else{
            remove(p+ch, up.substring(1));
        }
        
    }
    
}
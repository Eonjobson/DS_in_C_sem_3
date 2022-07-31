/**
 * basicProblem1
 */
import java.util.*;
public class basicProblem1 {

    /**
     * @param args
     */
    public static void main(String[] args) {
        int t;
        int n;
        
        Scanner sc = new Scanner(System.in);    
        n = sc.nextInt(); //n-1
        t = sc.nextInt(); //index I wanna go to (1 Indexed)
        int a[] = new int[n];
        System.out.println("Enter array element");
        for(int i=0; i<n-1; i++){
            a[i] = sc.nextInt();
        }   
        solve(t,n,a);
        

    }
    static void solve(int t,int n,int[] a){
        
        int curr= 1;
        do{
            curr = curr + a[curr-1];
            if(curr == t){
                System.out.println("YES");
                return;
            }
        }
            while(curr<n);
            System.out.println("NO");
            return;


        

    }
}
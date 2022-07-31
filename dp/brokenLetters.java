import java.util.Arrays;

public class brokenLetters {

    public static void main(String[] args) {
        
    }
    static int solve(int n,int k,String s,char[] typeables) {
        boolean typeable[] = new boolean[26];

        Arrays.fill(typeable,false);
        for(int i=0;i<k;i++){
            typeable[typeables[i] - 'a'] = true;
        }
        int[] a = new int[n];
        for(int i=0;i<n;i++){
            if(typeable[s.charAt(i)]){
                a[i]=1;
            }
            else{
                a[i]=0;
            }
        }
        int f[] = new int[n+1];
        int ans =0;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                f[i+1]=0;
            }
            else{
                f[i+1]=f[i]+1;
            }
            ans += f[i+1];
        }
        return ans;
    }
} 
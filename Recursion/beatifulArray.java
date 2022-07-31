import java.util.Arrays;

public class beatifulArray {
    public static void main(String[] args) {
        int arr[] = {5,8,9};
        int ans = solve(arr);
        System.out.println(ans);

    }
    static int solve(int[] arr){
        int min = Integer.MAX_VALUE;
        int size = arr.length;
        int df = 0;
        int p[] = new int[size+1];
        p[0]=0;
        for(int i=1;i<size;i++){
            p[i] = p[i-1] + arr[i-1];
        }
        Arrays.sort(p);
        System.out.println(Arrays.toString(p));
        for(int i=1;i<p.length-1;i++){
            df = p[i] - p[i-1];
            System.out.println(p[i]+" "+p[i-1]);
            if(df<min){
                
                min = df;
                
          
            }
        }
        return min;
    }
}

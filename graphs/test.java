public class test {
    public static void main(String[] args) {
        int a = 5;
        int b = 6;
        swap(a,b);
        System.out.println(a+" "+b);
    }
    static void swap(int i, int j){
        int temp =i;
        i=j;
        j = temp;
    }
}

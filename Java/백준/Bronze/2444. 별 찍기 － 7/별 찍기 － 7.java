import java.util.Scanner;
class Main {
    public static void main(String[] args) {
        Scanner stdInput = new Scanner(System.in);
        int val = stdInput.nextInt();
        for(int i=0;i<val;i++) {
            String alloc = "";
            for(int j=0;j<val-1-i;j++) {
               alloc += " "; 
            }
            for(int j=0;j<2*i+1;j++) {
                alloc += "*";
            }
            System.out.println(alloc);
        }
        for(int i=val-2;i>=0;i--) {
            String alloc = "";
            for(int j=0;j<val-1-i;j++) {
               alloc += " "; 
            }
            for(int j=0;j<2*i+1;j++) {
                alloc += "*";
            }
            System.out.println(alloc);
        }

    }
}
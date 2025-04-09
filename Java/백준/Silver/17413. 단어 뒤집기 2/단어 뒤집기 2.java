import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Stack<Character> st_bracket = new Stack<>(), st_normal = new Stack<>();
        String s = br.readLine();
        char[] arr = s.toCharArray();
        for(int i = 0; i < arr.length; i++) {
            char itm = arr[i];
            if(itm=='<') {
              while(st_normal.size()>0) {
                bw.write(st_normal.peek()+"");
                st_normal.pop();
              }
              st_bracket.push(itm);
              bw.write('<');
            }
            else if(itm=='>') {
              st_bracket.pop();
              bw.write('>');
            } else if(st_bracket.size()!=0) {
              bw.write(arr[i]+"");
            } else if (itm==' ') {
              while(st_normal.size()>0) {
                bw.write(st_normal.peek()+"");
                st_normal.pop();
              }
              bw.write(" ");
            } else {
              st_normal.push(itm);
            }
        }
        while(st_normal.size()>0) {
          while(st_normal.size()>0) {
            bw.write(st_normal.peek()+"");
            st_normal.pop();
          }
        }
        bw.flush();
        bw.close();
        br.close();
    }
}

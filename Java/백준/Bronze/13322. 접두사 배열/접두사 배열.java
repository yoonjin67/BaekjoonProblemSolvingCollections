import java.util.*;
import java.util.stream.Stream;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String targetString = br.readLine();
        for(int i = 0; i < targetString.length(); i++) {
            bw.write(i+"\n");
        }
        bw.flush();
    }
}

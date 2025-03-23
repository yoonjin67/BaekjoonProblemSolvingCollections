import java.util.*;
import java.util.stream.Stream;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        long[] rep = parsePairs(br);
        long[][] Q = new long[(int)rep[0]][2];
        long[][] P = new long[(int)rep[1]][2];
        for(int i = 0; i < rep[0]; i++) {
            Q[i] = parsePairs(br);
        }
        for(int i = 0; i < rep[1]; i++) {
            P[i] = parsePairs(br);
        }
        long res = 0;
        for(long[] Qi : Q) {
            long tmp = 0;
            for(long[] Pi: P) {
                long pyt = pythagoreanTheorem(Qi[0]-Pi[0], Qi[1]-Pi[1]);
                tmp = Math.max(pyt, tmp);
            }
            res = Math.max(res,tmp);
        }
        bw.write(res+"");
        bw.flush();
    }
    static long pythagoreanTheorem(long a, long b) {
        return a*a + b*b;
    }
    static long[] parsePairs(BufferedReader br) throws IOException {
        return Stream.of(br.readLine().split(" ")).mapToLong(Long::parseLong).toArray();
    }
}

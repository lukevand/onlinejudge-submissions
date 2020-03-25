import java.io.*;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

        String line = in.readLine();
        while (line.charAt(0) != '0') {
            BigInteger n = new BigInteger(line);
            BigInteger d = n.mod(BigInteger.valueOf(10));
            BigInteger remainingInt = n.divide(BigInteger.valueOf(10));
            BigInteger subbed = remainingInt.subtract(BigInteger.valueOf(5).multiply(d));
            if (subbed.mod(BigInteger.valueOf(17)).equals(BigInteger.ZERO)) {
                out.write('1');
            } else {
                out.write('0');
            }
            out.newLine();

            line = in.readLine();
        }
        out.flush();
    }
}

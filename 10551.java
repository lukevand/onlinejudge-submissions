import java.io.*;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

        String line = in.readLine();
        while (!line.equals("0")) {
            line = line.trim();
            String[] tmp = line.split(" +");
            int b = Integer.parseInt(tmp[0]);
            BigInteger p = new BigInteger(tmp[1], b);
            BigInteger m = new BigInteger(tmp[2], b);
            BigInteger result = p.mod(m);
            out.write(result.toString(b));
            out.newLine();
            line = in.readLine();
        }
        out.flush();
    }
}

import java.io.*;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

        String line = in.readLine();
        while (line != null) {
            line = line.trim();
            String[] tmp = line.split(" +");
            String x = tmp[0].trim();
            int baseFrom = Integer.parseInt(tmp[1]);
            int baseTo = Integer.parseInt(tmp[2]);
            BigInteger b = new BigInteger(x, baseFrom);
            String result = b.toString(baseTo).toUpperCase();
            if (result.length() > 7) {
                result = "ERROR";
            }
            out.write(String.format("%7s\n", result));
            line = in.readLine();
        }
        out.flush();

    }

}

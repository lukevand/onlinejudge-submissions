import java.io.*;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

        try {
            String line = in.readLine();
            while (line != null) {
                line = line.trim();
                String[] tmp = line.split(" +");
                String x = tmp[0].trim();
                String y = tmp[1].trim();
                boolean done = false;
                for (int i=2; i<=36 && !done; i++) {
                    for (int j=2; j<=36; j++) {
                        try {
                            if ((new BigInteger(x, i)).equals((new BigInteger(y, j)))) {
                                out.write(String.format("%s (base %d) = %s (base %d)\n", x, i, y, j));
                                done = true;
                                break;
                            }
                        } catch (NumberFormatException e) {};
                    }
                }

                if (!done) {
                    out.write(String.format("%s is not equal to %s in any base 2..36\n", x, y));
                }

                line = in.readLine();
            }
        } catch (IOException e) {
        } finally {
            out.flush();
        }

    }

}

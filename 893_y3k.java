import java.text.MessageFormat;
import java.text.SimpleDateFormat;
import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] line = in.readLine().split(" ");
        SimpleDateFormat format = new SimpleDateFormat("d M yyyy");
        while (true) {
            int days = Integer.parseInt(line[0]);
            int d = Integer.parseInt(line[1]);
            int m = Integer.parseInt(line[2]);
            int y = Integer.parseInt(line[3]);
            if (y == 0) {
                break;
            }
            Calendar date = new GregorianCalendar(y, m-1, d);
            date.add(Calendar.DAY_OF_MONTH, days);
            out.write(format.format(date.getTime())); out.write("\n");
            line = in.readLine().split(" ");
        }


        in.close();
        out.close();
    }
}


/**
 * Created by rtdimpsey and lcoseo on 4/13/17 and 4/20/22.
 */
import java.net.*;
import java.io.*;

public class DateServer
{
    public class Worker implements Runnable
    {
        Socket cl;

        public Worker(Socket client) {
            cl = client;
        }

        public void run()
        {
            while (true)
            {
                try {
                    PrintWriter pout = new PrintWriter(cl.getOutputStream(), true);
                    pout.println(new java.util.Date().toString());
                    cl.close();
                } catch (IOException ioe) {}

            }
        }
    }

    public static void main(String[] args)
    {
        try
        {
            ServerSocket sock = new ServerSocket(6013);

            while (true)
            {
                Socket client = sock.accept();
                Thread worker = new Thread(new DateServer().new Worker(client));
                worker.start();
            }
        }
        catch (IOException ie) {}
    }
}


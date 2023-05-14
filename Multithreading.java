import java.lang.*;
import java.util.*;

class Movie extends Thread {
    int tickets = 2, reqd;
    Movie(int x) {
        reqd =  x;
    }
    public synchronized void run() {
        if (reqd <= tickets) {
            System.out.println("Tickets booked for "+Thread.currentThread().getName());
            try {
                Thread.sleep(100);
            }
            catch (Exception e) {
                System.out.println(e);
            }   
            tickets -= reqd;
        }
        else {
            System.out.println("Sorry, Housefull "+Thread.currentThread().getName());
        }
    }
}

class Main {
    public static void main(String z[]) {
        Movie m = new Movie(1);
        Thread t1 = new Thread(m);
        Thread t2 = new Thread(m);
        Thread t3 = new Thread(m);
        t1.setName("Customer1");
        t2.setName("Customer2");
        t3.setName("Customer3");
        t1.start();
        t2.start();
        t3.start();
        
    }    
}

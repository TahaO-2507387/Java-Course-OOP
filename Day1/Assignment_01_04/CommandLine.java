package Day1.Assignment_01_04;

public class CommandLine {
    public static void main(String[] args) {
        if (args.length < 3) {
            System.out.println("There aren't enough arguments."); // als we niet genoeg argumenten hebben printen we wat
                                                                  // we hebben
            for (int i = 0; i < args.length; i++) {
                System.out.println(i + ": " + args[i]);
            }
        }
        // anders printen we de eerste 3
        else {
            System.out.println("First: " + args[0]);
            System.out.println("Second: " + args[1]);
            System.out.println("Third: " + args[2]);
        }

    }
}

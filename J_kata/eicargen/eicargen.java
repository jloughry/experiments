// eicargen: this programme will set off your antivirus defences!

// Usage: java eicargen [command [filename]]

// If run with no arguments, does nothing. If run with the argument
// "write" (optionally followed by a filename), it'll write a small
// binary file in the current directory called "eicar.com" (or whatever
// filename you specified). No particular protection against overwriting
// the target file is provided. The binary file is a harmless MS-DOS
// executable called the EICAR Standard Anti-Virus Test File. It is
// intended to set off anti-virus alarms but otherwise is harmless. All
// anti-virus defences should detect it.

// Credit: this is my own implementation after an original idea by Didier
// Stevens of Microsoft.

import java.io.DataOutputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class eicargen {
	public static void main(String[] argv) {
        String programme_name = System.getProperty("sun.java.command").split(" ")[0];
        String command = "";
        String filename = "";

        switch (argv.length) {
            case 1:
                command = argv[0];
                filename = "eicar.com";
                break;
            case 2:
                command = argv[0];
                filename = argv[1];
                break;
            default:
                System.out.println("Usage: java " + programme_name + " [command [filename]]");
                System.exit(1);
                break;
        }

        if (command.equals("write")) {
            try {
                DataOutputStream os = new DataOutputStream(new FileOutputStream(filename));
                try {
                    os.writeBytes(obfuscated_data());
                    os.close();
                } catch(IOException ioe) {
                    System.out.println(ioe.getMessage());
                }
            } catch(FileNotFoundException fnfe) {
                System.out.println(fnfe.getMessage());
            }
        }
    }

    // This is the EICAR Standard Anti-Virus Test File in slightly
    // scrambled form, for the purpose of evading detection by anti-virus
    // scanners. If it got detected and quarantined, this programme wouldn't
    // be very useful, would it?

    static public String obfuscated_data() {
        String c = "4\\PZ";
        String e = "^)7CC";
        double pi = 3.14159265; // This is only here for obfuscation.
        String m = "ILE!$";
        String f = ")7}$E";
        String b = "%@AP[";
        String d = "X54(P";
        String a = "X5O!P";
        String h = "STAND";
        Boolean this_is_only_here_to_break_up_the_data_segment;
        String i = "ARD-A";
        String g = "ICAR-";
        String k = "RUS-T";
        String j = "NTIVI";
        String n = "H+H*";
        String l = "EST-F";

        return a+b+c+d+e+f+g+h+i+j+k+l+m+n;
    }
}


public class eicargen {
	public static void main(String[] argv) {
        String programme_name = System.getProperty("sun.java.command").split(" ")[0];
        String argument = "";

        switch (argv.length) {
            case 1:
                argument = argv[0];
                break;
            default:
                System.out.println("Usage: java " + programme_name + " [arg]");
                System.exit(1);
                break;
        }

        if (argument == "write") {
            System.out.println("obfuscated_data = \"" + obfuscated_data() + "\"");
        }
    }

    static public String obfuscated_data() {
        String c = "4\\PZ";
        String e = "^)7CC";
        double pi = 3.14159;
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


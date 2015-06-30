public class eicargen {
	public static void main(String[] argv) {
        String programme_name = System.getProperty("sun.java.command").split(" ")[0];
        String argument = "";
        String secret_string;

        switch (argv.length) {
            case 1:
                argument = argv[0];
                break;
            default:
                System.out.println("Usage: java " + programme_name + " [arg]");
                System.exit(1);
                break;
        }

        System.out.println("argument = \"" + argument + "\"");
    }
}

/*

static public String obfuscated_data() {
    String j = "$EI";
    String n = "ARD";
    String f = "54(";
    String p = "TIV";
    String u = "LE!";
    String b = "!P%";
    String t = "-FI";
    String v = "$H+";
    String l = "-ST";
    String w = "H*";
    String d = "[4\";
    String i = ")7}";
    String c = "@AP";
    String m = "AND";
    String o = "-AN";
    String h = "7CC";
    String a = "X5O";
    String q = "IRU";
    String g = "P^)";
    String r = "S-T";
    String s = "EST";
    String e = "PZX";
    String k = "CAR";

    return a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q+r+s+t+u+v;
}

*/

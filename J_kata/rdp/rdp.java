public class rdp {
	public static void main(String[] argv) {
		String programme_name = System.getProperty("sun.java.command").split(" ")[0];
		String input_filename = "";

		switch(argv.length) {
			case 1:
				input_filename = argv[0];
				break;
			default:
				System.out.println("Usage: java " + programme_name + " [file]");
				System.exit(1);
				break;
		}
		System.out.println("input_filename = \"" + input_filename + "\"");
	}
}


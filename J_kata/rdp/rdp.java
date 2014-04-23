public class rdp {
	static public void main(String[] argv) {
		String programme_name = System.getProperty("sun.java.command").split(" ")[0];
		String input_filename = "";
		char c = 'A';

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
		prompt();
		System.out.println();
		System.out.println("Bye.");
	}

	static public void prompt() {
		System.out.print("> ");
	}

	// returns true if c is allowed to start a Scheme identifier

	static public boolean is_identifier_initial(char c) {
		if (Character.isLetter(c) || Character.isDigit(c)
			|| '!' == c || '$' == c || '%' == c || '&' == c || '*' == c
			|| '/' == c || ':' == c || '<' == c || '=' == c || '>' == c
			|| '?' == c || '~' == c || '_' == c || '^' == c) {
			return true;
		}
		return false;
	}

	// returns true if c is one of the other characters allowed in a Scheme identifier

	public boolean is_identifier_subsequent(char c) {
		if (is_identifier_initial(c) || Character.isDigit(c)
			|| '.' == c || '+' == c || '-' == c) {
			return true;
		}
		return false;
	}
}


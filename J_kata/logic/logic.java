public class logic {
	static public void main(String[] args) {

		System.out.println("First version: if (a) then b; if (c) then d;");
		if (a()) {
			b();
		}
		if (c()) {
			d();
		}

		System.out.println("Second version: if (a) then b; else if (c) then d;");
		if (a()) {
			b();
		} else if (c()) {
			d();
		}

		System.out.println("Bye.");
	}

	static public boolean a() {
		System.out.println("a is true");
		return true;
	}

	static public boolean b() {
		System.out.println("b is true");
		return true;
	}

	static public boolean c() {
		System.out.println("c is true");
		return true;
	}

	static public boolean d() {
		System.out.println("d is true");
		return true;
	}
}


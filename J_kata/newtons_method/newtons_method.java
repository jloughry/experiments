public class newtons_method {
	static public void main(String[] args) {
		double n = 443556;
		double guess = 10; // The initial guess must be > 0.

		do {
			guess = (guess + n / guess) / 2;
		} while (Math.abs(n - (guess * guess)) > 1e-9);

		System.out.println("The square root of " + n + " is " + guess + "\n");
	}
}


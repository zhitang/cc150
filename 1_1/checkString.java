public class checkString {
    public static final int CHARSET_SIZE = 256;
    public static boolean hasAllUniqueChars(String s) {

	return true;
    }
    
    public static void main(String [] args) {
	String [] test_strings = {"adslfjf", "all;ljl;13e43", "  aldfa adfl"};
	for (String s : test_strings) {
	    System.out.println("The string " + s + " has " + (hasAllUniqueChars(s) ? "unique" : "duplicate") + " characters.");
	}
    }
}
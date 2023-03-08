public class ZeroException extends Exception {
    public ZeroException() {
	super("ZeroException: Argument cannot be negative.");
    }
    
    public ZeroException(String message) {
        super(message);
    }
}

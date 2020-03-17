public class InterpretException extends Exception
{
    /**
     * Identificador de serialização da classe
     */
    private static final long serialVersionUID = 1L;
    
    /**
     * Constructs a new InterpretException with null as its detail message
     */
    public InterpretException()
    {
        super();
    }
    
    /**
     * Constructs a new InterpretException with the specified detail message
     *
     * @param message the detail message
     */
    public InterpretException(String message)
    {
        super(message);
    }
    
    /**
     * Constructs a new InterpretException with the specified detail message
     * and cause
     *
     * @param message the detail message
     * @param cause the cause
     */
    public InterpretException(String message, Throwable cause)
    {
        super(message, cause);
    }
    
    /**
     * Constructs a new InterpretException with the specified cause and a
     * detail message of (cause==null ? null : cause.toString())
     * (which typically contains the class and detail message of cause)
     *
     * @param cause the cause
     */
    public InterpretException(Throwable cause)
    {
        super(cause);
    }
}

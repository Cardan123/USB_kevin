public class LoadException extends Exception
{
    /**
     * Identificador de serialização da classe
     */
    private static final long serialVersionUID = 1L;
    
    /**
     * Constructs a new LoadException with null as its detail message
     */
    public LoadException()
    {
        super();
    }
    
    /**
     * Constructs a new LoadException with the specified detail message
     *
     * @param message the detail message
     */
    public LoadException(String message)
    {
        super(message);
    }
    
    /**
     * Constructs a new LoadException with the specified detail message and
     * cause
     *
     * @param message the detail message
     * @param cause the cause
     */
    public LoadException(String message, Throwable cause)
    {
        super(message, cause);
    }
    
    /**
     * Constructs a new LoadException with the specified cause and a detail
     * message of (cause==null ? null : cause.toString())
     * (which typically contains the class and detail message of cause)
     *
     * @param cause the cause
     */
    public LoadException(Throwable cause)
    {
        super(cause);
    }
}

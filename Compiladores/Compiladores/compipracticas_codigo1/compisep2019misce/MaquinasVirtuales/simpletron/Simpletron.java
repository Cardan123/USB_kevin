import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Scanner;
import java.util.HashMap;
import java.util.*;

public class Simpletron {
   public static final int MEMORY = 100;
   public static final int READ = 10;
   public static final int WRITE = 11;
   public static final int LOAD = 20;
   public static final int STORE = 21;
   public static final int ADD = 30;
   public static final int SUBTRACT = 31;
   public static final int DIVIDE = 32;
   public static final int MULTIPLY = 33;
   public static final int INC = 34;
   public static final int DEC = 35;
   public static final int BRANCH = 40;
   public static final int BRANCHNEG = 41;
   public static final int BRANCHZERO = 42;
   public static final int BRANCHGTZERO = 43;
   public static final int HALT = 44;
    
   private static HashMap<Integer, String> opMap = new HashMap<Integer, String>(){{
    put(READ, "read");
    put(WRITE, "write");
    put(LOAD, "load");
    put(STORE, "store");
    put(INC, "inc");
    put(DEC, "dec");
    put(ADD, "add");
    put(SUBTRACT, "sub");
    put(DIVIDE, "div");
    put(MULTIPLY, "mul");
    put(BRANCH, "branch");
    put(BRANCHNEG, "branchneg");
    put(BRANCHZERO, "branchzero");
    put(BRANCHGTZERO, "branchgtzero");
    put(HALT, "halt");
}};

   private final DecimalFormat memoryFormatter;
   ArrayList<Integer> memory;
   private int pc;
   private int operationCode;
   private int operand;
   private Scanner scanner;
   private boolean processing;
   static Stack pila;
   int cta=0;
   public static String opEncode(int opcode){
      if(opMap.containsKey(opcode)){
      return opMap.get(opcode);
      }
      return null;
   }
   public Simpletron(){
      processing = false;
      memory = new ArrayList<Integer>();
      pc = 0;
      operationCode = 0;
      operand = 0;
      scanner = new Scanner(System.in);
      memoryFormatter = new DecimalFormat("+0000;-0000");
   }
   private void loadFile() throws LoadException {
        BufferedReader lector = null;
        System.out.print("Please enter your file program: ");
        String source = scanner.nextLine();
        try {
            lector = new BufferedReader(new FileReader(source));
            String line = lector.readLine();
            System.out.println(line);
            int counter = 0;
            while(line != null){
                int word = Integer.parseInt(line);
                System.out.println("word <"+word+">");
                if((word >= -9999) && (word <= 9999)){
                    memory.add(new Integer(word));
                    counter = counter + 1;
                } else {
                    throw new NumberFormatException();
                }
                line = lector.readLine();
            }
        } catch(FileNotFoundException exception){
            throw new LoadException("error : attempt to file not found!", exception);
        } catch(IOException exception){
            throw new LoadException("error : attempt to invalid file!", exception);
        } catch(NumberFormatException exception){
            throw new LoadException("error : attempt to invalid instruction!", exception);
        } finally {
            try{ lector.close(); }
            catch(IOException exception){
                /* nothing to do*/
            }
        }
        System.out.println("Simpletron loading completed!");
   }
   public void read() {
        //cta=cta+1;
        //System.out.print("input  "+cta+" operand "+operand+" ;");
        int number = 0;
        try{
            number = Integer.parseInt(scanner.nextLine());
        } catch(NumberFormatException exception){
            number = Integer.MIN_VALUE;
        }
        if((number >= -9999) && (number <= 9999)){
            pila.push(new Double(number));
        } else {
            System.out.println("error : attempt to invalid number!");
        }
   }
   public void write(){
        System.out.print("output: ");
        //System.out.println(memoryFormatter.format(memory[operand]));
        Double d;
        d=(Double)pila.pop();
        System.out.print("["+d.doubleValue()+"]");
        pila.push(d);
   }
   public void load(){
      pila.push(new Double(memory.get(operand)));
      //pc = pc + 1;
   }
   public void store(){
      double d1;
      d1=((Double)pila.pop()).doubleValue();
      memory.add(operand, new Integer((int)d1));
      //pc = pc + 1;
   }
   public void inc(){
      double d1;
      d1=((Double)pila.pop()).doubleValue();
      d1+=1;
      pila.push(new Double(d1));
   }
   public void dec(){
      double d1;
      d1=((Double)pila.pop()).doubleValue();
      d1-=1;
      pila.push(new Double(d1));
   }
   public void add(){
       double d1, d2;
       d2=((Double)pila.pop()).doubleValue();
       d1=((Double)pila.pop()).doubleValue();
       d1+=d2;
       pila.push(new Double(d1));
   }
   public void sub(){
      double d1, d2;
      d2=((Double)pila.pop()).doubleValue();
      d1=((Double)pila.pop()).doubleValue();
      d1-=d2;
      pila.push(new Double(d1));
   }
   public void mul(){
      double d1, d2;
      d2=((Double)pila.pop()).doubleValue();
      d1=((Double)pila.pop()).doubleValue();
      d1*=d2;
      pila.push(new Double(d1));
   }
   public void div(){
      double d1, d2;
      d2=((Double)pila.pop()).doubleValue();
      d1=((Double)pila.pop()).doubleValue();
      d1/=d2;
      pila.push(new Double(d1));
   }
    public void branch(){ pc = operand-1; }
    public void branchneg(){
      double d1=0;
      d1=((Double)pila.pop()).doubleValue();
        if(d1 < 0){
            pc = operand-1;
        } //else { pc = pc + 1; }
    }
    public void branchzero(){
       double d1=0;
       d1=((Double)pila.pop()).doubleValue();
        if(d1 == 0){
            pc = operand-1;
        } //else { pc = pc + 1; }
    }
   public void branchgtzero(){
      double d1=0;
      d1=((Double)pila.pop()).doubleValue();
      if(d1 >= 0){
         //System.out.println(" if d1 =< "+d1+" >");
         pc = operand-1;
      } //else { pc = pc + 1; }
      pila.push(new Double(d1));
   }
    public void halt(){ processing = false; }
    private void interpret() throws InterpretException {
        System.out.println("Simpletron execution begins!");
        processing = true;
        while(processing){
            int instructionRegister = ((Integer)memory.get(pc)).intValue();
            operationCode = instructionRegister / 100;
            operand = instructionRegister % 100;
            String inst = opEncode(operationCode);
            if(inst==null)
               throw new InterpretException("error : attempt to unknown instruction!");
            else {
              UtilReflect.ejecutaMetodo(this, inst);
              pc=pc+1;
            }
        }
        System.out.println("Simpletron execution terminated!");
    }
    private void dump(){
       String temp;
        DecimalFormat variableFormatter = new DecimalFormat("   00");
        System.out.println();
        System.out.println("REGISTERS:");
        temp = variableFormatter.format(pc);
        System.out.println(temp + " Instruction Counter");
        temp = memoryFormatter.format(memory.get(memory.size()-2));
        System.out.println(temp + " Instruction Register");
        temp = variableFormatter.format(operationCode);
        System.out.println(temp + " Operation Code");
        temp = variableFormatter.format(operand);
        System.out.println(temp + " Operand");
        System.out.println();
        System.out.println("MEMORY:");
        System.out.print(" ");
        for(int i = 0; i < 10; i++){
            System.out.print("     " + i);
        }
        System.out.println();
        for(int i = 0; i < memory.size(); i += 1){
           if(i% 10 == 0) System.out.print((i / 10) + " ");
           System.out.print(memoryFormatter.format(memory.get(i)) + " ");
           if(i% 10 == 0 && i!=0) System.out.println();
        }
        System.out.println();
    }
    public void execute(){
        System.out.println("Welcome to Simpletron!");
        try{ loadFile(); interpret(); }
        catch(Exception exception){
            System.out.println(exception.getMessage());
            System.out.println("Simpletron execution abnormally terminated!");
        }
        finally {  dump(); }
    }
    public static void main(String[] args){
        Simpletron simpletron = new Simpletron();
        pila=new Stack();
        simpletron.execute();
    }
}

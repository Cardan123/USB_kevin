import java.awt.*;
import java.lang.reflect.*;
class CProcessor  {  
   public static final int NumTeams = 2;
   public static final int MaxProcessesPerTeam = 64;  
   public static final int OFF =0, ON=1;
   public static final int RED =0, BLUE=1;   
   public static final int DAT = 0, MOV = 1, ADD = 2, SUB = 3, JMP = 4, 
    JMZ = 5, JMN = 6, DJN = 7, CMP = 8, SPL = 9, ORG= 10, END = 11;
    public static final int IMMEDIATE = 0, DIRECT = 1, INDIRECT = 2, 
    AUTODECREMENT = 3;                               
   public CProcessor(Core c){
      Core = c ;
      StackPointer[RED] = -1; ProcessCounter[RED] = 0;
      StackPointer[BLUE] = -1; ProcessCounter[BLUE] = 0;
    }
    // Processor Flags            
    private int ErrorFlag;   // ON or OFF
    private int JumpFlag;  
    private int TeamFlag;  // RED or BLUE
    // REGISTERS    
    // Instruction Pointer
    private int IP;           
    // Instruction Register
    private CoreWord IR;
    // Extra Work Register
    private CoreWord X;                            
    // IP Stack Pointers
    private int IP_stacks[][] = new int[NumTeams][MaxProcessesPerTeam];
    // IP Stack Pointers                  
    private byte StackPointer[] = new byte[NumTeams];  
    // Process Counters
    private byte ProcessCounter[] = new byte[NumTeams];
    // INSTRUCTION POINTER STACKS
   private void IncrementIPStack(){
      if(++(StackPointer[TeamFlag]) >= ProcessCounter[TeamFlag]){
        StackPointer[TeamFlag] = 0;
      }
   }
   private void ResetIPStacks(){
      StackPointer[RED] = -1; ProcessCounter[RED] = 0;
      StackPointer[BLUE] = -1; ProcessCounter[BLUE] = 0;
   }
   private void InsertProcess(int NewIP){                           
    // If this is the last process, simply add the new process behind it
    if(StackPointer[TeamFlag]+1 == ProcessCounter[TeamFlag]){
        IP_stacks[TeamFlag][StackPointer[TeamFlag]+1] = NewIP; // insert the IP
        ProcessCounter[TeamFlag]++;    // increment process counter
        }
    else {                                                             
        for(int w=ProcessCounter[TeamFlag]; w > StackPointer[TeamFlag]+1; w--)
            IP_stacks[TeamFlag][w] = IP_stacks[TeamFlag][w-1];
        IP_stacks[TeamFlag][StackPointer[TeamFlag]+1] = NewIP;   // insert the IP
        ProcessCounter[TeamFlag]++;                             // increment process counter
        }
    }                                                        
   private void RemoveProcess(int IP){         
    // If this is the last process, simply remove it
    if(StackPointer[TeamFlag]+1 == ProcessCounter[TeamFlag]){
        ProcessCounter[TeamFlag]--;    // deccrement process counter
        }
    else {                                                             
        for(int w=StackPointer[TeamFlag]; w < ProcessCounter[TeamFlag]-1; w++)
            IP_stacks[TeamFlag][w] = IP_stacks[TeamFlag][w+1];
        ProcessCounter[TeamFlag]--;    // decrement process counter
        }
    }
    // BUSES
   /*private int AddressBus;//ap
   private CoreWord DataBus;//ap */  
   public int AddressBus;//ap
   public CoreWord DataBus;          
   private Core Core;  //ap       
    // REGISTER OPERATORS    
    // Move data to and from the busses    
   private void LoadIRfromBus(){
     IR = new CoreWord(DataBus);//clonar
     System.err.println("LoadIRfromBus core IR "+IR);
   }                                                      
// Put the data in the IR onto the data bus 
   private void PutIRonBus(){
     DataBus = new CoreWord(IR);
     Core.setDB (DataBus);
   }
    // Move instruction pointers to and from the internal stack  
   private void FetchIP(){   
    IP = IP_stacks[TeamFlag][ StackPointer[TeamFlag] ];
    System.err.println("FetchIP IP= < "+ IP +" > Team= < "+TeamFlag+" >");
    }                                                                          
// Put the instruction pointer on the current IP stack
   private void PutIP(){   
    IP_stacks[TeamFlag][ StackPointer[TeamFlag] ] = IP;
    }    
   // Swap the IR with the X register     
   private void SwapX(){
      CoreWord TempWord;                          
      TempWord = X; X = IR; IR = TempWord;
   }  
// Decode all address operands to their ABSOLUTE values                    
   private int DecodeOperand(short Mode, int Operand, int IP){       
      int NewOperand=-1;    // Holds the new operand to be returned
      int Pointer =0;    // Points to address for indirect addressing modes
      switch(Mode){                  
         // If the mode is IMMEDIATE, operand is unchanged
         case IMMEDIATE:
            System.out.println("DecodeOperand IMMEDIATE");
            NewOperand = Operand;
            System.out.println(
                             "DecodeOperand IMMEDIATE NewOperand"+ NewOperand);
            break;
         // If the mode is direct, operand is an address            
         case DIRECT:
            System.out.println("DecodeOperand DIRECT");
            NewOperand = (( Operand + IP ) % Core.CoreSize);
            System.out.println("DecodeOperand DIRECT NewOperand"+ NewOperand);
            break;   
         case INDIRECT:
            System.out.println("DecodeOperand INDIRECT");
            SwapX();    // Swap the IR and the X register
            // Load the new word from memory
            Pointer = ( Operand + IP ) % Core.CoreSize;  // Get pointer to address
            System.out.println("DecodeOperand Pointer ="+Pointer);
            AddressBus = Pointer;     // Place this addr on the bus
            Core.setAB(AddressBus);
            Core.ReadWord();   // strobe memory
            LoadIRfromBus();    // Load data from the data bus to IR   
            // Use this decremented pointer to compute the operand
            NewOperand = (Pointer + IR.OperandB) % Core.CoreSize;
            System.out.println("DecodeOperand IR = "+IR+
            " NewOperand = "+ NewOperand);
            // Put the original Instruction back where it belongs
            SwapX();            
            break;
// If the mode is indirect, operand is the address OF the address               
         case AUTODECREMENT:
            SwapX();    // Swap the IR and the X register
            // Load the new word from memory
            Pointer = ( Operand + IP ) % Core.CoreSize; // Get pointer to address
            AddressBus = Pointer; // Place this addr on the bus
            Core.ReadWord();  // strobe memory
            LoadIRfromBus();   // Load data from the data bus to IR      
            // Decrement the actual addressGet the actual address
            --IR.OperandB;      // Decrement the B Operand (our address)
            PutIRonBus();       // Put this back on the data bus
            Core.WriteWord();  // Tell Core to write the decremented word back to memory             
            // Use this decremented pointer to compute the operand
            NewOperand = (Pointer + IR.OperandB) % Core.CoreSize; 
            // Put the original Instruction back where it belongs
            SwapX();                                               
         break;      
      }     
      // return the new operand          
      return(NewOperand);
   }
    //  FETCH, DECODE AND EXECUTE
    private void Fetch(){               
     // Place the IP on the address bus
      System.out.println("Fetch Fetch IP = < "+IP+" >");
       AddressBus = IP;       
     System.out.println("Fetch Fetch AddressBus = < "+AddressBus+" >");                 
     // Tell Memory to do its stuff
       Core.setAB(AddressBus); 
       Core.ReadWord();     
     // Load the IR from the data bus
       LoadIRfromBus();
    }
    private void Decode(){
     System.out.println("Decode IR "+IR+" IP = "+IP);
     IR.OperandA = DecodeOperand(IR.ModeA, IR.OperandA, IP);
     IR.OperandB = DecodeOperand(IR.ModeB, IR.OperandB, IP);
    }
    private void Execute(){
        String inst;
        Method metodo;
        ErrorFlag = OFF;
        JumpFlag = OFF;
        System.out.println("1Execute IR.OpCode "+IR.OpCode);
        System.out.println("2Execute IR.OpCode "+
                           RA.OpCodeSymbols[IR.OpCode >> (2*2)]+" val "+(IR.OpCode >>4));
        inst= RA.OpCodeSymbols[IR.OpCode >> (2*2)].toLowerCase() ;
        if( IR.OpCode >>4 == DAT){
            ErrorFlag = ON;
            return;
        }
        try {
            System.out.println(" instr "+inst);
            metodo=this.getClass().getDeclaredMethod(inst, null);
            metodo.invoke(this, null);
        } catch(NoSuchMethodException e){
            System.out.println(" No metodo "+e);
        } catch(InvocationTargetException e){
            System.out.println(" inst = "+inst+"  "+e);
        } catch(IllegalAccessException e){
            System.out.println(e);
        }
    }
     // The Core War instructions
   private void mov(){
      System.out.println("MOVMOV");
      if(IR.ModeA == IMMEDIATE){
         // Put B operand on address bus
         AddressBus = IR.OperandB; 
         // Move the value to the data field             
         IR.OperandB = IR.OperandA;                      
         // Put IR on data bus
         PutIRonBus(); 
         // Tell Core to write B operand to memory
         Core.WriteOperandB();
      } else {       
         // Place the word at location A on the data bus
         AddressBus = IR.OperandA;
         Core.setAB(AddressBus);
         Core.ReadWord();
         // Write that word (from the data bus) to location B
         System.out.println("MOVMOV IR ="+IR);
         AddressBus = IR.OperandB;
         Core.setAB(AddressBus);
         Core.WriteWord();
      }        
   }                                     
   private void add(){
    // effects only B operand
    System.out.println("addADDADD");
    if(IR.ModeA == IMMEDIATE){
        // Get the word pointed to by the B Operand
        AddressBus = IR.OperandB;
        Core.setAB(IR.OperandB);
        Core.ReadWord();                                
        // Fetch the B operand of that word and add it to the A operand of the IR                                                   
        IR.OperandB = DataBus.OperandB + IR.OperandA;
        System.out.println("ADD IR "+IR);
        PutIRonBus();
        Core.WriteOperandB();
        }
    else {               
        // Save IR
        SwapX();
        // Get the word pointed to by the A Operand and load it into the IR
        AddressBus = X.OperandA;
        Core.ReadWord();
        LoadIRfromBus();                                         
        // Place the Word pointed to by the B Operand on the data bus
        AddressBus = X.OperandB;
        Core.ReadWord();                                                      
        // Add Operand B from the data bus (field B) to Operand B in IR (Field A)
        IR.OperandB += DataBus.OperandB;
        PutIRonBus();                                                 
        // Write OperandB to word pointed to by B field (still on bus)
        Core.WriteOperandB();
        // Restore the IR        
        SwapX();
        }        
    }            
   private void sub(){
      // effects only B operand
      if(IR.ModeA == IMMEDIATE){
        // Get the word pointed to by the B Operand
        AddressBus = IR.OperandB;
        Core.ReadWord();                                           
        // Fetch the B operand of that word and add it to the A operand of the IR                                                   
        IR.OperandB = 
        (DataBus.OperandB - IR.OperandA + Core.CoreSize) % Core.CoreSize;
        
        PutIRonBus();
        Core.WriteOperandB();
        }
    else {               
        // Save IR
        SwapX();
        // Get the word pointed to by the A Operand and load it into the IR
        AddressBus = X.OperandA;
        Core.ReadWord();
        LoadIRfromBus();                                                       
        // Place the Word pointed to by the B Operand on the data bus
        AddressBus = X.OperandB;
        Core.ReadWord();                                       
        // Add Operand B from the data bus (field B) to Operand B in IR (Field A)
        IR.OperandB = 
        (DataBus.OperandB - IR.OperandB + Core.CoreSize) % Core.CoreSize;
        PutIRonBus();                                                        
        // Write OperandB to word pointed to by B field (still on bus)
        Core.WriteOperandB();
        // Restore the IR        
        SwapX();
        }          
    }         
   private void jmp(){ // unconditional jump
           //IP=IP+IR.OperandA;
           System.out.println("JMPJMP IP  = "+IP);
           JumpFlag = ON; }    
   private void jmz(){    // jump if zero       
      //if b is IMMEDIATE and .OperandB == 0, then jump
      if(IR.ModeB == IMMEDIATE){
         if(IR.OperandB == 0)
            JumpFlag = ON;
      }            
      else {    //else B is an address            
        // Place address on the bus and strobe memory
         AddressBus = IR.OperandB;
         Core.ReadWord(); 
         if(DataBus.OperandB == 0)
            JumpFlag = ON;
      }            
   }       
   private void jmn(){ // jump if not zero
      //if b is IMMEDIATE and .OperandB != 0, then jump
      if(IR.ModeB == IMMEDIATE){
        if(IR.OperandB != 0)
            JumpFlag = ON;
      } else {   //else B is an address             
        // Place address on the bus and strobe memory
         AddressBus = IR.OperandB;
         Core.ReadWord();
         if(DataBus.OperandB != 0)
            JumpFlag = ON;
      }            
   }                                 
   private void djn(){ // decrement and jump if not zero
      //if b is IMMEDIATE and .OperandB != 0, then jump
      if(IR.ModeB == IMMEDIATE){
         if(--IR.OperandB != 0)
            JumpFlag = ON;
      }                    
      else {   //else B is an address             
        // Get the word pointed to by B
         AddressBus = IR.OperandB;
         Core.ReadWord();
         // Decrement the B field
         if(--(DataBus.OperandB) !=0)
            JumpFlag = ON;   
        // Value on the data bus has been decremented.  Write it back to Core.
         Core.WriteWord();
      }            
    }                                 
   private void cmp(){  // A cannot be IMMEDIATE                      
      if(IR.ModeA == IMMEDIATE){
         ErrorFlag = ON;
         return;
      }                       
      // A will always be an address                             
      AddressBus = IR.OperandA;
      Core.ReadWord();
      if(IR.ModeB == IMMEDIATE){                   
        if(DataBus.OperandB == IR.OperandB)
            IP++;
      }                   
      // Operand B is ALSO an address            
      else {                         
         SwapX();    // Save the IR
         LoadIRfromBus(); // Load the first word (A) into IR
         // Get the second word (B) on the bus                                                              
         AddressBus = X.OperandB;
         Core.ReadWord();                       
         // compare the entire Core Words against each other
         if(DataBus.equals(IR)){  // 0 is equal
            IP++;
         }        
         SwapX();    // Restore the IR
      }
   }                                  
   private void spl(){   // split a child process   
      // IMMEDIATE is an error
      if(IR.ModeB == IMMEDIATE){
         ErrorFlag = ON;
         return;
      }  
      // check that we can spl again.
      if(ProcessCounter[TeamFlag] < MaxProcessesPerTeam){
        InsertProcess(IR.OperandB);
      }
   }                                 
    // Set pointers to stack, busses, etc.           
   public void Reset(int pAddressBus, CoreWord pDataBus, 
                                    int RedIP, int BlueIP, 
                                    Core pCore){
     // Set pointers to busses
      AddressBus = pAddressBus;
      DataBus = pDataBus;
      // Set pointer to core
      Core = pCore;                      
      // Clear the instruction pointer stacks and stack pointers     
      ResetIPStacks();                              
      // Set the process Counters to zero
      ProcessCounter[RED] = 0;
      ProcessCounter[BLUE] = 0;             
      // Install the starting instruction pointers for both teams
      TeamFlag = BLUE;
      InsertProcess(BlueIP);
      TeamFlag = RED;                        
      InsertProcess(RedIP);
   }               
   // On receiving a signal from the Clock_In line 
   public void Cycle(/*Graphics g*/){           
    // SET PROCESSOR FLAGS
    // Flip the bit which tells who's turn it is;
    System.out.println("11CycleCCCCProcesor team = < "+TeamFlag+" >");
    if (TeamFlag == BLUE)
        TeamFlag = RED;
    else
        TeamFlag = BLUE; 
    System.out.println("22CycleCCCCProcesor team = < "+TeamFlag+" >");           
    ErrorFlag = OFF;
    JumpFlag = OFF;
    // GET (this task's) IP FROM THE STACK                
    // increment the appropriate IP stack
    IncrementIPStack();
    // Get the appropriate IP off of the current stack
    FetchIP();                                            
    //  RUN THE INSTRUCTION                             
    Fetch();  
    System.out.println("Decode");
    Decode();
    Execute();
    // Was there an error?                                       
    if(ErrorFlag == ON){
        RemoveProcess(IP);
        if(ProcessCounter[TeamFlag]==0){     
            return;
        }
     }
    // HANDLE THE JUMP (if any)                         
    // If we are to jump, place new address in IP             
    if (JumpFlag == ON){
        //IP = IR.OperandA;
        System.err.println("CCicle JumpFlag = ON IP= <"+ IP +" >");
        IP=IP+IR.OperandA;
        System.err.println(
        "CCicle JumpFlag = ON IP= <"+ IP +
        " > opa=< "+IR.OperandA+" > team =< "+TeamFlag+" >");
        }
    // Otherwise, update IP to point at next instruction        
    else {
        IP++; 
        IP %= Core.CoreSize;
        //Core.setAB(IP);
        }                    
    /*
    IP++;
    IP %= Core.CoreSize;*/
    Core.setAB(IP);
    System.err.println("CiCle IP= <"+ IP +" >");
    //  UPDATE THE TASK STACK                       
    // Place the new IP on the appropriate stack            
    PutIP();        
    }        
    // Are the programs still going?
    public boolean IsBlueWarriorRunning() {return(ProcessCounter[BLUE]>0); }
    public boolean IsRedWarriorRunning() {return(ProcessCounter[RED]>0); }
    public int BlueWarriorsRunning()  { return ProcessCounter[BLUE]; }
    public int RedWarriorsRunning()  { return ProcessCounter[RED]; }
    public int GetCurrentTeam() {return TeamFlag; }
    public void SetCurrentTeam(int t) { TeamFlag = t; }
    }                                         

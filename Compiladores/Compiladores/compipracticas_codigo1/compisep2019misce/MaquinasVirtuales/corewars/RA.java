//  Redcode Assembler Header file
//const char* WhiteSpace = " ,\t\n";
// Manipulate Symbol Table    
//-- CObList SymbolTable --
                                                                  
// Utiltiy functions
//ArrayList<String> linesTextLine = new ArrayList<String>(Arrays.asList(data.split(String.format("%n"))));
import java.util.*;
import java.io.File;
class RA {       
    //public:
   public static final int LineLength = 256;
   //char TextLine[]= new char[LineLength];
   public static final int NumOpCodes = 12;
   public static final int NumModeSymbols = 4;
   public static final int AField = 0;
   public static final int BField = 1;
   char ModeSymbols[] = {  
    '#',
    '_',
    '@',
    '<'
    } ; 
private static HashMap<String, Integer> opMap = new HashMap<String, Integer>(){{
        put("DAT",  CProcessor.DAT);
        put("MOV",  CProcessor.MOV);
        put("ADD",  CProcessor.ADD);
        put("SUB",  CProcessor.SUB);
        put("JMP",  CProcessor.JMP);
        put("JMZ",  CProcessor.JMZ);
        put("JMN",  CProcessor.JMN);
        put("DJN",  CProcessor.DJN);
        put("CMP",  CProcessor.CMP);
        put("SPL",  CProcessor.SPL);
        put("ORG",  CProcessor.ORG);
        put("END",  CProcessor.END);
    }};
   public static String OpCodeSymbols[] = {  
    "DAT",
    "MOV",
    "ADD",
    "SUB",
    "JMP",
    "JMZ",
    "JMN",
    "DJN",
    "CMP",
    "SPL",
    "ORG",
    "END"
    } ;                       
 
   short NumOperands[] = {  
    1, // DAT
    2, // MOV
    2, // ADD
    2, // SUB
    1, // JMP
    2, // JMZ
    2, // JMN
    2, // DJN
    2, // CMP
    1, // SPL
    1, // ORG
    0  // END
    } ; 
   //char ModeSymbols[];
   ArrayList<String> lines;
   ArrayList< ArrayList<String>> commands;
    // Symbol Table    
   ArrayList<SymbolTableEntry> SymbolTable = new ArrayList<SymbolTableEntry>();
   private ArrayList<CoreWord> codeList = new ArrayList<CoreWord>();   


   private static int AddressBus;
   private static CoreWord DataBus;       
    
   public static int opEncode(String opcode){
      if(opMap.containsKey(opcode)){
         return opMap.get(opcode);
      }
      return -1;
    }
   int FitToCore(int c) { 
       return (( c + Core.CoreSize) % Core.CoreSize) ; 
   }
   public RA(){}
   // ** Assemble the program 
 //public static Player parseFile(String name, String fileName, boolean verbose)
   public void Asm(String fileName, Core Core, int LoadAddress, boolean verbose){
        String data = "";
        try{
            data = new Scanner(new File(fileName)).useDelimiter("\\Z").next();
        }
        catch(Exception e){
            System.err.println("Problem reading file " + fileName);
            return ;
        }
        ArrayList<String> lines = new ArrayList<String>(Arrays.asList(data.split(String.format("%n"))));
        ArrayList< ArrayList<String>> commands = new ArrayList<ArrayList<String>>();
        
        if(verbose) System.err.println("Original source of " + fileName);
        for(int i = 0; i < lines.size(); i++)
        {
            String line = lines.get(i);
            if(verbose) System.err.println(line);
            line = line.trim().replaceAll(","," ").replaceAll("\\s+", " ").toUpperCase();
            String[] fields = line.split(" ");
            if(fields.length == 3 || fields.length == 4)
            {
                commands.add(new ArrayList<String>(Arrays.asList(fields)));
            }
            else if(line.length() > 0)
            {
                System.err.println("Syntax error on line " + i + " in " + fileName + ": " + line);
                return ;
            }
        }
        //System.err.println("Checkpoint 2");
        for(int i = 0; i < commands.size(); i++)
        {
            ArrayList<String> command = commands.get(i);
            //System.err.println("Checkpoint 3");
            if(command.size() == 4)
            {
                String lineLabel = command.get(0).toLowerCase();
                command.remove(0);
                //System.err.println("Checkpoint 4");
                for(int j = 0; j < commands.size(); j++)
                {
                    ArrayList<String> command2 = commands.get(j);
                    String field = command2.get(command2.size()-2).toLowerCase();
                    //System.err.println("Checkpoint 5");
                    if(field.equals(lineLabel))
                    {
                        command2.set(command2.size()-2, String.valueOf(i - j));
                        //System.err.println("Checkpoint 6");
                    }
                    if(field.equals("#" + lineLabel))
                    {
                        command2.set(command2.size()-2, "#" + String.valueOf(i));
                    }
                    if(field.equals("@" + lineLabel))
                    {
                        command2.set(command2.size()-2, "@" + String.valueOf(i - j));
                    }
                    
                    
                    field = command2.get(command2.size()-1).toLowerCase();
                    //System.err.println("Checkpoint 5");
                    if(field.equals(lineLabel))
                    {
                        command2.set(command2.size()-1, String.valueOf(i - j));
                        //System.err.println("Checkpoint 6");
                    }
                    if(field.equals("#" + lineLabel))
                    {
                        command2.set(command2.size()-1, "#" + String.valueOf(i));
                    }
                    if(field.equals("@" + lineLabel))
                    {
                        command2.set(command2.size()-1, "@" + String.valueOf(i - j));
                    }
                }
            }
        }
        
        if(verbose) System.err.println("Preprocessed source of " + fileName);
        for(ArrayList<String> command : commands)
        {
            String opcode = command.get(0), fieldA = command.get(1), fieldB = command.get(2);
            if(verbose) System.err.println(opcode + " " + fieldA + " " + fieldB);

            int op = opEncode(opcode.trim().toUpperCase());
            if(op < 0)
            {
                System.err.println("Invalid opcode " + opcode + " in file " + fileName);
                return ;
            }

            int modeA = CProcessor.DIRECT;
            int valA = 0;
            fieldA = fieldA.trim();
            if(fieldA.charAt(0) == '#')
            {
                modeA = CProcessor.IMMEDIATE;
                fieldA = fieldA.substring(1);
            }
            else if(fieldA.charAt(0) == '@')
            {
                modeA = CProcessor.INDIRECT;
                fieldA = fieldA.substring(1);
            }
            try{
                valA = Integer.parseInt(fieldA);
            }
            catch(NumberFormatException e)
            {
                System.err.println("Invalid A-field " + fieldA + " in file " + fileName);
                return ;
            }
    
            int modeB = CProcessor.DIRECT;
            int valB = 0;
            fieldB = fieldB.trim();
            if(fieldB.charAt(0) == '#')
            {
                modeB = CProcessor.IMMEDIATE;
                fieldB = fieldB.substring(1);
            }
            else if(fieldB.charAt(0) == '@')
            {
                modeB = CProcessor.INDIRECT;
                fieldB = fieldB.substring(1);
            }
            try{
                valB = Integer.parseInt(fieldB);
            }
            catch(NumberFormatException e)
            {
                System.err.println("Invalid B-field " + fieldB + " in file " + fileName);
                return ;
            }
            CoreWord cmd=new CoreWord( op, modeA, modeB, valA, valB);
            
            //Instruction cmd = new Instruction(op, modeA, modeB, valA, valB);
            codeList.add(cmd);
        }

        if(verbose) System.err.println("Compiled code of " + fileName);
        for(CoreWord command : codeList)
        {
            if(verbose) System.err.println(command);
        }
        //if(verbose) System.err.println("Hash of " + name + ": " + bot.getUniqueHash());
    }

   public boolean Asm(String FName, Core Core, int LoadAddress){      
      File fileText= new File(FName);              // a text file.
      File aFile = fileText;     // An alias for this file  
      String TextLine;
      boolean bandera = false;
      //const UINT LineLength = 256;
      // Clean out the symbol table, if need be           
      while(SymbolTable.size()>0){
        //delete [] SymbolTable[0];   // clear the memory
        SymbolTable.remove(0);    // Remove the pointer
        }
    System.err.println("reading file " + FName);
    String data = "";
    try{
            data = new Scanner(new File(FName)).useDelimiter("\\Z").next();
     } catch(Exception e){
            System.err.println("Problem reading file " + FName);
            bandera = true;
        }
     lines = new ArrayList<String>(
                      Arrays.asList(data.split(String.format("%n"))));
    commands = new ArrayList<ArrayList<String>>();
    if( !bandera ){        
        if(BuildSymbolTable()==true){         
            // Seek to beginning of file
            //fileText.Seek( (LONG)0, CFile::begin);     
            //if( fileText.Open(FName, CFile::modeRead) ){            
                if(AssembleToCore(aFile, Core, LoadAddress)== true){
                    return(true);   // if everything went fine, return true
                    } 
            //}                    
          }         
        //fileText.Close();          
        } 
    return(false); // there was some errors, Dude.
   }      
   //private:                 
    // PASS 1
    boolean BuildSymbolTable(/*CStdioFile fileText*/){                    
    //public static final int LineLength = 256;
    //char CurrentLine[]= new char[LineLength]; 
    String CurrentLine;
    
    int WordNum = -1;   // Keeps track of which instruction we're doing
    int Errors = 0;     

    for(int i = 0; i < lines.size(); i++){
       CurrentLine = lines.get(i);
       if(CurrentLine.charAt(0) == ';' || CurrentLine.charAt(0) == '\n'){
          continue;
       }                                    
       // Make a copy of the input string, before any processing
       String SaveThisLine = CurrentLine;                          
       // Increment the count of words assembled  (first line == 0)
       WordNum++;                                  
       // Force to upper case
       //if(verbose) System.err.println(line);
       CurrentLine = CurrentLine.trim().replaceAll(","," ").
                          replaceAll("\\s+", " ").toUpperCase();
       String[] fields = CurrentLine.split(" ");
       
       if(fields.length == 3 || fields.length == 4 
          || fields.length == 2 || fields.length == 1){
          commands.add(new ArrayList<String>(Arrays.asList(fields)));
       } else if(CurrentLine.length() > 0){
                System.err.println("Syntax error on line " + i); 
                //+ " in " + fileName + ": " + CurrentLine);
                //========return null;
       }                  
       //CurrentLine = CurrentLine.toUpperCase();                             
        // If the first column is not blank, assume its a label
       ArrayList<String> command = commands.get(i);
       if(command.size() == 4){
          String Label = command.get(0);
          System.err.println("Label = "+Label);
          if(AddSymbolToTable(Label, WordNum) == false){        
                // Report an error      
                String ErrorMessage =  "The token, \'" + Label +"\', could not be added to the symbol table.";
                ReportError(ErrorMessage, SaveThisLine, WordNum+1);   
                Errors++;
           }                            
       }
       //if(CurrentLine.charAt(0) != ' ' && CurrentLine.charAt(0) != '\t' 
       // && CurrentLine.charAt(0) != '\n'){
    }       
    if(Errors!=0)        
        return(false);
    else
        return(true);              
   }         
    // PASS 2 
    boolean AssembleToCore(File fileText, Core Core, int LoadAddress)
    {                      
    // Holds the current line of source
    //const int LineLength = 256;
    //char CurrentLine[LineLength];
    String CurrentLine;

    int TotalWords = 0;
    int Errors = 0; 
    // Points to the current word of core -- will receive compiled instruction
    int AddressPointer = LoadAddress;          
    // We build the instruction in here                 
    CoreWord NewWord=null; 
    System.err.println("AssembleToCore ");
      for(int i = 0; i < commands.size(); i++){
         ArrayList<String> command = commands.get(i);
         //System.err.println("Checkpoint 3");
         //if(command.size() == 4){
                //=====String lineLabel = command.get(0).toLowerCase();
            //command.remove(0);
         //}
      }
      for(ArrayList<String> command : commands){
         //NewWord.ModeA = NewWord.ModeB = CProcessor.DIRECT;
         //NewWord.OperandA = NewWord.OperandB = 0;  
         String OperatorName = command.get(0);
         System.out.println("comandos i = "+1+" com = "+command);
         int op = OpNameToOpCode(OperatorName); 
         System.out.println("asm to core opcode i = "+op+" com = "+1);
         if(op == -1){            
            String OpErrMess = "\'" + OperatorName + 
            "\' is not a valid operator name.";
            System.out.println("op err = "+OpErrMess);
            //ReportError(OpErrMess, SaveThisLine, TotalWords+1);
            Errors++;
            break;
          }
          //NewWord.OpCode = (int)op;  
          NewWord =new CoreWord( op, 
                  CProcessor.DIRECT, CProcessor.DIRECT, 0, 0);           
          // Is it the END of the program?
          if(NewWord.OpCode == CProcessor.END) {
             break;
          }   
          if(UsesField(AField, op/*NewWord.OpCode*/) == true){  
             String fieldA = command.get(1);
             if(!ExtractOperandA(fieldA, TotalWords, NewWord)){      
                String AnOpErr = fieldA;
                AnOpErr += " is not a recognized label.";
                //ReportError(AnOpErr, SaveThisLine, TotalWords+1);
                Errors++;
                }
            // * If this a pseudo-op, (ORG) treat it differently
            if(NewWord.OpCode == CProcessor.ORG){
                // *set origin
                continue;
                }
          }   
          if(UsesField(BField, op /*NewWord.OpCode*/) == true){  
             String fieldB = command.get(2);
             if(!ExtractOperandB(fieldB, TotalWords, NewWord)){    
                String AnOpErr = fieldB ;
                AnOpErr += " is not a recognized label.";
                //ReportError(AnOpErr, SaveThisLine, TotalWords+1);     
                Errors++;
                }
          }
          System.err.println("ensan <"+ NewWord +" >");
          TotalWords++;                                            
          Core.WriteWord(AddressPointer++, NewWord);   
      }   
         
      if(Errors!=0)
         return false;
      else {      
        return true;                
      }
   }                                                       
   boolean AddSymbolToTable(String s, int address){     
      // make sure it's not already there
      if(GetSymbol(s) == -1){                              
        // Add the new symbol
        SymbolTable.add( new SymbolTableEntry(s, address));
        return true;
      }
      else
        return false;        
   }
   int GetSymbol(String s){    
      for(int SymNum=0; SymNum < SymbolTable.size(); SymNum++){        
        SymbolTableEntry Entry = (SymbolTableEntry)SymbolTable.get(SymNum);
        if(s == Entry.SymbolName)
            return(Entry.Address);
      }            
    // Couldn't find it.  Sorry, Bud.        
      return(-1);        
   }  
   boolean ExtractOperandA(String Token, int CurrentAddress, CoreWord Word)
    {        
    int Value;
    // Check first for an explicit addressing mode  
    for(int m=0; m<NumModeSymbols; m++)  
        {
        System.out.println("modeA m= "+m+" tok0 ="+Token.charAt(0)+
        ""+ModeSymbols[m]);   
        if(ModeSymbols[m]==Token.charAt(0)){
            System.out.println("IFFFmodeA m= "+m+" tok0 ="+Token.charAt(0)+
        ""+ModeSymbols[m]); 
            // set the addr mode
            Word.ModeA = (short)m;   
            // clip off the mode character
            //===Token++;
            Token=Token.substring(1);
            }
        }                                                     
    // If it's a number, convert it 
    System.out.println("NNNNNumber token= "+Token);   
    if(Token.charAt(0)=='-' ||  "-+0123456789".indexOf(Token)!= -1){
        System.out.println("IFFFF number token= "+Token);
        Value = Integer.parseInt(Token);
        System.out.println("IFFFF number value= "+Value);
        
    }
    // Otherwise, its a label.  Go get its value
    else
        {                 
        String Symbol = Token;
        Value = GetSymbol(Symbol);
        if(Value == -1)
            {
            return(false);
            }    
        Value -= CurrentAddress;   
        }        
    if(Value > 0 ) Word.OperandA = FitToCore(Value);
    else Word.OperandA = Value;
    return true;
    }     
    boolean ExtractOperandB(String Token, int CurrentAddress, CoreWord Word)
    {        
    int Value;
    // Check first for an explicit addressing mode 
     for(int m=0; m<NumModeSymbols; m++)  
        {
        System.out.println("modeB m= "+m+" tok0 ="+Token.charAt(0)+
        ""+ModeSymbols[m]);   
        if(ModeSymbols[m]==Token.charAt(0)){
            System.out.println("IFFFmodeB m= "+m+" tok0 ="+Token.charAt(0)+
        ""+ModeSymbols[m]); 
            // set the addr mode
            Word.ModeB = (short)m;   
            // clip off the mode character
            //===Token++;
            Token=Token.substring(1);
            }
        }                                                                                               
    // If it's a number, convert it    
    if("-+0123456789".indexOf(Token)!= -1)
        Value = Integer.parseInt(Token);
        
    // Otherwise, its a label.  Go get its value
    else
        {                 
        String Symbol = Token;
        Value = GetSymbol(Symbol);
        if(Value == -1)
            {
            return(false);
            }    
            
        Value -= CurrentAddress;   
        }        

    Word.OperandB = FitToCore(Value);
    return true;
    }
    // Utiltiy functions
   int OpNameToOpCode(String OperatorName){         
      for(int OC=0; OC < NumOpCodes; OC++){    
         // If this name is a match, coolness
         //System.out.println("OC  = "+OC+" sym = "+OpCodeSymbols[OC]
         //+"name = "+OperatorName); 
         if (OperatorName.equals(OpCodeSymbols[OC])){
            return(OC);
         }
      }
      return -1;
    }
   boolean UsesField(int AorB, int OpCode){                
   //ASSERT(OpCode >=0 && OpCode <NumOpCodes);
   // Do the easy ones up front
      System.out.println("uses opcode i = "+OpCode+" numope = "+NumOperands[OpCode]);
      if(NumOperands[OpCode] == 2) // always
         return true;
      if(NumOperands[OpCode] == 0) // never
         return false;        
      // If we get here, this Op takes ONE operand
      if(OpCode == CProcessor.JMP){
         if(AorB == AField) { // only JMP uses the A field
            return true;
         } else
            return false;           
      } else if (AorB == BField) return true;    
      return false;        
   }
 void ReportError(String ErrorMessage, String SourceLine, int LineNumber){    
    /*CAsmErrDlg ErrorDialog;   
    
    ErrorDialog.m_LineNumber = LineNumber;
    ErrorDialog.m_SourceLine = SourceLine;
    ErrorDialog.m_AsmError = ErrorMessage;
    ErrorDialog.DoModal();*/
    }
   public static void main(String s[]){
      RA ra=new RA();
      Core core = new Core(AddressBus, DataBus, Core.CoreSize);
      ra.Asm("ZOTACO.RED", core, 0);
   }
   class SymbolTableEntry  {
      public SymbolTableEntry(){}
      public SymbolTableEntry(String s, int address) { 
        SymbolName = s; Address = address; };
      public String SymbolName;
      public int Address;
   } 
}

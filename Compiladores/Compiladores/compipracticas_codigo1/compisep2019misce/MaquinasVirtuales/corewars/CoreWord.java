class CoreWord {   
    //public short OpCode : 4; //OpCodes OpCode;
    //public short ModeA  : 2; // AddressingMode ModeA;
    //public short ModeB  : 2; //AddressingMode ModeB;
    public int OpCode; //OpCodes OpCode;
    public short ModeA; // AddressingMode ModeA;
    public short ModeB; //AddressingMode ModeB;
    public int OperandA;      
    public int OperandB;  
   

    private static final String[] opNames = {"DAT", "MOV", "ADD", "SUB", "JMP", "JMZ", "JMN" , "DJN", "CMP", "SPL", "ORG", "END"};
    private static final String[] modeNames = {"\t#", "\t ", "\t@", "<"};
 
   public static final int modeBits = 2;
   public static final int modeMask = (1 << modeBits)-1;
   public static final CoreWord DAT00 = new CoreWord(0, 0, 0);
   public CoreWord(CoreWord otro){
      this.ModeA = otro.ModeA; 
      this.ModeB = otro.ModeB;
      this.OpCode = otro.OpCode;
      this.OperandA = otro.OperandA;
      this.OperandB = otro.OperandB;
   }
   public CoreWord(int opcode, int field1, int field2){
        this.OpCode = opcode;
        this.OperandA = OperandA;
        this.OperandB = OperandB;
   }
   public CoreWord(int opcode, int ModeA, int ModeB, 
                   int OperandA, int OperandB) {
        ModeA &= modeMask;
        ModeB &= modeMask;
        this.OpCode = (opcode << (2*modeBits)) + (ModeA << modeBits) + ModeB;
        this.OperandA = OperandA;
        this.OperandB = OperandB;
    } 
   public boolean equals(CoreWord otro){
      return ModeA == otro.ModeA && ModeB == otro.ModeB && 
      this.OpCode == otro.OpCode && this.OperandA == otro.OperandA &&
             this.OperandB == otro.OperandB;
   } 
   public String toString(){
        return RA.OpCodeSymbols[OpCode >> (2*modeBits)] + modeNames[ModeA] + 
        OperandA + modeNames[ModeB] + OperandB;
    }
} 

import java.awt.*;
class Core {
   public static final int CoreSize = 4000;
   private int AddressBus;   //ap word
   private CoreWord DataBus;  //ap 
   private CoreWord CoreMemory[];       
   private int AddressHits[];
   private short HitPtr;
   CProcessor cp;
   public static final int RED = 0, BLUE= 1; 
   public void printCore(Graphics g, int yi, int Addr1, int Addr2, int size){
      int y=0;
      for(int i=0; i < size; i++){
         y = yi / size;
        //if(yi % size == 0){
         g.setColor(Color.black);
         if(cp.GetCurrentTeam()==BLUE)
           g.drawString(" i = "+i+
            //" Blue "+(Addr1+i)+" V = "+CoreMemory[Addr1+i]+
            " Blue "+((y*size+i)%4000)+" V = "+CoreMemory[(y*size+i)%4000], 400, 30*(i+2)); 
         else
           g.drawString(" i = "+i+
            //" Blue "+(Addr1+i)+" V = "+CoreMemory[Addr1+i]+
            " Red "+((y*size+i)%4000)+" V = "+CoreMemory[(y*size+i)%4000], 800, 30*(i+2)); 
        //}
      }      
   }
   public void printCore(int Addr1, int Addr2, int size){
      for(int i=0; i < size; i++)
         System.out.println(" i = "+i+
            " Blue "+(Addr1+i)+" V = "+CoreMemory[Addr1+i]+
            " Red "+(Addr2+i)+" V = "+CoreMemory[Addr2+i]);       
   }
   public void printCore( ){
      for(int i=0; i < 24; i++)
         System.out.println("   i = "+i+" mem = "+CoreMemory[i]);       
   }
   public void setDB(CoreWord DataBus ){
        this.DataBus = DataBus;
    }
   public void setAB(int ab ){
        this.AddressBus = ab;
    }
   public void setCP(CProcessor cp ){
        this.cp = cp;
    }
   public CProcessor getCP(){
        return cp;
    }
   public int getAB(){
        return AddressBus;
    }
   public Core(int A_Bus, CoreWord D_Bus, int CoreSize){          
    // Set the pointers to the MARS bus
      System.err.println("Core creado");
      DataBus = D_Bus;
      AddressBus = A_Bus;            
    // No memory hits, yet                
      HitPtr = -1;
      CoreMemory = new CoreWord[CoreSize]; 
      AddressHits = new int[100];  
      InitializeCore();
    }
   public void ReadWord(){               
    //ASSERT(*AddressBus <  CoreSize);
    // Copy the word from Core memory onto the data bus  
        System.err.println("11ReadWord core AddressBus =<"+AddressBus+
                           " >");  
        DataBus=new CoreWord(CoreMemory[AddressBus]);
        System.err.println("22ReadWord core DataBus "+DataBus+
                           "ReadWord CoreMemory "+CoreMemory[AddressBus]);
        cp.DataBus=DataBus;
        AddAHit(AddressBus);
    }         
// Write a word to memory            
   public void WriteWord(){
    //ASSERT(*AddressBus <  CoreSize);     
    //Copy the contents of the data bus into the word specified by the addr bus
    CoreMemory[AddressBus]= new CoreWord(DataBus);
    System.err.println("1core write <"+ CoreMemory[AddressBus] +
                       " > AddressBus= "+AddressBus);
    AddAHit(AddressBus);
   }       
   public void WriteWord(int Address, CoreWord NewWord){
    //ASSERT(Address <  CoreSize);        
    // Copy the contents of the data bus into the word specified by the addr bus
    System.err.println("22core write <"+ NewWord +" > addr= "+Address);
    CoreMemory[Address]=new CoreWord(NewWord);
    AddAHit(Address);
   }       
   public void WriteOperandA(){
    //ASSERT(*AddressBus <  CoreSize);    
    CoreMemory[AddressBus].OperandA = DataBus.OperandA;
    System.err.println("WriteOperandA core DataBus "+DataBus+
       "WriteOperandA CoreMemory "+CoreMemory[AddressBus]);
    AddAHit(AddressBus);
   }    
   public void WriteOperandB(){
    //ASSERT(*AddressBus <  CoreSize);    
    CoreMemory[AddressBus].OperandB = DataBus.OperandB;
    System.err.println("WriteOperandB core DataBus "+DataBus+
       "WriteOperandB CoreMemory "+CoreMemory[AddressBus]);
    AddAHit(AddressBus);
   }                       
   public void InitializeCore(){
      for(int index = 0; index< CoreMemory.length; index++) {
	  CoreMemory[index] = CoreWord.DAT00;;
      }
   }    
   public void InitializeCore(CoreWord Src){
      for(int index = 0; index< CoreMemory.length; index++) {
	  CoreMemory[index] = new CoreWord(Src);
      }
   }
   public void AddAHit(int a) { 
         if(HitPtr<99) {
            System.err.println("AddAHit HitPtr <"+ HitPtr +" > a= "+a);
            AddressHits[++HitPtr] = a; 
            
         }
   }
   public int GetAHit() { 
        System.err.println("GetHit HitPtr <"+ HitPtr);
        if(HitPtr >= 0) {
            
            return AddressHits[HitPtr--]; 
        }
        else 
            return(-1);
   }    
}

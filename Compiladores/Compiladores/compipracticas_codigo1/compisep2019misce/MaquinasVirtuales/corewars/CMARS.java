import java.awt.*;
class CMARS  {   
   // Central Processing Unit
    private CProcessor MPU;          
    // Main memory
    private Core Core;//ap
    // Address and Data buses
    private int AddressBus;
    private CoreWord DataBus;       
    // Flags
    private boolean BlueWarriorDead;
    private boolean RedWarriorDead; 
    // Flags
    private boolean Running;       // TRUE if we're running a battle  
    public CMARS(){   
       Running = false;     
       BlueWarriorDead = RedWarriorDead = false;
       Core = new Core(AddressBus, DataBus, Core.CoreSize);
       MPU = new CProcessor(Core);//core arg
       Core.setCP(MPU);
       DataBus = new CoreWord(0, 0, 0);
    }  
    //~CMARS(void);                        
   public void SetUp(/*Rectangle ViewRect*/){
      // Clear out core
      CoreWord Blank=new CoreWord(CProcessor.DAT,
            CProcessor.DIRECT, CProcessor.DIRECT, 0, 0);
      //Blank.OpCode = CProcessor.DAT;
      //Blank.OperandA = Blank.OperandB = 0;
      //Blank.ModeA = Blank.ModeB = CProcessor.DIRECT;
      Core.InitializeCore(Blank);
      RedWarriorDead  = false;
      BlueWarriorDead = false;
   }         
   public void Reset(int Addr1, int Addr2){                       
      // No one's dead yet                     
      RedWarriorDead  = false;
      BlueWarriorDead = false;
      // Reset the CPU
      MPU.Reset(AddressBus, DataBus, Addr1, Addr2, Core);        
   }  
   public void Reset(){    
      // Shut 'er down
      Running = false;                 
      CoreWord Blank;
      //Blank.OpCode = CProcessor.DAT;
      //Blank.OperandA = Blank.OperandB = 0;
      //Blank.ModeA = Blank.ModeB = CProcessor.DIRECT;
      Blank=new CoreWord(CProcessor.DAT,
                        CProcessor.DIRECT, CProcessor.DIRECT, 0, 0);
      // Blank out core 
      Core.InitializeCore(Blank);
      // Reset the MPU - no load addresses yet -- pass zeros
      MPU.Reset(AddressBus, DataBus, 0, 0, Core);                        
      // No one's dead yet                   
      RedWarriorDead  = false;
      BlueWarriorDead = false;
   }                 
   public void Cycle(/*Graphics g*/){        
    if(Running){
        System.out.println("CMARS cycle");
        MPU.Cycle(/*g*/);
           
        if(!MPU.IsRedWarriorRunning())
            {
            RedWarriorDead = true;
            Running = false;
            }
        
        if(!MPU.IsBlueWarriorRunning())        
            {
            BlueWarriorDead = true;
            Running = false;
            }
      }           
    }    
    public void Run()  { Running = true; }
    public void Stop() { Running = false; }

    public Core GetCore()  { return Core; }
    
    // Are the programs still going?
    public boolean IsBlueWarriorDead() {return BlueWarriorDead;}
    public boolean IsRedWarriorDead() {return RedWarriorDead;}
    
    public int BlueWarriorsRunning() {return MPU.BlueWarriorsRunning(); }
    public int RedWarriorsRunning() {return MPU.RedWarriorsRunning(); }             
    
    public int GetCurrentTeam() {return MPU.GetCurrentTeam(); }
    public void SetCurrentTeam(int t) { MPU.SetCurrentTeam(t); }
                 
} 
    
    

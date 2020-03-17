
class PruebaCore {
   public CMARS MARS;   
   public RA Assembler;

   public boolean RedWarriorLoaded;
   public boolean BlueWarriorLoaded;
    
   public int RedWarriorLoadAddress;
   public int BlueWarriorLoadAddress;
   public static final int RED = 0, BLUE= 1; 
   public PruebaCore(){
      MARS = new CMARS();  
      MARS.SetUp(/*rect*/);
      Assembler = new RA();
      BlueWarriorLoadAddress = 0; 
      //(Core.CoreSize/4)*3 +
      //                          (int)(Math.random()%(Core.CoreSize/4));
      RedWarriorLoadAddress  = (Core.CoreSize/4)*3 +
                                (int)(Math.random()*(Core.CoreSize/4));
      MARS.SetCurrentTeam(BLUE);    
      Assembler.Asm("IMP1.RED", MARS.GetCore(), RedWarriorLoadAddress);  
      Assembler.Asm("IMP1.RED", MARS.GetCore(), BlueWarriorLoadAddress);
      MARS.Reset(BlueWarriorLoadAddress, RedWarriorLoadAddress);
      MARS.Run();
      for(int i=0; i < 50 ; i++)
          MARS.Cycle();
      MARS.GetCore().printCore(
           BlueWarriorLoadAddress, RedWarriorLoadAddress, 30);
      /*System.out.println("Otro ciclo");
      MARS.Cycle();
      MARS.Cycle();
      MARS.Cycle();
      MARS.Cycle();
      MARS.Cycle();
      MARS.Cycle();
      MARS.Cycle();
      MARS.Cycle();
      MARS.Cycle();
      MARS.Cycle();
      MARS.Cycle();
      MARS.Cycle();
      MARS.Cycle();
      MARS.Cycle();
      MARS.Cycle();
      MARS.Cycle();
      MARS.Cycle();
      MARS.Cycle();
      MARS.Cycle();
      MARS.Cycle();
      MARS.Cycle();
      MARS.Cycle();
      MARS.Cycle();
      MARS.Cycle();*/
   }
   public static void main(String s[]){
      PruebaCore ra=new PruebaCore();
   }
}

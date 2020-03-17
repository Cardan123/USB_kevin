class CAddressBus {             
    private CoreWord BusContents;  
    public void SetBus(CoreWord Data){
        BusContents = Data;
    }      
    public CoreWord GetBus(){
        return ( BusContents );
    }
}


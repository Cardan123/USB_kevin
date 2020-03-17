class CDataBus {      
    private CoreWord BusContents;                    
    public void SetBus(CoreWord Data){
        BusContents = Data;
    }
    public CoreWord GetBus(){
        CoreWord BusAlias = BusContents;
        return(BusAlias);
    }
}
    
    

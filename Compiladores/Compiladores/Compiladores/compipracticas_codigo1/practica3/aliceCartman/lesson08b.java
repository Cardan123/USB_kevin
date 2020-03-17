import java.awt.Frame;
import java.applet.Applet;
import java.awt.*;
import java.awt.event.*;
import com.sun.j3d.utils.applet.MainFrame;
import com.sun.j3d.utils.geometry.*;
import com.sun.j3d.utils.universe.*;
import javax.media.j3d.*;
import javax.vecmath.*;
import com.sun.j3d.loaders.*;
import com.glyphein.j3d.loaders.milkshape.MS3DLoader;

public class lesson08b extends Applet { 
    	SimpleUniverse simpleU; 
    	static boolean application = false;
	
	public lesson08b (){    
	}    

	public void init() { 
      
	setLayout(new BorderLayout()); 
	Canvas3D c = new Canvas3D(SimpleUniverse.getPreferredConfiguration()); 
    	add("Center", c);    
	simpleU= new SimpleUniverse(c); // setup the SimpleUniverse, attach the Canvas3D
    	BranchGroup scene = createSceneGraph(); 
        simpleU.getViewingPlatform().setNominalViewingTransform();
        
        scene.compile(); 
        simpleU.addBranchGraph(scene); //add your SceneGraph to the SimpleUniverse   
    }

    public BranchGroup createSceneGraph() {      

   	BranchGroup objRoot = new BranchGroup(); 

	
      	try
	{	
		Scene s = null;
   		Loader loader = new MS3DLoader (MS3DLoader.LOAD_ALL);	// .ms3d Loader


		if (application == false){
			java.net.URL url = new java.net.URL (getCodeBase(), "coke.ms3d");
			 s = loader.load (url);
			objRoot.addChild (s.getSceneGroup ());
	
		}
		else {
			java.io.File file = new java.io.File("/home/rtecla/alice_agent/alice_cart/Models/Cartman2.ms3d");
			if (file.getParent().length() > 0) {// figure out the base path
                                System.out.println(file.getParent() + java.io.File.separator);
  				loader.setBasePath(file.getParent() + java.io.File.separator);
			}
			s = loader.load(file.getName());
			objRoot.addChild (s.getSceneGroup ());
			 AmbientLight ambientlight = new AmbientLight(new Color3f(0.9F, 0.9F, 0.9F));
        DirectionalLight directionallight = new DirectionalLight(true, new Color3f(0.5F, 0.5F, 0.5F), new Vector3f(0.0F, -1F, 0.0F));
        ambientlight.setInfluencingBounds(bounds);
        directionallight.setInfluencingBounds(bounds);
        objRoot.addChild(ambientlight);
        objRoot.addChild(directionallight);
		}

	}

      	catch (java.net.MalformedURLException ex){	
      	}
      	catch (java.io.FileNotFoundException ex){
      	}



      	return objRoot;
      	}

      	public void destroy() {	
		simpleU.removeAllLocales();    
      	}  

      	public static void main(String[] args) {
		application = true;    
        	Frame frame = new MainFrame(new lesson08b(), 500, 500);    
      	}
    public static final BoundingSphere bounds;
    private static Point3d center;
        static 
    {
        center = new Point3d(7.5D, 0.0D, -7.5D);
        bounds = new BoundingSphere(center, 1.7976931348623157E+308D);
    }
}

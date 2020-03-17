import com.sun.j3d.utils.geometry.GeometryInfo;
import com.sun.j3d.utils.image.TextureLoader;

import javax.media.j3d.*;
import javax.vecmath.Color3f;
import javax.vecmath.Point2f;
import javax.vecmath.Point3f;
import java.net.URL;
import java.awt.image.*;
/**
 * A re-usable Java3D {@link com.sun.j3d.utils.geometry.Primitive} shape resembling a picture frame.
 * <p/>
 * {@link Picture} is a {@link com.sun.j3d.utils.geometry.Primitive}, that creates a {@link Shape3D} (using {@link GeometryInfo}) representing a picture and picture frame.
 *
 * @author Cormac Redmond -- credmond85 /at/ gmail
 */
public class Picture extends Group {

    // Default Material node for Picture
    private final static Material pictureMaterial = (new Material(
            new Color3f(ColourConstants.red),
            new Color3f(ColourConstants.red),
            new Color3f(ColourConstants.red),
            new Color3f(ColourConstants.red),
            1f));

    private String imageURL = "default.jpg";

    // Create Appearance for Picture
    private Appearance pictureAppearance;
    ImageComponent2D image;
    TextureLoader loader;

    public BufferedImage getImage() {
        return image.getImage() ;
    }
    public void createSceneGraph() {
        // Load the picture        
        // Get current classloader ... loading resources this way is neccessary when the application is JAR'd
        ClassLoader cl = this.getClass().getClassLoader();
        URL url = cl.getResource(imageURL);

        loader = new TextureLoader(url, null);
        image = loader.getImage();

        // Check for file error
        if (image == null) {
            System.out.println("Failed to load the file: " + imageURL);
        }
        auxiliar(); 
    }
    public void createSceneGraph(BufferedImage bImage) {
       loader = new TextureLoader(bImage); 
       auxiliar();   
    }
    public void auxiliar() {
        // Create an array of coordinates
        Point3f coords[] = new Point3f[8];
        Point2f textCoords[] = new Point2f[4];

        coords[0] = new Point3f(-.55f, .64f, 0.0f);
        coords[1] = new Point3f(-.55f, -.64f, 0.0f);
        coords[2] = new Point3f(.55f, -.64f, 0.0f);
        coords[3] = new Point3f(.55f, .64f, 0.0f);

        // These coordinates represent the back of the frame
        coords[4] = new Point3f(-.60f, .69f, -0.01f);
        coords[5] = new Point3f(-.60f, -.69f, -0.01f);
        coords[6] = new Point3f(.60f, -.69f, -0.01f);
        coords[7] = new Point3f(.60f, .69f, -0.01f);

        //  Create an array of texture coordinates (default)
        textCoords[0] = new Point2f(0.0f, 1.0f);
        textCoords[1] = new Point2f(0.0f, 0.0f);
        textCoords[2] = new Point2f(1.0f, 0.0f);
        textCoords[3] = new Point2f(1.0f, 1.0f);
         
        TextureAttributes textureAttrib = new TextureAttributes();

        // Use 'NICEST' for highest quality rendering
        textureAttrib.setPerspectiveCorrectionMode(TextureAttributes.NICEST);

        //Texture2D texture = new Texture2D(Texture.BASE_LEVEL, Texture.RGBA, 1, 1);
        Texture texture=loader.getTexture();
        //texture.setImage(0, image);

        // Set the texture
        pictureAppearance.setTexture(texture);

        // Setup a PolygonAttributes
        PolygonAttributes pictureMaterialPA = new PolygonAttributes();

        // Render all sides of the shape
        pictureMaterialPA.setCullFace(PolygonAttributes.CULL_NONE);

        // Create normals for the back of shape also, so light can reflect there too, etc
        pictureMaterialPA.setBackFaceNormalFlip(true);

        // Add Material, TextureAttributes and PolygonAttributes to the Appearance
        pictureAppearance.setTextureAttributes(textureAttrib);
        this.pictureAppearance.setMaterial(pictureMaterial);
        pictureAppearance.setPolygonAttributes(pictureMaterialPA);

        // Create a QUAD_ARRAY GeometryInfo
        GeometryInfo gi = new GeometryInfo(GeometryInfo.QUAD_ARRAY);

        // Tell it the coordinates of the QUADs
        gi.setCoordinates(coords);

        // Tell it the texture coordinates of the QUADs
        gi.setTextureCoordinates(textCoords);

        // Finally create a Shape3D by handing it the geometry and an Appearance node
        Shape3D picture = new Shape3D(gi.getGeometryArray(), pictureAppearance);

        // Add the Shape3D Picture
        TransformGroup pictureTG = new TransformGroup();
        pictureTG.addChild(picture);
        this.addChild(pictureTG);
    }
    /**
     * A constructor accepting the URL to an file
     *
     * @param imageURL a string containing full or relative path to the desired picture image
     */
    public Picture(String imageURL) {
        // set default appearances with default materials

        this.imageURL = imageURL;
        this.pictureAppearance = new Appearance();
        this.pictureAppearance.setMaterial(pictureMaterial);

        this.createSceneGraph();
    }
}
   


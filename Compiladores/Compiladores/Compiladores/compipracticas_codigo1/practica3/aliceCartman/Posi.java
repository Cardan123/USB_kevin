import javax.media.j3d.*;
import javax.vecmath.*;
public class Posi {
public static TransformGroup translate(Node node, Vector3f vector) {
	Transform3D transform3D = new Transform3D();
	transform3D.setTranslation(vector);
	TransformGroup transformGroup =new TransformGroup(transform3D);
        transformGroup.addChild(node);
	return transformGroup; 
} 
public static TransformGroup escatrans(Node node, Vector3f vector, Vector3d escala) {
	Transform3D transform3D = new Transform3D();
	transform3D.setTranslation(vector);
        transform3D.setScale(escala);
	TransformGroup transformGroup =new TransformGroup();
	transformGroup.setTransform(transform3D); 
        transformGroup.addChild(node);
	return transformGroup;
} 
}

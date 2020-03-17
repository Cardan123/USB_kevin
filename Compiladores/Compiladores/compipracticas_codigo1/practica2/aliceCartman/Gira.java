import javax.media.j3d.*;
import javax.vecmath.*;
public class Gira {
     	public static TransformGroup rotate(Node node, Alpha alpha) {
	TransformGroup xformGroup = new TransformGroup();
	xformGroup.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);
RotationInterpolator interpolator =new RotationInterpolator(alpha, xformGroup);
interpolator.setSchedulingBounds(new BoundingSphere(new Point3d(0.0, 0.0, 0.0), 1.0));
	xformGroup.addChild(interpolator); xformGroup.addChild(node);
	return xformGroup; }
}
